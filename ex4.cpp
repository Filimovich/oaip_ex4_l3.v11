#include <iostream>
#include <cmath>

using namespace std;

int calculate_ranks(unsigned int num)
{
	int i;

	for (i = 0; num > 0; ++i) {
		num /= 10;
	}

	return (i);
}

double* createArray(unsigned int num)
{
	int arraySize = calculate_ranks(num);
	int numRank = 1;
	double *array = new double[arraySize];

	array[0] = arraySize;

	while (arraySize > 0) {
		array[arraySize--] = pow(((num % 10) * numRank), 2);
		numRank *= 10;
		num /= 10;
	}

	return (array);
}

int main()
{
	unsigned int number = 1242323344;
	double *arrayPtr = createArray(number);

	for (int i = arrayPtr[0]; i > 0; i--) {
		cout << *arrayPtr - i + 1 << " rank of the given number: " << arrayPtr[i] << endl;
	}

	return (0);
}

/*
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
	int *array = createArray(number);

	for (int i = 1; i <= array[0]; i++) {
		cout << array[i] << endl;
	}

	return (0);
}
*/