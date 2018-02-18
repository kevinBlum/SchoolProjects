#include <iostream>
#include <ctime>
#include <ratio>
#include <conio.h>
#include <cmath>

using namespace std;

std::clock_t start;

extern "C" void _asmCollatz();
extern "C" void _asmSieve();

extern "C" double _getDouble() {
	double d;
	std::cin >> d;
	return d;
}

extern "C" int _getInt() {
	int i;
	std::cin >> i;
	return i;
}

extern "C" void _printString(char* s) {
	std::cout << s;
	return;
}

extern "C" void _printDouble(double d) {
	std::cout << d << std::endl;
}

extern "C" void _printInt(int i) {
	std::cout << i << std::endl;
}