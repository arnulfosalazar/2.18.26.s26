#include <iostream>



class Expandable {
public:
	Expandable(); //constructor
	~Expandable(); //destructor

	//insertion operations
	void push_back(int value); //insert to the right of existing values
	void insert(int index, int value); //inserts at index

	void print(); //prints elements from left to right

	// update operation
	void update(int index, int value);

	//deletion operations
	int pop_back(); //deletes and returns the rightmost value
	int erase(int index); //deletes the value at index and returns it


private:
	int* ar; //pointer to store the starting address of the array
	int size; //size of the array (total number of elements that it can hold)
	int count; //number of elements currently in the array

};
