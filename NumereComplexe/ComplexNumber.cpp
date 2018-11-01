#include "pch.h"
#include "ComplexNumber.h"

void ComplexNumber::set_real(const double& real)
{
	m_real = real;
}

double ComplexNumber::get_real()
{
	return m_real;
}

void ComplexNumber::set_imaginary(const double & imaginary)
{
	m_imaginary = imaginary;
}

double ComplexNumber::get_imaginary()
{
	return m_imaginary;
}
