

#include "main.h"

void operatorControl() {
	
	while (1) {
		int joy = joystickGetAnalog(1,2);
			motorSet(2,joy);
			motorSet(3,joy);
			motorSet(8,-joy);
			motorSet(9,-joy);
		}
		delay(20);
	}
