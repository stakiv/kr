#include <iostream>
#include "container.h"
using namespace std;


void container::set(int num_) {
	num = num_;
}
int container::quantity() {
	num -= 1;
	return (num);
}