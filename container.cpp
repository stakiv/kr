#include <iostream>
using namespace std;

class container {
private:
	int num;
public:
	void set(int num_) {
		num = num_;
	}
	int quantity() {
		num -= 1;
		return (num);
	}
};
