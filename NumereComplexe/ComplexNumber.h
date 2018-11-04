#pragma once
#include <string>
#include <cstring>
#include <math.h>

class ComplexNumber
{
public:
	//constructors
	ComplexNumber(double real = 0, double imaginary = 0);
	ComplexNumber(std::string);
	ComplexNumber(const ComplexNumber &);

	//setters and getters
	void set_real(const double&);  
	double get_real();
	void set_imaginary(const double&);
	double get_imaginary();
	
	//unary operators
	ComplexNumber operator+();
	ComplexNumber operator-();

	//binary operators
	friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator+(double, const ComplexNumber&);
	friend ComplexNumber operator+(const ComplexNumber&, double);
	
	friend ComplexNumber operator-(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator-(double, const ComplexNumber&);
	friend ComplexNumber operator-(const ComplexNumber&, double);

	friend ComplexNumber operator*(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator*(double, const ComplexNumber&);
	friend ComplexNumber operator*(const ComplexNumber&, double);

	friend ComplexNumber operator/(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator/(double, const ComplexNumber&);
	friend ComplexNumber operator/(const ComplexNumber&, double);

	friend ComplexNumber operator^(const ComplexNumber&, int);

	//relational operators
	friend bool operator==(const ComplexNumber&, const ComplexNumber&);
	friend bool operator==(double, const ComplexNumber&);
	friend bool operator==(const ComplexNumber&, double);

	friend bool operator!=(const ComplexNumber&, const ComplexNumber&);
	friend bool operator!=(double, const ComplexNumber&);
	friend bool operator!=(const ComplexNumber&, double);

	//compound operators
	ComplexNumber& operator=(const ComplexNumber &);
	ComplexNumber& operator=(const double &);

	ComplexNumber& operator+=(const ComplexNumber &);
	ComplexNumber& operator+=(const double &);

	ComplexNumber& operator-=(const ComplexNumber &);
	ComplexNumber& operator-=(const double &);

	ComplexNumber& operator*=(const ComplexNumber &);
	ComplexNumber& operator*=(const double &);

	ComplexNumber& operator/=(const ComplexNumber &);
	ComplexNumber& operator/=(const double &);

	ComplexNumber Conjugate();

	//friend functions
	//double square_root();

private:
	double m_real, m_imaginary;
};

