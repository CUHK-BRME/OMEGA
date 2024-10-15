# OMEGA: Open-Source Multi-Mode Hopping Platform

**OMEGA** is a versatile, open-source hopping robot platform designed for research and educational purposes. It features a middle-sized robot equipped with an omnidirectional 3-RSR parallel leg, enabling seamless transitions between 1D, 2D, and 3D hopping modes. The platform is built using accessible manufacturing technologies, supporting both tethered and untethered experiments.

## Features:
- **Multi-mode hopping**: 1D, 2D, and 3D modes
- **Omnidirectional 3-RSR parallel leg**
- **Accessible manufacturing**: 3D printing, water-jet cutting
- **Simulator**: For control learning and experiments

## Video Demonstration:
Watch the OMEGA platform in action [here](https://github.com/user-attachments/assets/fb11da87-3373-4812-8873-817871e5c72c).
https://github.com/user-attachments/assets/fb11da87-3373-4812-8873-817871e5c72c

## Installation:

### 1. Hardware Setup
Follow the instructions in the `hardware` folder for setting up the physical components of OMEGA.

### 2. Software Setup
Ensure the following setup and requirements for software implementation:

- **Matlab Version**: 2018b (run as administrator)  

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
  
- **Post Matlab Installation Add-ons** (requires non-institute network):
  - Simulink Support Package for Raspberry Pi Hardware
  - MATLAB Support for MinGW-w64 C/C++/Fortran Compiler (needed for compiling S-function builder)

- **Custom File Path Setup**:
  - Add `can_bus_multi` to the Matlab path.

- **Simulink Model Configuration Parameters**:
  - Set **Hardware Board** to **Raspberry Pi**.
  - Input the Raspberry Pi IP address and login credentials under **Target Hardware Resources**.
  - Enable **Run external mode in a background thread** under **External Mode**.

### 3. Running Experiments
Refer to the `software` folder for running 1D, 2D, and 3D hopping experiments.

## License:
OMEGA is licensed under the [MIT License](LICENSE).

---
