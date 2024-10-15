
# Software Instruction

### 1. Environment Setup

- **Matlab Version**: 2018b (set to always run as administrator)  

  **Required Add-ons**:
  - DSP System Toolbox
  - Embedded Coder
  - Instrument Control Toolbox
  - MATLAB Compiler
  - MATLAB Coder
  - Simulink Coder
  - Signal Processing Toolbox
  - Simscape
  - Simscape Electrical
  - Robotics System Toolbox
  - Aerospace Toolbox

- **Add-ons Needed After Matlab Installation** (require a non-institute network):
  - Simulink Support Package for Raspberry Pi Hardware
  - MATLAB Support for MinGW-w64 C/C++/Fortran Compiler (needed for compiling S-function builder)

- **Custom File Path Setup**:
  - Add `can_bus_multi` to the Matlab path.

- **Simulink Model Configuration Parameters**:
  - **Hardware Implementation**:
    - Set **Hardware Board** to **Raspberry Pi**.
  - **Hardware Board Settings**:
    - **Target Hardware Resources**:
      - Under **Board Parameters**, input the Raspberry Pi IP address and login credentials.
    - **External Mode**:
      - Enable **Run external mode in a background thread**.
