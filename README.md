# NECRemoteControllerSTM32
Build a Simple IR Reciever Interrupts Based
#NEC Protocol
![NEC](https://github.com/SeifEldidi/NECRemoteControllerSTM32/assets/106155115/24003296-3217-4b20-b4e5-1a3c8e864eab)
Logical '0' – a 562.5µs pulse burst followed by a 562.5µs space, with a total transmit time of 1.125ms
Logical '1' – a 562.5µs pulse burst followed by a 1.6875ms space, with a total transmit time of 2.25ms

As Shown in the Above figure and as described (credits goes to https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol for all info provided)
simple Detector can be built around the information provided just simply check the difference between rising and falling edge times if its about 562.5us a 0 zero is read 
else if it is about 1.6875ms a 1 is flagged .

-Implementation is based on Interrupts instead of polling to save cpu time
