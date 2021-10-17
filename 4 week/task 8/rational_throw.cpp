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
            throw invalid_argument("Zero denominator");
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

private:

    int num;
    int den;
};

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(const Rational& first, const Rational& second) {
    
    int num = 0;
    int den = 1;
    num = first.Numerator() * second.Denominator();
    den = first.Denominator() * second.Numerator();
    if (den == 0) {
        throw domain_error("Zero denominator");
    }
    Rational rez{ num, den };
    return rez;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
