#pragma once
#include <string>
#include <cstring>

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
	/*friend ComplexNumber operator+();
	friend ComplexNumber operator-();*/

	//binary operators
	friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator+(double, const ComplexNumber&);
	friend ComplexNumber operator+(const ComplexNumber&, double);
	
	friend ComplexNumber operator-(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator-(double, const ComplexNumber&);
	friend ComplexNumber operator-(const ComplexNumber&, double);

private:
	double m_real, m_imaginary;
};

