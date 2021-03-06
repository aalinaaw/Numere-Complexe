#pragma once
#include <string>
#include <cstring>
#include <math.h>

#define PI 3.141592

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

	operator std::string() const;

	friend std::istream & operator>>(std::istream & stream, ComplexNumber &);
	friend std::ostream & operator<<(std::ostream & stream, const ComplexNumber &);

	ComplexNumber Conjugate();

	//friend functions
	double modulus();
	static ComplexNumber square_root(const ComplexNumber &, int);

	std::string ToString();



private:
	double m_real, m_imaginary;
};

