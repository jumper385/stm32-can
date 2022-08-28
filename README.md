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
`can-swither.h` acts as 'switchboard' for the lower level CAN Bus driver `uwaa_can_sys.h`. This file is configurable by the user and serves to hold all the data that needs to be 'sniffed' by the CAN node in a single struct. There are three critical components that require user changes. 
### `typedef struct CAN_RX`
This type definition holds the data that needs to be initialized in the `main.c` file. This file holds the parsed data that subsequent functions in `main.c` should use access and use. In the repository's case, we store latitude, longitide, altitude etc in this struct. Feel free to change this to suit your project.

![image](https://user-images.githubusercontent.com/17038915/187078254-1b5399a2-bd94-4f1b-8735-4c35da837d47.png)
### `enum_message_ids`
This holds the enumerated CAN_FRAME_XXX ID's specific to the project. The enumerated values define the can message ID when transmitted and can be accesed in `main.c`.
![image](https://user-images.githubusercontent.com/17038915/187078505-77102dc2-6b43-4eb2-abe4-3ae9809e2109.png)

![image](https://user-images.githubusercontent.com/17038915/187078489-38ceaeb0-0d84-4f5d-9d94-c73a9f6678ea.png)
