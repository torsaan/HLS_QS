### T0d0: Wrapper fil kan ikke brukes til å bygge platformen(?)
   * Litt usikker på om dette går an å bare flytte på. uten alle filer. 

# HLS_QS Embedded Application Guide

This guide details the steps for setting up and running a quicksort algorithm on a Zybo 7000 board using Vivado, Vitis, and PuTTY.
If you want a video instead you can look here [YouTube](https://www.youtube.com/watch?v=c9cXk7Su5Zw)


## Table of Contents
1. [Introduction](#introduction)
2. [Setting Up Vivado](#setting-up-vivado)
   - [Creating a New Project](#creating-a-new-project)
   - [Selecting the Zybo 7000 Board](#selecting-the-zybo-7000-board)
   - [Creating the Block Design](#creating-the-block-design)
   - [Configuring Block Automation](#configuring-block-automation)
   - [Adding AXI GPIO](#adding-axi-gpio)
   - [Validating the Design and Generating HDL Wrapper](#validating-the-design-and-generating-hdl-wrapper)
   - [Generating the Bitstream](#generating-the-bitstream)
3. [Exporting Hardware from Vivado](#exporting-hardware-from-vivado)
4. [Setting Up Vitis](#setting-up-vitis)
   - [Creating a New Workspace](#creating-a-new-workspace)
   - [Setting Up the Platform Component](#setting-up-the-platform-component)
   - [Building the Platform](#building-the-platform)
5. [Developing the Application in Vitis](#developing-the-application-in-vitis)
   - [Importing the Quicksort Algorithm](#importing-the-quicksort-algorithm)
   - [Building the Application](#building-the-application)
6. [Setting Up and Using PuTTY](#setting-up-and-using-putty)

## Introduction

This guide walks you through the process of setting up an embedded application using Vivado, Vitis, and PuTTY for the Zybo 7000 board. The application implements a quicksort algorithm and is run using a serial connection via PuTTY.

## Prerequisites
* Vitis 2023.X
* Vivado 2023.X
* Zybo Zynq-7000 development board
* PuTTY
* Svaj



## Setting Up Vivado

### Creating a New Project
1. Open Vivado and select **Create New Project**.
2. Choose name and directory, then click **Next**.
3. Select **RTL Project** and **Do not specify sources at this time**, then click **Next**.

![Screenshot 2024-10-16 143136](https://github.com/user-attachments/assets/cbce6e96-e663-4c9e-aff1-c7ee4b90696f)

4. Choose the Zybo 7000 board from the vendor `digilentinc`, or search for "Zybo".
  ![image](https://github.com/user-attachments/assets/88584c4b-6295-4a8e-bdb9-e46600c05e08)

5. Click **Next** and then **Finish**.





 ### Creating the Block Design
Your screen should look something like this. Click **Create Block Design**, enter a name, and click **OK**.
![image](https://github.com/user-attachments/assets/a8c47bd5-ada9-43fc-84fc-8f2fd77f3344)

2. Right-click in the **Diagram** or click the **+** sign in the toolbar.
![image](https://github.com/user-attachments/assets/a0ddf7c0-b8d8-4366-b06f-232898b4ca44)

3. Search for `ZYNQ7` and add the **ZYNQ7 Processing System**.
 ![image](https://github.com/user-attachments/assets/50ad7d2b-d8e0-4bb4-bbc0-7f7ec2a1325f)

4. Click **Run Block Automation**, then **OK**.
 ![image](https://github.com/user-attachments/assets/11697f28-9a59-42b6-ac24-ab102d2ac66f)
 The block should now look like this: 
![image](https://github.com/user-attachments/assets/5c8031b8-49ad-4213-bb53-dd74c6361667)





### Configuring Block Automation

1. Add an **AXI GPIO** by searching for it in the IP catalog.
![image](https://github.com/user-attachments/assets/de12f25f-2afb-4690-b178-26110b7f1507)

2. Click **Run Connection Automation**, select **All automation**, and click **OK**.
![image](https://github.com/user-attachments/assets/91323b2b-675a-442d-864b-bebfc8dfd507)





### Validating the Design and Generating HDL Wrapper

1. In the **Diagram** toolbar, click **Regenerate Layout**.
2. Validate the design by clicking **Validate Design**. Ignore warning messages.
![image](https://github.com/user-attachments/assets/30346bfb-7333-4769-b247-b42b8435cbae)

3. Go to **Sources**, right-click the design, and click **Create HDL Wrapper**.
![image](https://github.com/user-attachments/assets/c0638b5d-f785-4ede-9fc2-b51e85ce070d)

4. Select **Let Vivado manage wrapper and auto-update**, then click **OK**.
![image](https://github.com/user-attachments/assets/34f64415-a210-42df-9180-764e9fbaec2c)





### Generating the Bitstream

1. Go to **Program and Debug** and click **Generate Bitstream**.
![image](https://github.com/user-attachments/assets/ec8408a8-0dd3-46a8-95e1-ff79e8bc351b)
2. Confirm by clicking **OK**. Monitor progress under **Design Runs**.
![image](https://github.com/user-attachments/assets/61717502-c05e-45e3-8b34-3c286e4f0ca7)

3. When completed, click **OK**.
![image](https://github.com/user-attachments/assets/804c43a1-4cec-4749-a461-5c3816d1d92a)




## Exporting Hardware from Vivado

1. Go to **File** > **Export** > **Export Hardware**.
2. Check **Include bitstream**, then click **Next** and **Finish**.
3. Note the location of the wrapper file as it will be needed for Vitis.
![image](https://github.com/user-attachments/assets/78268229-aef5-44fe-affb-230f4b63ad3f)




## Setting Up Vitis
### Creating a New Workspace


1. Open Vitis and create a new workspace.
![image](https://github.com/user-attachments/assets/0c1c5f11-ade4-4f8a-9176-5ca944e722ac)

2. Create a new platform component.
![image](https://github.com/user-attachments/assets/f8dd3985-4873-4353-8a63-4cb369fdca13)

3. Name the platform and select the exported hardware wrapper as the hardware design.
![image](https://github.com/user-attachments/assets/00eff955-8e13-4c68-9bb3-c2a4847f2984)

![image](https://github.com/user-attachments/assets/c2a976d4-51e7-41e2-96a1-6b0cbcd0ff12)

Keep / Make sure you have these settings, click `Next` and then `Finish`. 
![image](https://github.com/user-attachments/assets/64bcd69b-07f0-44ee-8d32-b6884f8e5031)

### Setting Up the Platform Component
Wait for the platform to generate.
![image](https://github.com/user-attachments/assets/3b29d844-0f97-47de-8097-78947dc742bd)



### Building the Platform

1. Build the platform by clicking the **Build Platform** icon (hammer icon).
![image](https://github.com/user-attachments/assets/3eda471a-8dc7-403b-8441-b46d2f8d18a4)
2. Monitor the build progress until it completes.
![image](https://github.com/user-attachments/assets/f6d5664d-3f47-4015-98c7-fe4ef82f36d4)



## Developing the Application in Vitis
### Importing the Quicksort Algorithm

1. Go to the welcome page in Vitis and click `Examples`.
![image](https://github.com/user-attachments/assets/637239ae-3a89-4ad2-ae34-6ae28f8625c2)
2. Select the **Hello World** template to create a new application component.
![image](https://github.com/user-attachments/assets/1560a4b8-0eb6-4a50-ab93-c5d8b00b364f)

Here you can rename the component or just leave as is. 
![image](https://github.com/user-attachments/assets/8adbe879-7e33-4128-9de1-fbc3e72164fe)
### Configuring the Application


1. Configure the application settings and platform options.
2. Make sure the correct platform is selected (from the wrapper exported from Vivado).

![image](https://github.com/user-attachments/assets/3d807949-a17b-4d4c-aecf-f7e2196b9ac4)

Click `Next`
![image](https://github.com/user-attachments/assets/98eb5020-58c0-4368-9537-dfbf849e473b)

Click `Finish`
![image](https://github.com/user-attachments/assets/7fdaed3b-10d0-416d-8cfa-61bf8c3bbce7)


1. Import and replace the `src` files with the quicksort algorithm files from the repository.
![image](https://github.com/user-attachments/assets/c0bf33cd-aced-476f-a9bd-e1baa37982e2) 

2. Copy the files from this repo under `src`and replace the files your local `src`folder. 
![image](https://github.com/user-attachments/assets/4c86dc8f-5f02-4f20-a76a-0cac44fdd3c4)


### Building the Application
![image](https://github.com/user-attachments/assets/1443f55f-0d1f-4b56-b0a6-604d03090fe9)
2. Verify the build output for any errors.
![image](https://github.com/user-attachments/assets/f8a89307-dd9c-4202-ba3d-acd3a18eec7f)




### Deploying and Testing the Application
1. Connect the Zybo 7000 board and locate it in the hardware manager.
2. Use Vitis to deploy the application onto the board.


## Setting Up and Using PuTTY

### Installing PuTTY
1. Download and install PuTTY from [the official website](https://www.putty.org).

1. Connect the Zybo 7000 board and locate it in the hardware manager.
![image](https://github.com/user-attachments/assets/048a8d3b-264e-4e9b-be1a-f7273451bdd8)
### Configuring Serial Connection

1. Open PuTTY and select `Serial` as the connection type.
2. Enter your `COM` port number and set the speed to **115200**.



![image](https://github.com/user-attachments/assets/212d6fab-bc64-453b-98b0-c6aae6592d0d)

### Running the Application with PuTTY
1. Open the PuTTY terminal and start the application in Vitis.
2. Monitor the output and interact with the application as needed.

![image](https://github.com/user-attachments/assets/97c953cf-ac43-4eb9-81bf-0779c026f454)
Now with the putty terminal open click run in vitis. 
![image](https://github.com/user-attachments/assets/a175b7d6-df42-4a61-b498-3529ed745054)

![image](https://github.com/user-attachments/assets/cae0691a-ce57-4d04-b20c-3b428d2c75b4)

![image](https://github.com/user-attachments/assets/5bcca538-a502-47af-8247-531b417f8d9d)











