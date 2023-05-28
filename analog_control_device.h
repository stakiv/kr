#pragma once
class analog_control_device {
private:
	bool I1, I2, Q9;
public:
	void set(bool i1);
	void set(bool i1, bool i2);
	void set(bool i1, bool i2, bool q9);
	bool is_on_1();
	bool is_off();
	bool is_on_2();
	bool is_on_3();
};

