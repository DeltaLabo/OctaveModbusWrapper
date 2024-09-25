#include <HardwareSerial.h>

#include "OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h"


// Define the HardwareSerial used as an RS-485 port
HardwareSerial RS485(1);

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus
OctaveModbusWrapper octave(RS485);

// Variable to store the last error code
uint8_t modbusErrorCode;


void setup() {
  // Use Serial0 port for debugging and logging
  Serial.begin(9600);

  // Start the Modbus serial port
  RS485.begin(MODBUS_BAUDRATE, PARITY, RS485_RX_PIN, RS485_TX_PIN);

  // Start the Octave Modbus object
  octave.begin(MODBUS_BAUDRATE);

  // Wait 500ms for Modbus startup
  delay(500);
}


void loop() {
    // Read Signed Current Flow from Octave meter via Modbus
    double signedCurrentFlow;
    modbusErrorCode = octave.SignedCurrentFlow_double(&signedCurrentFlow);

    if (modbusErrorCode == 0) { // No error
        Serial.print("\nSigned current flow: ");
        octave.PrintDouble(signedCurrentFlow);
    } else {
        octave.PrintError(modbusErrorCode, Serial);
    }

    // Read Net Signed Volume from Octave meter via Modbus
    int32_t netSignedVolume;
    modbusErrorCode = octave.NetSignedVolume_int32(&netSignedVolume);

    if (modbusErrorCode == 0) { // No error
        Serial.print("Net signed volume: ");
        Serial.println(netSignedVolume);
    } else {
        octave.PrintError(modbusErrorCode, Serial);
    }

    delay(1000);
}