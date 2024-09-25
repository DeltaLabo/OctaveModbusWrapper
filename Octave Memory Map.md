# Notes about the Arad Octave water meter's Modbus memory map

Arad Octave ultrasonic water meters of versions 4.02 and up have Modbus output capabilites, enabled by the [Octave Modbus Module](https://arad.co.il/wp-content/uploads/OCTAVE-Installation-Manuel-EN-web.pdf).

According to the [memory map](https://www.pipersberg.de/wp-content/uploads/2021/09/OCTAVE-Handbuch-Modbus-Modul.pdf), all read operations are executed on input registers (modbus code `04`).

32-bit values (signed or unsigned) are stored in 2 16-bit registers, with a `AB CD` byte order, whereas 64-bit values (double precision) are stored in 4 registers, with a `HG FE DC BA` order.