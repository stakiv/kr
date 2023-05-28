#include "analog_control_device.h"
#include <iostream>
using namespace std;

void analog_control_device::set(bool i1) {
	I1 = i1;
}
void analog_control_device::set(bool i1, bool i2) {
	I1 = i1; I2 = i2;
}
void analog_control_device::set(bool i1, bool i2, bool q9) {
	I1 = i1; I2 = i2; Q9 = q9;
}
bool analog_control_device::is_on_1() {
	if (I1) {
		return 1;
	}
	else return 0;
}
bool analog_control_device::is_off() { return 0; }
bool analog_control_device::is_on_2() {
	if (I1 and I2) {
		return 1;
	}
	else return 0;
}
bool analog_control_device::is_on_3() {
	if (I1 and I2 and Q9) {
		return 1;
	}
	else return 0;
}

int main() {
	return 0;
}
