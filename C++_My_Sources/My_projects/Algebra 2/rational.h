#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include <string>

class Rational {
private:
	int num, denum;
	void assign(const char *);
	void reduce();
	friend int a_bigger_b(const Rational &, const Rational &);

public:
	Rational();
//	Rational(const int a);
	Rational(const int num, const int denum = 1);
	Rational(const Rational &);
	int getNumerator() const;
	int getDenominator() const;
	operator std::string()const;
	friend Rational operator+(const Rational &, const Rational &);
	friend Rational operator+(const Rational &, const int &);
	friend Rational operator+(const int &, const Rational &);
	friend Rational operator-(const Rational &, const Rational &);
	friend Rational operator-(const Rational &, const int &);
	friend Rational operator-(const int &, const Rational &);
	friend Rational operator*(const Rational &, const Rational &);
	friend Rational operator*(const Rational &, const int &);
	friend Rational operator*(const int &, const Rational &);
	friend Rational operator/(const Rational &, const Rational &);
	friend Rational operator/(const Rational &, const int &);
	friend Rational operator/(const int &, const Rational &);
	Rational &operator=(const Rational &);
	Rational &operator=(const int &);
	Rational &operator+=(const Rational &);
	Rational &operator+=(const int &);
	Rational &operator-=(const Rational &);
	Rational &operator-=(const int &);
	Rational &operator*=(const Rational &);
	Rational &operator*=(const int &);
	Rational &operator/=(const Rational &);
	Rational &operator/=(const int &);
	friend bool operator>(const Rational &, const Rational &);
	friend bool operator>(const Rational &, const int &);
	friend bool operator>(const int &, const Rational &);
	friend bool operator>=(const Rational &, const Rational &);
	friend bool operator>=(const Rational &, const int &);
	friend bool operator>=(const int &, const Rational &);
	friend bool operator<(const Rational &, const Rational &);
	friend bool operator<(const Rational &, const int &);
	friend bool operator<(const int &, const Rational &);
	friend bool operator<=(const Rational &, const Rational &);
	friend bool operator<=(const Rational &, const int &);
	friend bool operator<=(const int &, const Rational &);
	friend bool operator==(const Rational &, const Rational &);
	friend bool operator==(const Rational &, const int &);
	friend bool operator==(const int &, const Rational &);
	friend bool operator!=(const Rational &, const Rational &);
	friend bool operator!=(const Rational &, const int &);
	friend bool operator!=(const int &, const Rational &);
	friend Rational operator-(const Rational &);
	friend Rational operator+(const Rational &);
	Rational &operator++();
	Rational &operator--();
};

int GCD(int a, int b);
int LCD(int a, int b);

#endif // RATIONAL_H_INCLUDED
