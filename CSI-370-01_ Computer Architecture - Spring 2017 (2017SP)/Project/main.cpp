#include "functions.h"

// Clock Functions
extern "C" void _clockStart() {
	start = clock();
}

extern "C" void _clockEnd() {
	double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time: " << duration << " seconds\n";
}

// C++ implementation of Sieve of Eratosthenes
extern "C" void sieveEra() {
	_clockStart();
	int n = 10000;
	std::cout << "Primes below 1000: " << n << std::endl;

	char *prime = new char[n + 1];
	int p = 2;
	std::fill_n(prime, n, true);

	for (p; p*p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p*p; i <= n; i += p)
				prime[i] = false;
		}
	}
	_clockEnd();
	
	for (p = p + (1 - (p % 2)); p <= n; p += 2) {
		if (prime[p])
		std::cout << p << " ";
	}
	
	cout << endl;

}

// C++ implementation of Collatz Conjecture
extern "C" void _collatz() {

	int collatz;
	int collatzCounter = 0;
	cout << "Input integer for c++ collatz: \n";
	cin >> collatz;

	_clockStart();

	while (collatz != 1) {

		if (collatz % 2 == 0) {
			collatz = collatz / 2;
			collatzCounter++;
		}
		else {
			collatz = 3 * collatz + 1;
			collatzCounter++;
		}
	}
	cout << "Input reached one after step: " << collatzCounter << endl;
	_clockEnd();


}

// Main stub driver
int main() {

	int userInput;
	bool menuLoop = true;

	// Main loop
	while (menuLoop) {
		cout << "Math Functions\n" << "1. Collatz Assembly\n" <<  "2. Collatz C++\n" << "3. Sieve of Eratosthenes Assembly\n" 
			 << "4. Sieve of Eratosthenes C++\n" << "0. Exit Program\n";
		cin >> userInput;

		if (cin.fail() || userInput < 0 || userInput > 4) {
			cin.clear();
			cin.ignore();
			cout << "Invalid input\n";
		}
		else {
			switch (userInput) {
			case 0:
				menuLoop = false;
				break;
			case 1:
				_asmCollatz();
				break;
			case 2:
				_collatz();
				break;
			case 3:
				_asmSieve();
				break;
			case 4:
				sieveEra();
				break;
			}
		}
	}

	return 0;
}