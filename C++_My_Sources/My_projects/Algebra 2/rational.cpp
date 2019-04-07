#include "rational.h"
#include "tostring.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int GCD(int a, int b){
    if ((a == 0) && (b == 0)) return 1;
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    while ((a != 0) && (b != 0)) {
        if (a>b) a=a-b; else
            b=b-a;
    }
    if (a == 0) return b;
    return a;
}

int LCD(int a, int b){
    return a*b/GCD(a,b);
}

void Rational::reduce(){
		int abs_p = abs(this->num);
		int abs_q = abs(this->denum);
		while (abs_p != 0 && abs_q != 0) {
			if (abs_p > abs_q) {
				abs_p = abs_p % abs_q;
			}
			else {
				abs_q = abs_q % abs_p;
			}
		}
		this->num /= abs_p + abs_q;
		this->denum /= abs_p + abs_q;
}

Rational::Rational() {
	this->num = 0;
	this->denum = 1;
}

/*
Rational::Rational(const int a){
num=a; denum=1;
}
*/

Rational::Rational(const int num, const int denum) {
	int sign = 1;
	if (num * denum < 0) {
		sign = -1;
	}
	int abs_p = abs(num);
	int abs_q = abs(denum);
	this->num = abs_p * sign;
	this->denum = abs_q;
	this->reduce();
}

Rational::Rational(const Rational &that) {
	this->num = that.num;
	this->denum = that.denum;
}

/*void Rational::assign(const char *string) {
	int p = 0;
	int i = 0;
	int sign = 1;
	while (string[i] != '/' && string[i] != 0) {
		if (string[i] == '-') {
			sign = -1;
		}
		else {
			p = p * 10 + string[i] - '0';
		}
		i++;
	}
	p *= sign;
	int q = 0;
	if (string[i] == 0) {
		q = 1;
	}
	else {
		i++;
		while (string[i] != 0) {
			q = q * 10 + string[i] - '0';
			i++;
		}
	}
	this->p = p;
	this->q = q;
}*/

int Rational::getNumerator() const {
	return this->num;
}

int Rational::getDenominator() const {
	return this->denum;
}

Rational::operator std::string()const{
	std::ostringstream oss;
	if (denum == 0) oss<<"Invalid"; else
	if (num == 0) oss<<" 0"; else
    if (denum == 1 && num>0) oss<<" "<<num; else
    if (denum == 1 && num<0) oss<<num;
    else
    if (num>0)
	oss <<" "<<num<<"/"<<denum;
	else
    oss <<" "<<num<<"/"<<denum;
	return oss.str();
}

Rational operator+(const Rational &a, const Rational &b) {
	Rational res;
	res.num = a.num * b.denum + a.denum * b.num;
	res.denum = a.denum * b.denum;
	res.reduce();
	return res;
}

Rational operator+(const Rational &a, const int &b) {
	return a + Rational(b);
}

Rational operator+(const int &a, const Rational &b) {
	return Rational(a) + b;
}

Rational operator-(const Rational &a, const Rational &b) {
	Rational res;
	res.num = a.num * b.denum - a.denum * b.num;
	res.denum = a.denum * b.denum;
	res.reduce();
	return res;
}

Rational operator-(const Rational &a, const int &b) {
	return a - Rational(b);
}

Rational operator-(const int &a, const Rational &b) {
	return Rational(a) - b;
}

Rational operator*(const Rational &a, const Rational &b) {
	Rational res;
	res.num = a.num * b.num;
	res.denum = a.denum * b.denum;
	res.reduce();
	return res;
}

Rational operator*(const Rational &a, const int &b) {
	return a * Rational(b);
}

Rational operator*(const int &a, const Rational &b) {
	return Rational(a) * b;
}

Rational operator/(const Rational &a, const Rational &b) {
    Rational res;
    if (a.denum==0) {cout<<"\n First argument is invalid, can't divide!\n"; res=0;} else
    if (b.num==0 || b==0) {cout<<"\n Second argument is zero - division by zero!\n"; res=0;} else {
	int sign = 1;
	if (a.num * b.num < 0) {
		sign = -1;
	}
	res.num = abs(a.num * b.denum) * sign;
	res.denum = abs(a.denum * b.num);
	res.reduce();
    }
	return res;
}

Rational operator/(const Rational &a, const int &b) {
	return a / Rational(b);
}

Rational operator/(const int &a, const Rational &b) {
	return Rational(a) / b;
}

Rational &Rational::operator=(const Rational &that) {
	this->num = that.num;
	this->denum = that.denum;
	return *this;
}

Rational &Rational::operator=(const int &that) {
	this->num = that;
	this->denum = 1;
	return *this;
}

Rational &Rational::operator+=(const Rational &that) {
	*this = *this + that;
	return *this;
}

Rational &Rational::operator+=(const int &that) {
	*this = *this + Rational(that);
	return *this;
}

Rational &Rational::operator-=(const Rational &that) {
	*this = *this - that;
	return *this;
}

Rational &Rational::operator-=(const int &that) {
	*this = *this - Rational(that);
	return *this;
}

Rational &Rational::operator*=(const Rational &that) {
	*this = *this * that;
	return *this;
}

Rational &Rational::operator*=(const int &that) {
	*this = *this * Rational(that);
	return *this;
}

Rational &Rational::operator/=(const Rational &that) {
	*this = *this / that;
	return *this;
}

Rational &Rational::operator/=(const int &that) {
	*this = *this / Rational(that);
	return *this;
}

int a_bigger_b(const Rational &a, const Rational &b) {
	int flag = 0;
	if (a.num * b.denum > a.denum * b.num) {
		flag = 1;
	}
	else if (a.num * b.denum == a.denum * b.num) {
		flag = 0;
	}
	else {
		flag = -1;
	}
	return flag;
}

bool operator>(const Rational &a, const Rational &b) {
	bool flag = false;
	if (a_bigger_b(a, b) == 1) {
		flag = true;
	}
	return flag;
}

bool operator>(const int &a, const Rational &b) {
	return Rational(a) > b;
}

bool operator>(const Rational &a, const int &b) {
	return a > Rational(b);
}

bool operator>=(const Rational &a, const Rational &b) {
	bool flag = false;
	if (a_bigger_b(a, b) >= 0) {
		flag = true;
	}
	return flag;
}

bool operator>=(const int &a, const Rational &b) {
	return Rational(a) >= b;
}

bool operator>=(const Rational &a, const int &b) {
	return a >= Rational(b);
}

bool operator<(const Rational &a, const Rational &b) {
	bool flag = false;
	if (a_bigger_b(a, b) == -1) {
		flag = true;
	}
	return flag;
}

bool operator<(const int &a, const Rational &b) {
	return Rational(a) < b;
}

bool operator<(const Rational &a, const int &b) {
	return a < Rational(b);
}

bool operator<=(const Rational &a, const Rational &b) {
	bool flag = false;
	if (a_bigger_b(a, b) <= 0) {
		flag = true;
	}
	return flag;
}

bool operator<=(const int &a, const Rational &b) {
	return Rational(a) <= b;
}

bool operator<=(const Rational &a, const int &b) {
	return a <= Rational(b);
}

bool operator==(const Rational &a, const Rational &b) {
    if (a.num==0 && b.num==0) return true;
	bool flag = false;
	if (a_bigger_b(a, b) == 0) {
		flag = true;
	}
	return flag;
}

bool operator==(const int &a, const Rational &b) {
	return Rational(a) == b;
}

bool operator==(const Rational &a, const int &b) {
	return a == Rational(b);
}

bool operator!=(const Rational &a, const Rational &b) {
	bool flag = false;
	if (a_bigger_b(a, b) != 0) {
		flag = true;
	}
	return flag;
}

bool operator!=(const int &a, const Rational &b) {
	return Rational(a) != b;
}

bool operator!=(const Rational &a, const int &b) {
	return a != Rational(b);
}

Rational operator-(const Rational &that) {
	Rational res(that);
	res.num *= -1;
	return res;
}

Rational operator+(const Rational &that) {
	Rational res(that);
	return res;
}

Rational &Rational::operator++() {
	this->num += this->denum;
	return *this;
}

Rational &Rational::operator--() {
	this->num -= this->denum;
	return *this;
}
