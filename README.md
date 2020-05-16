# Arduino USB-DMX

A firmware to use an Arduino as a USB-TTL-DMX thingie. Just attach your USB-TTL-Converter 
to 13 (RX) and 11 (TX). Now use a serial connection from your device to send data using the Arduino's UART.

## What it does
This firmware will read individual bytes from software serial and send them to your DMX chip attached to your Arduino's UART.
The firmware expects 512 bytes sent on Pin 11 with a 9600 baudrate. The first byte read corresponds to DMX channel 1, second
byte to DMX channel 2 and so on. After 500 milliseconds, the current channel is reset to 1, so incomplete frames can be sent.

## Applications
I use this firmware as a cheap and simple replacement for DMXKing or Enttec devices while still not needing to control DMX timings in client 
software as is the case for cheap FTDI-based USB-DMX converters.
