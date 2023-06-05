#pragma once
class analog_sensor {
private:
	string Line;
public:
	void set(string line);
	bool get_num(int num);
	bool is_present();
};
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
class container {
private:
	int num;
public:
	void set(int num_);
	int quantity();
};
class file {
private: string K; int I;
public:
	void set(string k, int i);
	void write();
};