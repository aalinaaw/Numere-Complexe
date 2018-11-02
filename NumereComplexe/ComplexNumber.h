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
	
private:
	double m_real, m_imaginary;
};

