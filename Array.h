#ifndef _ARRAY
#define _ARRAY

#include <iostream>
using namespace std;

// Класс без данных и методов – простейший вариант исключения 
class ArrayException {};



// дефолтный размер
const int DEFAULT_CAPACITY = 10;

// класс для реализации вектора
class Array{

	// Указатель на массив в динамич. памяти
int* ptr;
// Текущий размер
int size;
// Вместимость
int capacity;


// часть доступная пользователю
public:
	//
	bool isFail;

	// конструктор с установкой дефолтного размера
	explicit Array(int startCapacity = DEFAULT_CAPACITY);

	// деструктор
	~Array();

	// конструктор копирования
	Array(const Array& arr);

	// оператор присваивания
	Array& operator = (const Array& arr);


	// Чтение и запись элементов массива
	int& operator [](int index);

	// Вставка элемента внутрь массива 
	void insert(int index, int elem);

	// Вставка элемента в конец массива
	void insert(int elem);

	// Увеличение предела размера
	void increaseCapacity(int newCapacity);

	// Удаление элемента
	void remove(int index);


// другие функции

	// Получить размер массива
	int getSize() const;

	// Выввод массива
	friend ostream& operator <<(ostream& out, const Array& arr);



// часть недоступная пользователю
private:

};



#endif