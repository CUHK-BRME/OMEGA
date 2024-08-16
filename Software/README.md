# Software Instruction

1. Environment Setup
  -Matlab 2018b
     AddOns:
       -DSP System Toolbox
       -Embedded Coder
       -Instrument Control Toolbox
       -Matlab compiler
       -MATLAB Coder
       -Simulink Coder
       -Signal Processing Toolbox
       -Simscape
       -Simscape Electrical
     AddOns needed after installing Matlab (need non institute network):
       -Simulink Support Package for Raspberry Pi Hardware
       -MATLAB Support for MinGW-w64 C/C++/Fortran Compiler (for compile s-function builder)
     Set Path for Custom Files:
       -can_bus_multi
     Simulink Model Configuration Parameters:
       -Hardware Implementation -> Hardware Board: Raspberry Pi
       -Hardware Board Setting -> Target hardware resources -> Board Parameters: input connected Raspberry Pi IP address and its login details
       -Hardware Board Setting -> Target hardware resources -> External mode: check the "Run external mode in a background thread"
   
       
