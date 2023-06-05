#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include "kr.h"
using namespace std;


void analog_sensor::set(string line) {
	Line = line;
}
bool analog_sensor::get_num(int num) {
	if (num > 0) return 1;
	else return 0;
}
bool analog_sensor::is_present() {
	if (Line == "1") return 1;
	else return 0;
}

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
		Sleep(500); return 1;
	}
	else return 0;
}
bool analog_control_device::is_off() { return 0; }
bool analog_control_device::is_on_2() {
	if (I1 and I2) {
		Sleep(500); return 1;
	}
	else return 0;
}
bool analog_control_device::is_on_3() {
	if (I1 and I2 and Q9) {
		Sleep(500); return 1;
	}
	else return 0;
}

void container::set(int num_) {
	num = num_;
}
int container::quantity() {
	num -= 1;
	return (num + 1);
}


void file::set(string k, int i) {
	K = k; I = i;
}
void file::write() {
	ofstream out("exit.txt", ios::app);
	if (out.is_open()) {
		out << "Cycle " << I << ": An error has occurred: " << K << endl;
	}
	out.close();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	bool i0, i1, i2, i3, i4, i5, i6, i8, i7, i9;
	bool q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11;
	int num_of_containers0, num_of_caps3, i = 0, num1, num2, count = 0, w = 0;
	string k, f;
	analog_sensor s0;
	analog_sensor s1;
	analog_sensor s2;
	analog_sensor s3;
	analog_sensor s4;
	analog_sensor s5;
	analog_sensor s6;
	analog_sensor s7;
	analog_sensor s8;
	analog_sensor s9;
	analog_control_device cd0;
	analog_control_device cd2;
	analog_control_device cd3;
	analog_control_device cd4;
	analog_control_device cd5;
	analog_control_device cd6;
	analog_control_device cd7;
	analog_control_device cd9;
	analog_control_device cd10;
	analog_control_device cd11;
	file err;

	ifstream in("start3.txt");
	string line;
	getline(in, line);
	vector<string> arr;
	string delim(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();
	while ((next = line.find(delim, prev)) != string::npos) {
		string tmp = line.substr(prev, next - prev);
		arr.push_back(line.substr(prev, next - prev));
		prev = next + delta;
	}
	string tmp = line.substr(prev);
	arr.push_back(line.substr(prev));
	container n1;
	container n2;
	if (w == 0) {
		num_of_containers0 = stoi(arr[0]);
		n1.set(num_of_containers0);
		num_of_caps3 = stoi(arr[1]);
		n2.set(num_of_caps3);
	}
	i0 = i3 = 0; num1 = num2 = 0;
	if (w != 0) in.close();
	while (in.is_open()) {

		i += 1;
		cout << "Cycle " << i << endl;

		num1 = n1.quantity();
		num2 = n2.quantity();

		i0 = s0.get_num(num1); 
		i3 = s3.get_num(num2);  

		if (!i0 and !i3) {
			cout << "I0 and I3 containers are empty" << endl;
			in.close();
			break;
		}
		if (!i3) {
			cout << "I3 container is empty" << endl;
			in.close();
			break;
		}
		if (!i0) {
			cout << "I0 container is empty" << endl;
			in.close();
			break;
		}
		cd0.set(i0);  
		q1 = q0 = cd0.is_on_1();
		q1 = q0 = cd0.is_off();
		cout << "New bottle is on the first conveyor" << endl;
		int m = 0;

		while (in.is_open()) {
			string line;
			getline(in, line);
			vector<string> arr;
			string delim(" ");
			size_t prev = 0;
			size_t next;
			size_t delta = delim.length();
			while ((next = line.find(delim, prev)) != string::npos) {
				string tmp = line.substr(prev, next - prev);
				arr.push_back(line.substr(prev, next - prev));
				prev = next + delta;
			}
			string tmp = line.substr(prev);
			arr.push_back(line.substr(prev));

			
			s1.set(arr[1]); 
			i1 = s1.is_present();
			s2.set(arr[2]); 
			i2 = s2.is_present();
			s4.set(arr[3]); 
			i4 = s4.is_present();
			s5.set(arr[4]);
			i5 = s5.is_present();
			s7.set(arr[6]);
			i7 = s7.is_present();
			s6.set(arr[5]);
			i6 = s6.is_present();
			s8.set(arr[7]);
			i8 = s8.is_present();
			s9.set(arr[8]);
			i9 = s9.is_present();

			if (i1) cout << "I1" << " "; 
			if (i2) cout << "I2" << " ";
			if (i4) cout << "I4" << " ";
			if (i5) cout << "I5" << " ";
			if (i7) cout << "I7" << " ";
			if (i6) cout << "I6" << " ";
			if (i8) cout << "I8" << " ";
			if (i9) cout << "I9" << " ";


			if (i1 and !i2 and !i4 and !i5 and !i6 and !i7 and !i8 and !i9) { // шаг 3
				q2 = cd2.is_off();
				cd3.set(i1, !q2);  
				q3 = cd3.is_on_2();
				q3 = cd3.is_off();
				if (q3) {
					k = "Q3 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				cd2.set(!q3);
				q2 = cd2.is_on_1();
				if (!q2) {
					k = "Q2 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (((m != 1) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The bottle was filled" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and i2 and !i4 and !i5 and !i6 and !i7 and !i8 and !i9 and (m == 1)) { // шаг 7
				q2 = cd2.is_off();
				cd4.set(i2, !q2); 
				q4 = cd4.is_on_2();
				q4 = cd4.is_off();
				if (q4) {
					k = "Q4 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				cd2.set(!q4);
				q2 = cd2.is_on_1();
				if (!q2) {
					k = "Q2 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (((m != 2) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The lid is on the bottle" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and i4 and !i5 and !i6 and !i7 and !i8 and !i9 and (m == 2)) { // шаг 10
				q2 = cd2.is_off();
				cd5.set(i4, !q2);  
				q5 = cd5.is_on_2();
				q5 = cd5.is_off();
				cd6.set(!q5);
				q6 = cd6.is_on_1();
				q6 = cd6.is_off();
				cd5.set(!q6);
				q5 = cd5.is_on_1();
				q5 = cd5.is_off();
				if (q5 or q6) {
					k = "Q5 or Q6 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				cd2.set(!q5, !q6);
				q2 = cd2.is_on_2();
				if (!q2) {
					k = "Q2 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (m != 3 or (w != 0)) { 
					w += 1; in.close(); break; 
				}
				cout << "The lid was tightened" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and i5 and !i6 and !i7 and !i8 and !i9 and (m == 3)) { // шаг 15
				cd2.set(i5);
				q2 = cd2.is_off();
				if (q2) {
					k = "Q2 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if ((m != 4) or (w != 0)) {
					w += 1; in.close(); break;
				}
				cout << "The first conveyor is off" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and !i5 and !i6 and i7 and !i8 and !i9 and (m == 4)) { // шаг 16
				cd9.set(i5, i7);
				q9 = cd9.is_on_2();
				q9 = cd9.is_off();
				cout << "The second convoyer is on" << endl;
				cd7.set(i7, !q9); 
				q7 = q8 = cd7.is_on_3();
				q7 = q8 = cd7.is_off();
				if (q7 or q8) {
					k = "Q7 or Q8 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				cd9.set(!q7, !q8);
				q9 = cd9.is_on_2();
				if (!q9) {
					k = "Q9 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (((m != 5) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The bottle is in the box on the second conveyor" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and !i5 and i6 and !i7 and !i8 and !i9 and (m == 5)) { // шаг 20
				q9 = cd9.is_off();
				cd10.set(i6, !q9); 
				q10 = cd10.is_on_2();
				q10 = cd10.is_off();
				if (q10) {
					k = "Q10 didn't turn off";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				cd9.set(!q10);
				q9 = cd9.is_on_1();
				if (!q9) {
					k = "Q9 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (((m != 6) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The print was made" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and !i5 and !i6 and !i7 and i8 and !i9 and (m == 6)) { // шаг 23
				cd11.set(i8);
				q11 = cd11.is_on_1();
				if (!q11) {
					k = "Q11 didn't turn on";
					err.set(k, i); err.write();
					cout << "An error has occurred" << endl; in.close(); break;
				}
				m += 1;
				if (((m != 7) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The third convoyer is on" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and !i5 and !i6 and !i7 and !i8 and i9 and (m == 7)) { // шаг 24
				cd9.set(i9);
				q9 = cd9.is_off();
				m += 1;
				if (((m != 8) or (w != 0))) { 
					w += 1; in.close(); break; 
				}
				cout << "The second convoyer is off" << endl;
				Sleep(500);
				continue;
			}
			else if (!i1 and !i2 and !i4 and !i5 and !i6 and !i7 and !i8 and !i9 and (m == 8)) {
			cout << "End of the cycle" << endl; cout << endl;
				break;
			}
			else {
				cout << "Unexpected object or no object" << endl; 
				k = "unexpected object or no object";
				err.set(k, i); err.write();
				in.close();
				break;
			}
}
		if ((m != 8) or (w != 0)) { 
			num1 -= 1; num2 -= 1; cout << "MISTAKE" << endl; cout << endl; in.close(); break;
		}
		count += 1;
	}

	q2 = cd2.is_off();
	q9 = cd9.is_off();
	q11 = cd11.is_off(); 
	if (i0) cout << num1 << " details left in I0" << endl;
	if (i3) cout << num2 << " details left in I3" << endl;
	cout << count << " products were produced" << endl;
	ofstream out("exit.txt", ios::app);
	if (out.is_open()) {
		out << num1 << " details left in I0" << endl;
		out << num2 << " details left in I3" << endl;
		out << count << " products were produced" << endl;
		out << endl;
	}
	out.close();
	cout << "stop";

}





