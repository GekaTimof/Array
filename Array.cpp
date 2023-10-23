#include <iostream>
#include "Array.h"

using namespace std;

// Конструктор, ввод размера (создание) Array элемента
Array::Array(int startCapacity) {
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}


// Деструктор
Array::~Array() {
	delete[] ptr;
}


// Конструктор копирования
Array::Array(const Array& arr){
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}


// Оператор присваивания
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


// Оператор индексации
int& Array::operator [](int index) {
	if (index >= size || index < 0)
		throw ArrayException(); // Исключение - некоректные данные
	else
		return ptr[index];
}


// Вставка элемента внутрь массива 
void Array::insert(int elem, int index){
	if (index < 0 || index > size)
		throw ArrayException();

	if (size == capacity)
		// Закрытая функция, увеличивающая предельный размер
		increaseCapacity(size + 1);

	// Если index==size, этот цикл не выполнится ни разу
	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	size++;
	ptr[index] = elem;
}

// Вставка элемента в конец массива
void Array::insert(int elem){
 insert(elem, size);
}


// Увеличение предела размера
void Array::increaseCapacity(int newCapacity) {
	capacity = newCapacity < capacity * 2 ?
		capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}


// Удаление элемента
void Array::remove(int index){
	if (index < 0 || index >= size)
		throw ArrayException();
	for (int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];
	ptr[size - 1] = 0;
	size--;
}


// Получить размер массива
int Array::getSize() const{
	return size;
}


// Выввод массива
ostream& operator <<(ostream& out, const Array& arr){
	out << "Total size: " << arr.size << endl;
	for (int i = 0; i < arr.size; i++)
		out << arr.ptr[i] << " ";
	return out;
}


// функция для задачи Иосифа Флави
void Array::Iosiph(int k) {
	if (k < 1) {
		cout << "Error";
	}
	else {
		// задаём точку старта
		int pos = k - 1;

		// удаляем элементы из списка
		while (this->getSize() > 1) {
			// удаляем элемент
			this->remove(pos);
			//  делаем шаг
			pos += k - 1;
			// проверка шага
			while (pos >= this->getSize()) {
				pos = pos - this->getSize();
			}
		}
	}
}
