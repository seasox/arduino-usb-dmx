#include <DMXSerial.h>
#include <SoftwareSerial.h>

#define RX 13
#define TX 11
#define TIMEOUT 500 // millis

SoftwareSerial my_serial(RX, TX);

size_t current_channel = 1;

unsigned long last_read = -1;

void setup(void) {
	DMXSerial.init(DMXController);
	DMXSerial.maxChannel(DMXSERIAL_MAX);
	my_serial.begin(9600);
}

void loop(void) {
	if (mySerial.available()) {
		if (millis() - last_read > TIMEOUT) {
			current_channel = 1;
		}
		char c = my_serial.read();
		DMXSerial.write(current_channel, c);
		last_read = millis();
		current_channel++;
		if (current_channel > DMXSERIAL_MAX) {
			current_channel = 1;
		}
	}
}
