#include "expandable.h"

Expandable::Expandable() {

	ar = new int[1];
	size = 1;
	count = 0;
}

Expandable::~Expandable() {

	delete[] ar;
}

void Expandable::expand() {

	size = size * 2; //the new size
	int* br = new int[size];
	// copy all old data form previous array to the new array
	for (int i = 0; i < count; i++) {
		*(br + i) = *(ar + i); //br[i] = ar[i]
	}
	delete[] ar;

	ar = br;
}

void Expandable::push_back(int value) {

	//expand if no space available
	if (count == size) {
		expand();
	}

	//insert at index count
	*(ar + count) = value;
	//ar[count] = value;
	//increment count
	count++;
}

void Expandable::insert(int index, int value) {

	if (count == size) { //expand if no space available
		expand();
	}

	if (index < 0 || index >= count) { //inserting to the right of current data
		index = count; // 
	}

	for (int i = count - 1; i >= 0; i--) { //shift right [index ... count-1]
		*(ar + i + 1) = *(ar + i);
	}
	*(ar + index) = value; //store value at index

	count++;
}

void Expandable::print() {

	for (int i = 0; i < count; i++) {
		std::cout << *(ar + i) << " ";
	}
	std::cout << std::endl;
}

void Expandable::update(int index, int value) {

	if (index >= 0 && index <= count - 1) {
		*(ar + index) = value; //replace existing element by new value
	}
}

int Expandable::pop_back() {

	if (count == 0) {
		return -1;
	}
	int temp = *(ar + count - 1);
	*(ar + count - 1) = 0;
	count--;
		return temp;
}

int Expandable::erase(int index) {

	if (index < 0 || index > count - 1) {
		return -1;
	}
	int temp = *(ar + index);

	for (int i = index + 1; i <= count-1; i++) { //shift left [index+1 ... count-1]
		*(ar + i - 1) = *(ar + i);
	}
	count--;
	return temp;
}

int Expandable::front() {

	if (count == 0) {
		return -1;
	}
	return *ar; //*(ar+0); ar[0]
}

int Expandable::back() {

	if (count == 0) {
		return -1;
	}
	return *(ar + count - 1);

}

int Expandable::at(int index) {

	if (index < 0 || index > count - 1) {
		return -1;
	}
	return *(ar + index);
}