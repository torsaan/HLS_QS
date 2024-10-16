# HLS_QS
Embedded application Vitis / Vivado , for runing the quicksort algorithm on a zybo 7000 board. 





#1. 
  Start a new project in vivado.
  * ![Screenshot 2024-10-16 143136](https://github.com/user-attachments/assets/cbce6e96-e663-4c9e-aff1-c7ee4b90696f)

  Select the correct board by: `vendor:` digilentinc , board `Zybo`. Or just search for Zybo.
  ![image](https://github.com/user-attachments/assets/88584c4b-6295-4a8e-bdb9-e46600c05e08)

 Click `Next` and then `Finish`. 

#2. 
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


