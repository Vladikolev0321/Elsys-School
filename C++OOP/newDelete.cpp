#include <iostream>
using namespace std;

class Vector
{
	int *arr;
	int capacity;
	int size;

public:
	Vector()
	{
		this->arr = new int[1];
		this->size = 0;
		this->capacity = 1;
	}
	void add_element(int value)
	{
		if (this->capacity == this->size) {
			int* temp = new int[this->capacity * 2];
			for (int i = 0; i < this->size; i++)
			{
				temp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp;
			this->capacity *= 2;
		}
		this->arr[size] = value;
		this->size++;
	}
	void pop()
	{
		int* tmp = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			tmp[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = tmp;
		this->size--;
	}
	void printElements()
	{
		cout << "Printing elements:" << endl;
		for (int i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << endl;
		}
	}
	int getSize() {
		return this->size;
	}
	int getCapacity() {
		return this->capacity;
	}
	~Vector()
	{
		delete[] this->arr;
	}
};

int main()
{
	Vector vector;
	vector.add_element(1);
	vector.add_element(2);
	vector.add_element(3);
	vector.add_element(4);

	vector.pop();

	vector.printElements();


	return 0;
}
