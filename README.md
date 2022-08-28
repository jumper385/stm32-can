# Simple CAN Bus
This library is build to make CAN Bus easier to use. Addiitonally, this README should make it easier for you to implement CAN Bus in your projects as well. 

# Getting Started

## Pre-Req
1. STM32CubeIDE
2. CAN Enabled STM32 MCU Board
3. CAN Transceiver

## Step 1. Setup CAN Bus in the Configurator
You'll need to change the Pre-scaler value, Time Quanta Settings and Operating Mode (Optional). NOTE: when changing the operating to Loopback mode, data will be sent to the physical CAN Bus to other connected nodes.
![image](https://user-images.githubusercontent.com/17038915/187077557-f6ae311a-caae-40cd-b399-d4af6019bfd7.png)

You'll also need to enable the "CAN RX0 and USB low priority interrupts" configuration in the "NVIC Settings"
![image](https://user-images.githubusercontent.com/17038915/187077633-052d0002-29ce-43bc-9d6b-455c14cdb8ec.png)

Save the code with `Ctrl-S` and the code will automaticlaly generate.

## Step 2. Include `can-switcher.h`
`can-swither.h` acts as 'switchboard' for CAN Bus. 
