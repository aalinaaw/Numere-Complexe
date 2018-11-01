
#pragma once
class ComplexNumber
{
public:
	void set_real(double);
	double get_real();
	void set_imaginary(double);
	double get_imaginary();
	ComplexNumber() { m_real = 0; m_imaginary = 0; }
private:
	double m_real, m_imaginary;
};

