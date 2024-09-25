Octave Modbus Wrapper
============

### What is this repository for?

* This repository was created to develop an Arduino wrapper for Modbus communication with Arad Octave ultrasonic water meters.

It is compatible with ESP32- and Arduino-based microcontrollers, using any TTL-to-RS485 converter that can be interfaced via UART, and Arad Octave meters versions 4.02 and up.

This project is based on the Modbus RTU library developed by [Industrial Shields](https://github.com/Industrial-Shields/arduino-Modbus).

### Arad Octave water meters info

* [Documentation page](https://arad.co.il/products/bulk-water-meters/octave-ultrasonic-water-meter/)
* See [`Octave Memory Map.md`](https://github.com/DeltaLabo/OctaveModbusWrapper/blob/main/Octave%20Memory%20Map.md) for explanatory notes about the Modbus memory map implemented in Octave water meters

### How do I set up?

* Install Git
* Install Arduino IDE
* If using **ESP32-based** microcontrollers, follow these [instructions](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/#software-setup) for Arduino IDE support
* If using **Arduino-based** microcontrollers, install [`fp64lib`](https://www.arduino.cc/reference/en/libraries/fp64lib/) via the library manager
* Clone this repo and upload [`main.ino`](https://github.com/DeltaLabo/OctaveModbusWrapper/tree/main/main) to the ESP32
* Use an [Octave NFC reader](https://arad.co.il/wp-content/uploads/OCTAVE-Installation-Manuel-EN-web.pdf) to configure the water meter's Modbus slave address, baud rate, parity, and other variables
* Modify the `MODBUS_SLAVE_ADDRESS` in `OctaveModbusWrapper.h` accordingly
* `#import OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h` or `#import OctaveModbusWrapper/Arduino/OctaveModbusWrapper.h` in your Arduino code file
* Create a `Serial`-like object (either `Hardware-` or `SoftwareSerial` work) with the appropiate baud rate and parity that can interface via RS-485 with the Modbus module, most commonly using a TTL-to-RS485 module
* Create an `OctaveModbusWrapper` object with the `Serial` as a parameter, for example:
```
// Define the HardwareSerial used as an RS-485 port
HardwareSerial RS485(0);
// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus
OctaveModbusWrapper octave(RS485);
```
* `begin()` the `Serial` and `OctaveModbusWrapper` objects, i.e.:
```
// Start the Modbus serial port
RS485.begin(MODBUS_BAUDRATE, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);
// Set RTS pin
RS485.setPins(RS485_RX_PIN, RS485_TX_PIN, -1, RS485_RTS_PIN);
// Disable hardware flow control, as required by the documentation,
// and set the TX buffer size threshold to 128 bytes (maximum value)
RS485.setHwFlowCtrlMode(UART_HW_FLOWCTRL_DISABLE, 128);
// Enable half-duplex flow control
RS485.setMode(UART_MODE_RS485_HALF_DUPLEX);

// Start the Octave Modbus object
octave.begin(MODBUS_BAUDRATE);
```

### Contribution guidelines ###

* If you want to propose a change or need to modify the code for any reason first clone this [repository](https://github.com/DeltaLabo/rsim) to your PC and create a new branch for your changes. Once your changes are complete and fully tested ask the administrator permission to push this new branch into the source.
* If you just want to do local changes instead you can download a zip version of the repository and do all changes locally in your PC. 

### Who do I talk to? ###

* [Juan J. Rojas](mailto:juan.rojas@itcr.ac.cr)
* [Anthony Arguedas](mailto:antarguedas@estudiantec.r)
