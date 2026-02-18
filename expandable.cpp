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

	if (count == size) {
		expand();
	}
}