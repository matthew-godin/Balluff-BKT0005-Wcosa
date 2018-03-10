/*
Author: Matthew Godin

Role: Simple code to read contrast values from
      a balluff BKT0005 photoelectric contrast sensor.
      We read the contrast value and whether or not the
      wiring mode is set to PNP.

Publication: March 10th, 2018
*/
#include "Cosa/OutputPin.hh"
#include "Cosa/InputPin.hh"
#include "Cosa/Watchdog.hh"
#include "Cosa/AnalogPin.hh"
#include "Cosa/Trace.hh"
#include "Cosa/UART.hh"

void readBalluffPhotoelectric();

AnalogPin analogPin(Board::A8);
InputPin pnpPin(Board::D24);

void setup() {
	uart.begin(9600);
	trace.begin(&uart, PSTR("TEST STARTED\n"));
	Watchdog::begin();
}

void loop() {
	readBalluffPhotoelectric();
	Watchdog::delay(2000);
}

void readBalluffPhotoelectric()
{
	analogPin.powerup();
	trace << "Contrast: " << analogPin.sample() << endl;
	analogPin.powerdown();
	trace << "Wiring in PNP: " << pnpPin.is_on() << endl;
}
