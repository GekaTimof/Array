#include <iostream>
#include "Array.h"
#include <time.h>

using namespace std;

// Start program hear
int main(void) {
	setlocale(LC_ALL, "Russian");

	// Тестирование 2

	int k = 2;

	int args[7] = { 1000, 5000, 10000, 50000, 100000, 500000, 1000000 };
	for (int test = 0; test < 7; test++) {
		int N = args[test];

		// заполняем список
		Array arr(N);
		for (int i = 1; i <= N; i++) {
			arr.insert(i);
		}
		
		clock_t tStart = clock();
		arr.Iosiph(k);
		double time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
		cout << N << "	" << arr[0] << "	" << time << '\n';
	}



	//// Тестирование 1
	//Array arr(4);
	//for (int i = 0; i < 4; i++)
	//	arr.insert(i + 1);
	//cout << arr << endl;

	//for (int i = 0; i < 8; i += 2)
	//	arr.insert(10 + i, i);
	//cout << arr << endl;

	//for (int i = 1; i < 8; i += 2)
	//	arr[i] = 20 + i;
	//cout << arr << endl;

	//for (int i = 6; i >= 0; i -= 3)
	//	arr.remove(i);
	//cout << arr << endl;


}