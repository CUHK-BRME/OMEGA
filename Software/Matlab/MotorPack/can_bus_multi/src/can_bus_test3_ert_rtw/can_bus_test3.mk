###########################################################################
## Makefile generated for Simulink model 'can_bus_test3'. 
## 
## Makefile     : can_bus_test3.mk
## Generated on : Mon Apr 19 17:24:43 2021
## MATLAB Coder version: 4.1 (R2018b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/can_bus_test3.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = can_bus_test3
MAKEFILE                  = can_bus_test3.mk
COMPUTER                  = GLNX
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2018b
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2018b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = $(MATLAB_WORKSPACE)/C/Users/Ng_Wee_Shen/Desktop/Test_ray/can_bus_multi/src
ARCH                      = glnx
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU GCC Raspberry Pi v1.0 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2018b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG = --output_file=
LDOUTPUTFLAG = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm -lstdc++

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU GCC Raspberry Pi Assembler
AS = as

# C Compiler: GNU GCC Raspberry Pi C Compiler
CC = gcc

# Linker: GNU GCC Raspberry Pi Linker
LD = gcc

# C++ Compiler: GNU GCC Raspberry Pi C++ Compiler
CPP = g++

# C++ Linker: GNU GCC Raspberry Pi C++ Linker
CPP_LD = g++

# Archiver: GNU GCC Raspberry Pi Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =

#--------------------
# File extensions
#--------------------

OBJ_EXT             = .s.o
ASM_EXT             = .s
C_DEP               = .c.dep
H_EXT               = .h
COBJ_EXT            = .c.o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
CXX_DEP             = .cpp.dep
HPP_EXT             = .hpp
CPPOBJ_EXT          = .cpp.o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS =  -c $(ASFLAGS_ADDITIONAL) $(INCLUDES)

CFLAGS =  -c -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" -O0

LDFLAGS = -lrt -lpthread -ldl

SHAREDLIB_LDFLAGS = -shared -lrt -lpthread -ldl

CPPFLAGS =  -c -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" -O2

CPP_LDFLAGS = -lrt -lpthread -ldl

CPP_SHAREDLIB_LDFLAGS = -shared -lrt -lpthread -ldl

ARFLAGS = -r

DOWNLOAD_FLAGS = 

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/can_bus_test3.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/can_bus_test3_ert_rtw -I$(MATLAB_WORKSPACE)/C/Users/Ng_Wee_Shen/Documents/MATLAB/can_bus_test3 -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include/src -I$(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include -I$(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/comm_rt -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/realtime/targets/raspi/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/realtime/targets/raspi/server -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=can_bus_test3 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=1 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0 -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=1
DEFINES_SKIPFORSIL = -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=can_bus_test3 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/can_bus_test3_ert_rtw/can_bus_test3.cpp $(START_DIR)/can_bus_test3_ert_rtw/can_bus_test3_data.cpp $(START_DIR)/can_bus_test3_ert_rtw/rtGetInf.cpp $(START_DIR)/can_bus_test3_ert_rtw/rtGetNaN.cpp $(START_DIR)/can_bus_test3_ert_rtw/rt_nonfinite.cpp $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c $(START_DIR)/CAN_BUS_MULTISTATE_SF_wrapper.cpp $(START_DIR)/LINMOT_CAN_TEST_wrapper.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/realtime/targets/raspi/server/MW_raspi_init.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/rtiostream_tcpip.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.cpp

MAIN_SRC = $(START_DIR)/can_bus_test3_ert_rtw/ert_main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = can_bus_test3.cpp.o can_bus_test3_data.cpp.o rtGetInf.cpp.o rtGetNaN.cpp.o rt_nonfinite.cpp.o ext_svr.c.o updown.c.o ext_work.c.o rtiostream_utils.c.o CAN_BUS_MULTISTATE_SF_wrapper.cpp.o LINMOT_CAN_TEST_wrapper.cpp.o MW_raspi_init.c.o rtiostream_interface.c.o rtiostream_tcpip.c.o linuxinitialize.cpp.o

MAIN_OBJ = ert_main.cpp.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL =   -fpermissive
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL =  

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL =  

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL =   -fpermissive
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL =  

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL =  

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	echo "### Successfully generated all binary outputs."


prebuild : 


download : build


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/comm_rt/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/comm_rt/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/toolbox/comm/extern/comm_rt/export/include/comm_rt/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/can_bus_test3_ert_rtw/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/can_bus_test3_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(START_DIR)/can_bus_test3_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


MW_raspi_init.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/realtime/targets/raspi/server/MW_raspi_init.c
	$(CC) $(CFLAGS) -o $@ $<


rtiostream_tcpip.c.o : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) $(CFLAGS) -o $@ $<


linuxinitialize.cpp.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


