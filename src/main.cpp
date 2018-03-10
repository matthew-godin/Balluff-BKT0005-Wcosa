/*
Author: Matthew Godin

Role: Simple code to read contrast values from
      a balluff BKT0005 photoelectric contrast sensor.
      We read the contrast value and whether or not the
      wiring mode is set to PNP.

Publication: March 10th, 2018
*/
#include "BKT0005.h"
#include "Cosa/Watchdog.hh"
#include "Cosa/Trace.hh"
#include "Cosa/UART.hh"

using namespace wlp;

BKT0005 contrast_sensor(Board::A8, Board::D24);

void setup() {
	uart.begin(9600);
	trace.begin(&uart, PSTR("TEST STARTED\n"));
	Watchdog::begin();
}

void loop() {
	contrast_sensor.begin();
	trace << "Contrast: " << contrast_sensor.read_contrast() << endl;
	contrast_sensor.sleep();
	trace << "Wiring in PNP: " << contrast_sensor.read_pnp() << endl;
	Watchdog::delay(2000);
}
