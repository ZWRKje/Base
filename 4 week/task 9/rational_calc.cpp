#include <iostream>
#include <exception>
#include <iostream>
#include <numeric>
#include <math.h>

using namespace std;

class Rational {
public:
	Rational() {

		this->num = 0;
		this->den = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
		if (numerator < 0 && denominator > 0) {
			this->num = numerator / abs(gcd(numerator, denominator));
			this->den = denominator / abs(gcd(numerator, denominator));
		}
		else if (numerator > 0 && denominator < 0) {
			this->num = -1 * numerator / abs(gcd(numerator, denominator));
			this->den = -1 * denominator / abs(gcd(numerator, denominator));
		}
		else {
			this->num = abs(numerator / abs(gcd(numerator, denominator)));
			this->den = abs(denominator / abs(gcd(numerator, denominator)));
		}


	}

	int Numerator() const {
		return this->num;

	}

	int Denominator() const {

		return this->den;
	}

	void changeNum(const int& value) {
		this->num = value;
	}

	void changeDen(const int& value) {
		this->den = value;
	}
private:

	int num;
	int den;
};


Rational operator/(const Rational& first, const Rational& second) {

	int num = 0;
	int den = 1;
	num = first.Numerator() * second.Denominator();
	den = first.Denominator() * second.Numerator();
	if (den == 0) {
		throw domain_error("Division by zero");
	}
	Rational rez{ num, den };
	return rez;
}

Rational operator*(const Rational& first, const Rational& second) {
	Rational rez;
	int num = 0;
	int den = 1;
	num = first.Numerator() * second.Numerator();
	den = first.Denominator() * second.Denominator();
	rez.changeNum(num / gcd(num, den));
	rez.changeDen(den / gcd(num, den));
	return rez;
}



Rational operator-(const Rational& first, const Rational& second) {
	Rational rez;
	int num = 0;
	int den = 1;
	num = first.Numerator() * second.Denominator() - second.Numerator() * first.Denominator();
	den = first.Denominator() * second.Denominator();
	rez.changeNum(num / gcd(num, den));
	rez.changeDen(den / gcd(num, den));
	return rez;
}
Rational operator+(const Rational& first, const Rational& second) {
	Rational rez;
	int num;
	int den;
	num = first.Numerator() * second.Denominator() + second.Numerator() * first.Denominator();
	den = first.Denominator() * second.Denominator();
	rez.changeNum(num / gcd(num, den));
	rez.changeDen(den / gcd(num, den));
	return rez;
}

ostream& operator<<(ostream& stream, const Rational& data) {
	stream << data.Numerator() << "/" << data.Denominator();
	return stream;
}

Rational todo(const Rational& num1, const Rational& num2, const char& action) {
	Rational rez;

	switch (action)
	{
	case '+':
		rez = num1 + num2;
		return rez;
		break;
	case '-':
		rez = num1 - num2;
		return rez;
		break;
	case '*':
		rez = num1 * num2;
		return rez;
		break;
	case '/':
		rez = num1 / num2;
		return rez;
		break;
	default:
		break;
	}
}

Rational inputNum() {
	int a = 0;
	int b = 0;

	cin >> a;
	cin.ignore(1);
	cin >> b;
	Rational num{ a,b };
	return num;
}
int main() {
	char action;
	Rational num1;
	Rational num2;
	try {
		num1 = inputNum();

		cin.ignore(1);
		cin >> action;
		cin.ignore(1);

		num2 = inputNum();
	}
	catch (invalid_argument& e) {
		cout << e.what();
		return -1;
	}
	try {
		Rational rez;
		rez = todo(num1, num2, action);
		cout << rez;
	}
	catch (domain_error& e) {
		cout << e.what();
		return -2;
	}
	return 0;
}
