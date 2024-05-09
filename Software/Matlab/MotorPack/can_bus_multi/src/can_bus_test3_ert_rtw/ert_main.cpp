//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'can_bus_test3'.
//
// Model version                  : 1.3643
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Apr 19 17:28:36 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "can_bus_test3.h"
#include "can_bus_test3_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "MW_raspi_init.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(can_bus_test3_M) == (NULL)) &&
    !rtmGetStopRequested(can_bus_test3_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(can_bus_test3_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(can_bus_test3_M, true);
      }

      if (rtmGetStopRequested(can_bus_test3_M) == true) {
        rtmSetErrorStatus(can_bus_test3_M, "Simulation finished");
        break;
      }
    }

    can_bus_test3_step();

    // Get model outputs here
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(can_bus_test3_M) == (NULL)) &&
                      !rtmGetStopRequested(can_bus_test3_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(can_bus_test3_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread,(void *)&threadJoinStatus), 0,
                 "pthread_join");
  }

  mwRaspiTerminate();

  // Disable rt_OneStep() here

  // Terminate model
  can_bus_test3_terminate();
  rtExtModeShutdown(1);
  sem_post(&stopSem);
  return NULL;
}

void backgroundTask(void *arg)
{
  while (runModel) {
    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(can_bus_test3_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(can_bus_test3_M, true);
      }
    }
  }
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  mwRaspiInit();
  rtmSetErrorStatus(can_bus_test3_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  // Initialize model
  can_bus_test3_initialize();

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(can_bus_test3_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(can_bus_test3_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(can_bus_test3_M, true);
    }
  }

  rtERTExtModeStartMsg();

  // Call RTOS Initialization function
  myRTOSInit(0.001, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
