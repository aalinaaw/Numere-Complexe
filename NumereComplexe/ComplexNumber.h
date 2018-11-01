#pragma once
#include <string>
#include <cstring>

class ComplexNumber
{
public:
	void set_real(const double&);
	double get_real();
	void set_imaginary(const double&);
	double get_imaginary();
	ComplexNumber(double real = 0, double imaginary = 0);
	ComplexNumber(std::string);
private:
	double m_real, m_imaginary;
};

