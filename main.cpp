#include "expandable.h"

int main() {

	Expandable v1, v2;

	//push_back(value); values go into the last position. insert(index, value); values go knto the index indicated.
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v1.print();
	//10, 20, 30

	v2.push_back(100);
	v2.insert(0, 50);
	v2.push_back(20);

	v2.print();
	//50, 100, 20

	//pop_back(); removes the last value. you can make it return the value that it removed
	// erase(index);

	std::cout << v1.pop_back() << std::endl; // 30
	v1.print(); //10, 20

	std::cout << v2.erase(1); //100
	v2.print(); //50, 20

	v2.update(1, -20);
	v2.print(); //50, -20

	return 0;
}