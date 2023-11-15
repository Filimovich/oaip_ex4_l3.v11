#include <iostream>
#include <cmath>

using namespace std;

int calculate_ranks(int num)
{
	int i;

	for (i = 0; num > 0; ++i) {
		num /= 10;
	}

	return (i);
}

int* createArray(int num)
{
	int arraySize;

	arraySize = calculate_ranks(num);

	int* array = new int[arraySize];

	for (int i = arraySize; i >= 1; i--) {
		array[i] = pow((num % 10), 2);
		num /= 10;
	}

	array[0] = arraySize;

	return (array);
}

int main()
{
	int number = 35412;
	int* array = createArray(number);

	for (int i = 1; i <= array[0]; i++) {
		cout << array[i] << endl;
	}

	return (0);
}
