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


bool operator==(const Rational& first, const  Rational& second) {
    if (first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator())
        return true;
    else
        return false;
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

Rational operator/(const Rational& first, const Rational& second) {

    int num = 0;
    int den = 1;
    num = first.Numerator() * second.Denominator();
    den = first.Denominator() * second.Numerator();
    Rational rez{ num, den };
    return rez;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
