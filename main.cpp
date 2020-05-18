/*
    Title:      Main.cpp
    Purpose:    Implement recursive functions
    Author:     Dr. Arias / Rami Isaac
    Date:       May 17, 2020
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

using namespace std;

// Functions
unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
size_t MinimumPosition(const int array[], size_t size);
size_t MaximumPosition(const int array[], size_t size);
void SelectionSort(int array[], size_t size);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}


	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}

	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}
	return 0;
}

/*
 * Fibonacci()
 *
 * This is a recursive function that calculates
 * the nth number in the Fibonacci Sequence
 * @param unsigned int n
 * @returns nth number in sequence
 */
unsigned long long int Fibonacci(unsigned int n){
    // Base Case
    if (n <= 1)
        return n;
    // Find nth number in sequence
    return Fibonacci(n-1) + Fibonacci(n-2);
}

/*
 * MinimumPosition()
 *
 * This is a recursive function that finds the
 * position of the minimum element in an array
 * @param const int array[], size_t size
 * @returns position of min element in arr
 */
size_t MinimumPosition(const int array[], size_t size) {
    // Base Case
    if (size <= 1)
        return 0;

    // Call MinimumPosition() for min index
    int i = MinimumPosition(array, --size);

    // Return min index
    return array[size] < array[i] ? size : i;
}

/*
 * MaximumPosition()
 *
 * This is a recursive function that finds the
 * position of the maximum element in an array
 * @param const int array[], size_t size
 * @returns position of max element in arr
 */
size_t MaximumPosition(const int array[], size_t size) {
    // Base Case
    if (size <= 1)
        return 0;

    // Call MaximumPosition() for max index
    int i = MaximumPosition(array, --size);

    // Return max index
    return array[size] > array[i] ? size : i;
}

/*
 * SelectionSort()
 *
 * This is a recursive function that sorts
 * an array using selection sort algorithm
 * @param int array[], size_t size
 * @returns -
 */
void SelectionSort(int array[], size_t size){
    // Find index of largest element
    int maxIndex = MaximumPosition(array, size);

    // Swap
    int temp = array[size-1];
    array[size-1] = array[maxIndex];
    array[maxIndex] = temp;

    if (size > 1) {
        // Call SelectionSort()
        SelectionSort(array, --size);
    }
}

/*
 * PrintReverseString()
 *
 * This is a recursive function that takes in
 * a string and outputs the string in reverse
 * @param const string& str, ostream& output
 * @returns -
 */
void PrintReverseString(const string& str, ostream& output) {
    size_t size = str.size(); // Find size of str

    if (size == 1)
        output << str; // Output str if not long enough to reverse
    else {
        // Call PrintReverseString(), output reversed string
        PrintReverseString(str.substr(0, size - 1), output << str[size - 1]);
    }
}