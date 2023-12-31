#include <iostream>
#include "Array.h"

using namespace std;

// �����������, ���� ������� (��������) Array ��������
Array::Array(int startCapacity) {
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}


// ����������
Array::~Array() {
	delete[] ptr;
}


// ����������� �����������
Array::Array(const Array& arr){
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}


// �������� ������������
Array& Array::operator = (const Array& arr) {
	if (this == &arr)
		return *this;
	if (capacity != arr.capacity){
		delete[] ptr;
		ptr = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
	return *this;
}


// �������� ����������
int& Array::operator [](int index) {
	if (index >= size || index < 0)
		throw ArrayException(); // ���������� - ����������� ������
	else
		return ptr[index];
}


// ������� �������� ������ ������� 
void Array::insert(int elem, int index){
	if (index < 0 || index > size)
		throw ArrayException();

	if (size == capacity)
		// �������� �������, ������������� ���������� ������
		increaseCapacity(size + 1);

	// ���� index==size, ���� ���� �� ���������� �� ����
	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	size++;
	ptr[index] = elem;
}

// ������� �������� � ����� �������
void Array::insert(int elem){
 insert(elem, size);
}


// ���������� ������� �������
void Array::increaseCapacity(int newCapacity) {
	capacity = newCapacity < capacity * 2 ?
		capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}


// �������� ��������
void Array::remove(int index){
	if (index < 0 || index >= size)
		throw ArrayException();
	for (int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];
	ptr[size - 1] = 0;
	size--;
}


// �������� ������ �������
int Array::getSize() const{
	return size;
}


// ������ �������
ostream& operator <<(ostream& out, const Array& arr){
	out << "Total size: " << arr.size << endl;
	for (int i = 0; i < arr.size; i++)
		out << arr.ptr[i] << " ";
	return out;
}


// ������� ��� ������ ������ �����
void Array::Iosiph(int k) {
	if (k < 1) {
		cout << "Error";
	}
	else {
		// ����� ����� ������
		int pos = k - 1;

		// ������� �������� �� ������
		while (this->getSize() > 1) {
			// ������� �������
			this->remove(pos);
			//  ������ ���
			pos += k - 1;
			// �������� ����
			while (pos >= this->getSize()) {
				pos = pos - this->getSize();
			}
		}
	}
}
