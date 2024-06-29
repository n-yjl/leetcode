#include <iostream>
#include <cmath>
using namespace std;

int main(int n) {
	int input = n;
	int prevdigits;
	int logten;
	int product = 1;										// initialize multiplication with 1
	int sum = 0;											// initialize addition with 0

	logten = log10(input);									// use log10 for integer length (logten + 1)
	int* result = new int[logten + 1];						// allocate memory for array

	for (int i = 0; i < (logten + 1); i++) {				// repeated code for each digit
		i == 0												// if/else loop for first iteration
			? result[i] = input / pow(10, (logten - i))		// divide input by (10^highest digit)
			: result[i] = (input / pow(10, (logten - i))	// divide input by (10^highest digit - current iteration)
				- prevdigits * 10);							// subtract by remainder if it exists (comes after first iteration)
		prevdigits = input / pow(10, (logten - i));			// define remainder
	}

	for (int i = 0; i < (logten + 1); i++) {
		product *= result[i];								// multiply each digit
		sum += result[i];									// add each digit
	}
	
	delete[] result;										// deallocate memory
	return (product - sum);
}