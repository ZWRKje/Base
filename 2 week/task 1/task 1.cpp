#include <iostream>

int Factorial(int num) {
	int n = 1;
	if (num < 0)
		return 1;

	if (num > 1 && num != 0)
		n *= Factorial(num - 1);
	else
		return 1;

	return n *= num;
}

int main() {
	int num = 0;
	std::cin >> num;
	std::cout << Factorial(num);
	return 0;
}