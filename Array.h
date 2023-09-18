#ifndef _ARRAY
#define _ARRAY

#include <iostream>
using namespace std;

// ����� ��� ������ � ������� � ���������� ������� ���������� 
class ArrayException {};



// ��������� ������
const int DEFAULT_CAPACITY = 10;

// ����� ��� ���������� �������
class Array{

	// ��������� �� ������ � �������. ������
int* ptr;
// ������� ������
int size;
// �����������
int capacity;


// ����� ��������� ������������
public:
	//
	bool isFail;

	// ����������� � ���������� ���������� �������
	explicit Array(int startCapacity = DEFAULT_CAPACITY);

	// ����������
	~Array();

	// ����������� �����������
	Array(const Array& arr);

	// �������� ������������
	Array& operator = (const Array& arr);


	// ������ � ������ ��������� �������
	int& operator [](int index);

	// ������� �������� ������ ������� 
	void insert(int index, int elem);

	// ������� �������� � ����� �������
	void insert(int elem);

	// ���������� ������� �������
	void increaseCapacity(int newCapacity);

	// �������� ��������
	void remove(int index);


// ������ �������

	// �������� ������ �������
	int getSize() const;

	// ������ �������
	friend ostream& operator <<(ostream& out, const Array& arr);



// ����� ����������� ������������
private:

};



#endif