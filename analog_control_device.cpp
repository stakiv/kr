#include <iostream>
#include <windows.h>
using namespace std;

class analog_control_device {
private:
	bool I1, I2, Q9;
public:
	void set(bool i1) {
		I1 = i1;
	}
	void set(bool i1, bool i2) {
		I1 = i1; I2 = i2;
	}
	void set(bool i1, bool i2, bool q9) {
		I1 = i1; I2 = i2; Q9 = q9;
	}
	bool is_on_1() {
		if (I1) {
			//Sleep(1000);
			return 1;
		}
		else return 0;
	}
	bool is_off() return 0;
	bool is_on_2() {
		if (I1 and I2) {
			//Sleep(1000);
			return 1;
		}
		else return 0;
	}
	bool is_on_3() {
		if (I1 and I2 and Q9) {
			//Sleep(1000);
			return 1;
		}
		else return 0;
	}
};


