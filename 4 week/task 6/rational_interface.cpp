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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
