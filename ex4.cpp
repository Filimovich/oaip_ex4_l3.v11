#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

double* create_array(unsigned num);
unsigned digit_input();
int calculate_ranks(unsigned num);
void input_error(void);
void inputOutOfRange_error();

int main()
{
	unsigned number = digit_input();
	cout << number << endl;
	double *arrayPtr = create_array(number);

	for (int i = arrayPtr[0]; i > 0; i--) {
		cout << *arrayPtr - i + 1 << " rank of the given number: " << arrayPtr[i] << endl;
	}

	return (0);
}

unsigned digit_input()
{
	double digit;
	while(1) {
		string str;
		size_t pos{};
		cin >> str;
		try {
			digit = stod(str, &pos);
			if (cin && pos == str.size())
				break;
			else
				input_error();
		}
		catch (invalid_argument const&) {
			input_error();
		}
		catch (out_of_range const&) {
			inputOutOfRange_error();
		}
	}

	if (fabs(digit) > UINT_MAX) {
		inputOutOfRange_error();
		return (digit_input());
	}

	if (digit < 0)
		return (fabs(digit));

	return (digit);
}

void input_error(void)
{
	cout << "Input data type error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

void inputOutOfRange_error()
{
	cout << "Out of range error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

int calculate_ranks(long num)
{
	int i;

	for (i = 0; num > 0; ++i) {
		num /= 10;
	}

	return (i);
}

double* create_array(long num)
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
