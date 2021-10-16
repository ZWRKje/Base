#include <iostream>
#include <numeric>
#include <math.h>
#include <sstream>
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

ostream& operator<<(ostream& stream, const Rational& data) {
    stream << data.Numerator() << "/" << data.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& data) {
    if (!stream.eof()) {
        int n = 0, m = 0;
        char a = ' ';
        if (stream.good()) {
            stream >> n;
        }
        if (stream.good()) {
            stream >> a;
        }
        if (stream.good()) {
            stream >> m;
        }

        if (n != 0 && m != 0 && a == '/') {
            data = Rational{ n, m };
        }
    }
    return stream;
}
int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
