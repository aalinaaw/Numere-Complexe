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

ComplexNumber::ComplexNumber(double real, double imaginary) :
	m_real(real),
	m_imaginary(imaginary)
{
}

ComplexNumber::ComplexNumber(std::string string)
{
	m_real = 0;
	m_imaginary = 0;
	int sign = 1;
	bool has_real = true, has_sign = false, has_imaginary = false;
	if (string[0] == '-')
	{
		sign = -1;
		has_sign = true;
	}
	if (string[0] == 'i' || string[1] == 'i')
	{
		has_real = false;
		has_imaginary = true;
	}
	int start_pos, end_pos;
	if (has_real == true)
	{
		if (has_sign)
			start_pos = 1;
		else
			start_pos = 0;

		end_pos = string.length();
		for (int i = start_pos + 1; i < string.length(); i++)
		{
			if (strchr("0123456789.", string[i]) == NULL)
			{
				end_pos = i;
				break;
			}
		}

		m_real = sign * std::stod(string.substr(start_pos, end_pos - start_pos));

	}

	if (has_real && end_pos < string.length())
	{
		if (string[end_pos] == '-')
			sign = -1;
		else
			sign = 1;
		has_imaginary = true;
	}

	if (has_imaginary)
	{
		if (!has_real)
		{
			if (has_sign)
				start_pos = 3;
			else
				start_pos = 2;
		}
		else
			start_pos = end_pos + 3;
		m_imaginary = sign * std::stod(string.substr(start_pos, string.length()-start_pos));
	}

}
