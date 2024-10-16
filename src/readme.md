
# HLS_QS Embedded Application for Zybo 7000 Board

This guide covers the setup and deployment of the quicksort algorithm using Vivado, Vitis, and PuTTY on a Zybo 7000 board.

## Table of Contents

1. [Introduction](#introduction)
2. [Setting Up Vivado](#setting-up-vivado)
3. [Exporting Hardware from Vivado](#exporting-hardware-from-vivado)
4. [Setting Up Vitis](#setting-up-vitis)
5. [Developing the Application in Vitis](#developing-the-application-in-vitis)
6. [Setting Up and Using PuTTY](#setting-up-and-using-putty)
7. [Testing and Troubleshooting](#testing-and-troubleshooting)
8. [Conclusion](#conclusion)

## Introduction

### Overview
This project implements a quicksort algorithm on the Zybo 7000 board using Vivado and Vitis for hardware-software co-design. The application is tested via serial communication using PuTTY.

### Tools Used
- **Vivado**: For FPGA development and configuration
- **Vitis**: For software development and deployment
- **PuTTY**: For serial communication

### Hardware Requirements
- Zybo 7000 board
- USB cables for connection
- Computer with Vivado, Vitis, and PuTTY installed

## Setting Up Vivado

### 1. Creating a New Project
- Open Vivado and start a new project.
- Select the Zybo 7000 board:
  - Vendor: `digilentinc`
  - Board: `Zybo`
- Click `Next`, then `Finish`.

![Project Setup](https://github.com/user-attachments/assets/cbce6e96-e663-4c9e-aff1-c7ee4b90696f)

### 2. Creating the Block Design
- Click on `Create Block Design`, enter a name, and click `Ok`.

![Block Design](https://github.com/user-attachments/assets/88584c4b-6295-4a8e-bdb9-e46600c05e08)

### 3. Adding ZYNQ7 Processing System
- Right-click inside the `Diagram` area or click the plus sign in the toolbar.
- Search for `zynq` and add the `ZYNQ7 Processing System`.

![ZYNQ7 Processing System](https://github.com/user-attachments/assets/a0ddf7c0-b8d8-4366-b06f-232898b4ca44)

- Click `Run Block Automation` and accept the defaults.

![Run Block Automation](https://github.com/user-attachments/assets/11697f28-9a59-42b6-ac24-ab102d2ac66f)

### 4. Adding AXI GPIO
- Add another IP, search for `AXI GPIO`, and add it.
- Click `Run Connection Automation`, select `All automation`, then click `Ok`.

![AXI GPIO](https://github.com/user-attachments/assets/de12f25f-2afb-4690-b178-26110b7f1507)

### 5. Validating the Design
- Click `Regenerate Layout`, then `Validate Design`.
- Ignore warning messages and click `Ok`.

![Validate Design](https://github.com/user-attachments/assets/30346bfb-7333-4769-b247-b42b8435cbae)

### 6. Generating the HDL Wrapper
- In `Sources`, right-click on the design and select `Create HDL Wrapper`.
- Choose `Let Vivado manage wrapper and auto-update`, then click `Ok`.

![HDL Wrapper](https://github.com/user-attachments/assets/c0638b5d-f785-4ede-9fc2-b51e85ce070d)

### 7. Generating the Bitstream
- Go to `Program and Debug` and click `Generate Bitstream`. Click `Ok`.
- Wait for the process to complete.

![Generate Bitstream](https://github.com/user-attachments/assets/ec8408a8-0dd3-46a8-95e1-ff79e8bc351b)

## Exporting Hardware from Vivado

- Export the hardware: `File` -> `Export Hardware`.
- Include the bitstream, then click `Next` and `Finish`.
- Save the wrapper file for Vitis integration.

![Export Hardware](https://github.com/user-attachments/assets/78268229-aef5-44fe-affb-230f4b63ad3f)

## Setting Up Vitis

### 1. Creating a New Workspace
- Open Vitis and create a new workspace.

![Vitis Workspace](https://github.com/user-attachments/assets/0c1c5f11-ade4-4f8a-9176-5ca944e722ac)

### 2. Setting Up the Platform Component
- Create a new platform component.
- Select the exported hardware file from Vivado as the hardware design.
- Confirm settings, then click `Finish`.

![Platform Setup](https://github.com/user-attachments/assets/c2a976d4-51e7-41e2-96a1-6b0cbcd0ff12)

### 3. Building the Platform
- Wait for the platform to generate, then build the platform.

![Build Platform](https://github.com/user-attachments/assets/3eda471a-8dc7-403b-8441-b46d2f8d18a4)

## Developing the Application in Vitis

- Use the `Hello World` template to create the application.
- Replace the template code with the quicksort algorithm in the `src` folder.
- Build and deploy the application.

![Application Development](https://github.com/user-attachments/assets/1443f55f-0d1f-4b56-b0a6-604d03090fe9)

## Setting Up and Using PuTTY

- Install PuTTY and set up a serial connection.
- Enter the `COM` port number and set the speed to `115200`.

![PuTTY Setup](https://github.com/user-attachments/assets/212d6fab-bc64-453b-98b0-c6aae6592d0d)

## Testing and Troubleshooting

- Open PuTTY and run the application in Vitis.
- Test the quicksort algorithm using the serial connection.
- Refer to troubleshooting steps for common issues.

![Run Application](https://github.com/user-attachments/assets/97c953cf-ac43-4eb9-81bf-0779c026f454)

## Conclusion

This guide outlines the setup and deployment of the quicksort algorithm on the Zybo 7000 board using Vivado, Vitis, and PuTTY. For further assistance, refer to the documentation or community resources.

