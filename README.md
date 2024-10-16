# HLS_QS Embedded Application Guide

This guide details the steps for setting up and running a quicksort algorithm on a Zybo 7000 board using Vivado, Vitis, and PuTTY.

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
7. [Testing and Troubleshooting](#testing-and-troubleshooting)
8. [Conclusion](#conclusion)

## Introduction

This guide walks you through the process of setting up an embedded application using Vivado, Vitis, and PuTTY for the Zybo 7000 board. The application implements a quicksort algorithm and is run using a serial connection via PuTTY.





## Setting Up Vivado

### Creating a New Project
1. Open Vivado and select **Create New Project**.
![Screenshot 2024-10-16 143136](https://github.com/user-attachments/assets/cbce6e96-e663-4c9e-aff1-c7ee4b90696f)

  Select the correct board by: `vendor:` digilentinc , board `Zybo`. Or just search for Zybo.
  ![image](https://github.com/user-attachments/assets/88584c4b-6295-4a8e-bdb9-e46600c05e08)

 Click `Next` and then `Finish`. 

 
  Your screen should look something like this. Click `Create block design`, select a fitting name and then `Ok`. 
  ![image](https://github.com/user-attachments/assets/a8c47bd5-ada9-43fc-84fc-8f2fd77f3344)

 Once the block design has finished loading, right click inside of the `Diagram` or click the plus sign in the `Diagram` toolbar. 
![image](https://github.com/user-attachments/assets/a0ddf7c0-b8d8-4366-b06f-232898b4ca44)

 Search for `zynq` and double click the `ZYNQ7 Processing System`
 ![image](https://github.com/user-attachments/assets/50ad7d2b-d8e0-4bb4-bbc0-7f7ec2a1325f)

 After the block has been added, click `Run block Automation`. Click ok. 
 ![image](https://github.com/user-attachments/assets/11697f28-9a59-42b6-ac24-ab102d2ac66f)
 The block should now look like this: 
 
![image](https://github.com/user-attachments/assets/5c8031b8-49ad-4213-bb53-dd74c6361667)

Add another IP , search for `axi gpi` and double click the `AXI GPIO`
![image](https://github.com/user-attachments/assets/de12f25f-2afb-4690-b178-26110b7f1507)

Now click `Run Connection Automation` , select `All automation` then click `Ok`  
![image](https://github.com/user-attachments/assets/91323b2b-675a-442d-864b-bebfc8dfd507)

In the `Diagram` toolbar click `Regenerate layout` and then `Validate Design`, ignore warning messasges `Ok`
![image](https://github.com/user-attachments/assets/30346bfb-7333-4769-b247-b42b8435cbae)

Go to `Sources` , under design sources right click the design and click `Create HDL wrapper`
![image](https://github.com/user-attachments/assets/c0638b5d-f785-4ede-9fc2-b51e85ce070d)

Check `Let vivado manage wrapper and auto-update` , `Ok`
![image](https://github.com/user-attachments/assets/34f64415-a210-42df-9180-764e9fbaec2c)

After the wrapper is created, go to `Program and debug` and click `Generate bitstream`. `Ok` . 
![image](https://github.com/user-attachments/assets/ec8408a8-0dd3-46a8-95e1-ff79e8bc351b)
This will take some time but look under `Design runs` to see that it's running. 
![image](https://github.com/user-attachments/assets/61717502-c05e-45e3-8b34-3c286e4f0ca7)

When the prosses is finnished just click `Ok`. 
![image](https://github.com/user-attachments/assets/804c43a1-4cec-4749-a461-5c3816d1d92a)

Export hardware , Next , `Include bitstream` , next , finish. Remeber where you put the wrapper as you need it for the next step.   
![image](https://github.com/user-attachments/assets/78268229-aef5-44fe-affb-230f4b63ad3f)

#Vitis

Open a new workspace in vitis
![image](https://github.com/user-attachments/assets/0c1c5f11-ade4-4f8a-9176-5ca944e722ac)

Create a new platform component. 
![image](https://github.com/user-attachments/assets/f8dd3985-4873-4353-8a63-4cb369fdca13)

Give the platform a name and click  `Next`
![image](https://github.com/user-attachments/assets/00eff955-8e13-4c68-9bb3-c2a4847f2984)

Locate the wrapper you exported earlier and select it as hardware design. Click `Next`
![image](https://github.com/user-attachments/assets/c2a976d4-51e7-41e2-96a1-6b0cbcd0ff12)

Keep / Make sure you have these settings, click `Next` and then `Finish`. 
![image](https://github.com/user-attachments/assets/64bcd69b-07f0-44ee-8d32-b6884f8e5031)

Wait for the platform to generate.
![image](https://github.com/user-attachments/assets/3b29d844-0f97-47de-8097-78947dc742bd)

Once the platform is built you should be able to click build platform, click the hammer icon to build the platform. 
![image](https://github.com/user-attachments/assets/3eda471a-8dc7-403b-8441-b46d2f8d18a4)
When the platform is built it should look like this. 
![image](https://github.com/user-attachments/assets/f6d5664d-3f47-4015-98c7-fe4ef82f36d4)
Go to the welcome page and click `Examples`
![image](https://github.com/user-attachments/assets/637239ae-3a89-4ad2-ae34-6ae28f8625c2)
Locate the `Hello World` example and click `Create Application Component from Template`. 
![image](https://github.com/user-attachments/assets/1560a4b8-0eb6-4a50-ab93-c5d8b00b364f)

Here you can rename the component or just leave as is. 
![image](https://github.com/user-attachments/assets/8adbe879-7e33-4128-9de1-fbc3e72164fe)


select the platform we just built from the wrapper we exported from vivado 
![image](https://github.com/user-attachments/assets/3d807949-a17b-4d4c-aecf-f7e2196b9ac4)

Click `Next`
![image](https://github.com/user-attachments/assets/98eb5020-58c0-4368-9537-dfbf849e473b)

Click `Finish`
![image](https://github.com/user-attachments/assets/7fdaed3b-10d0-416d-8cfa-61bf8c3bbce7)

Locate the `src`folder for you platform. If unsure where you put them use this to find the location. 
![image](https://github.com/user-attachments/assets/c0bf33cd-aced-476f-a9bd-e1baa37982e2) 

Copy the files from this repo under `src`and replace the files your local `src`folder. 
![image](https://github.com/user-attachments/assets/4c86dc8f-5f02-4f20-a76a-0cac44fdd3c4)

Go to the flow navigator and click `Build` for your component
![image](https://github.com/user-attachments/assets/1443f55f-0d1f-4b56-b0a6-604d03090fe9)
When done 
![image](https://github.com/user-attachments/assets/f8a89307-dd9c-4202-ba3d-acd3a18eec7f)
Now connect your zybo 7000 board and locate it in the hardware manager to find the correct port. 
![image](https://github.com/user-attachments/assets/048a8d3b-264e-4e9b-be1a-f7273451bdd8)
Open putty, pick `Serial`connection , enter your `COM` number and set speed to 115200. 
![image](https://github.com/user-attachments/assets/212d6fab-bc64-453b-98b0-c6aae6592d0d)
Then click `open`. 
![image](https://github.com/user-attachments/assets/97c953cf-ac43-4eb9-81bf-0779c026f454)
Now with the putty terminal open click run in vitis. 
![image](https://github.com/user-attachments/assets/a175b7d6-df42-4a61-b498-3529ed745054)

![image](https://github.com/user-attachments/assets/cae0691a-ce57-4d04-b20c-3b428d2c75b4)

![image](https://github.com/user-attachments/assets/5bcca538-a502-47af-8247-531b417f8d9d)











