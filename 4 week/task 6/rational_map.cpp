#include <iostream>
#include <numeric>
#include <math.h>
#include <map>
#include <set>
#include <vector>
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
			this->num = numerator / abs(gcd(numerator, denominator));
			this->den = denominator / abs(gcd(numerator, denominator));
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

bool operator<(const Rational& first, const  Rational& second) {
	return first.Numerator() * second.Denominator() < second.Numerator() * first.Denominator();
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

	{
		set<Rational> rationals;
		rationals.insert(Rational(1, 2));
		rationals.insert(Rational(1, 3));

		map<Rational, string> name;
		name[Rational(1, 2)] = "одна вторая";
	}

    cout << "OK" << endl;
    return 0;
}
