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

ComplexNumber ComplexNumber::operator+()
{
	ComplexNumber c(*this);
	return c;
}

ComplexNumber ComplexNumber::operator-()
{
	ComplexNumber c(*this);
	c.m_real = -c.m_real;
	c.m_imaginary = -c.m_imaginary;
	return c;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber & a)
{
	this->m_real = a.m_real;
	this->m_imaginary = a.m_imaginary;
	return *this;
}

ComplexNumber & ComplexNumber::operator=(const double & a)
{
	this->m_real = a;
	this->m_imaginary = 0;
	return *this;
}

ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & a)
{
	*this = *this + a;
	return *this;
}

ComplexNumber & ComplexNumber::operator+=(const double & a)
{
	this->m_real += a;
	return *this;
	
}

ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & a)
{
	*this = *this - a;
	return *this;
}

ComplexNumber & ComplexNumber::operator-=(const double & a)
{
	this->m_real -= a;
	return *this;
}

ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & a)
{
	*this = *this * a;
	return *this;
}

ComplexNumber & ComplexNumber::operator*=(const double & a)
{
	this->m_real *= a;
	this->m_imaginary *= a;
	return *this;
}

ComplexNumber & ComplexNumber::operator/=(const ComplexNumber & a)
{
	*this = *this / a;
	return *this;
}

ComplexNumber & ComplexNumber::operator/=(const double & a)
{
	this->m_real /= a;
	this->m_imaginary /= a;
	return *this;
}

ComplexNumber::operator std::string() const
{
	ComplexNumber c(*this);
	return c.ToString();
}

std::istream & operator>>(std::istream & stream, ComplexNumber & z)
{
	std::string str;
	char ch; stream.get(ch);
	while (ch != '\n' && !stream.eof()) {
		str += ch;
		stream.get(ch);
	}
	ComplexNumber temp(str);
	z.m_real = temp.m_real;
	z.m_imaginary = temp.m_imaginary;

	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ComplexNumber & z)
{
	ComplexNumber temp(z);
	stream << temp.ToString();
	return stream;
}



ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber c(*this);
	c.m_imaginary = -c.m_imaginary;
	return c;
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

ComplexNumber::ComplexNumber(const ComplexNumber & z)
{
	m_real = z.m_real;
	m_imaginary = z.m_imaginary;
}


ComplexNumber operator+(const ComplexNumber & a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a.m_real + b.m_real;
	c.m_imaginary = a.m_imaginary + b.m_imaginary;
	return c;
}

ComplexNumber operator+(double a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a + b.m_real;
	c.m_imaginary = b.m_imaginary;
	return c;
}

ComplexNumber operator+(const ComplexNumber & a, double b)
{
	ComplexNumber c;
	c.m_real = a.m_real + b;
	c.m_imaginary = a.m_imaginary;
	return c;
}

ComplexNumber operator-(const ComplexNumber & a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a.m_real - b.m_real;
	c.m_imaginary = a.m_imaginary - b.m_imaginary;
	return c;
}

ComplexNumber operator-(double a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a - b.m_real;
	c.m_imaginary = -b.m_imaginary;
	return c;
}

ComplexNumber operator-(const ComplexNumber & a, double b)
{
	ComplexNumber c;
	c.m_real = a.m_real - b;
	c.m_imaginary = a.m_imaginary;
	return c;
}

ComplexNumber operator*(const ComplexNumber & a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a.m_real * b.m_real - a.m_imaginary * b.m_imaginary;
	c.m_imaginary = a.m_real * b.m_imaginary + a.m_imaginary * b.m_real;
	return c;
}

ComplexNumber operator*(double a, const ComplexNumber & b)
{
	ComplexNumber c;
	c.m_real = a * b.m_real;
	c.m_imaginary = a * b.m_imaginary;
	return c;
}

ComplexNumber operator*(const ComplexNumber & a, double b)
{
	ComplexNumber c;
	c.m_real = a.m_real * b;
	c.m_imaginary = a.m_imaginary * b;
	return c;
}

ComplexNumber operator/(const ComplexNumber & a, const ComplexNumber & b)
{
	ComplexNumber c, tempa(a), tempb(b);
	tempa = tempb.Conjugate() * tempa;
	tempb = tempb.Conjugate() * tempb;
	c.m_real = tempa.m_real / tempb.m_real;
	c.m_imaginary = tempa.m_imaginary / tempb.m_real;
	return c;
}

ComplexNumber operator/(double a, const ComplexNumber & b)
{
	ComplexNumber c, tempb(b), tempa(a, 0);
	tempa = tempa * tempb.Conjugate();
	tempb = tempb * tempb.Conjugate();
	c.m_real = tempa.m_real / tempb.m_real;
	c.m_imaginary = tempa.m_imaginary / tempb.m_real;
	return c;
}

ComplexNumber operator/(const ComplexNumber & a, double b)
{
	ComplexNumber c;
	c.m_real = a.m_real / b;
	c.m_imaginary = a.m_imaginary / b;
	return c;
}

ComplexNumber operator^(const ComplexNumber & a, int b)
{
	ComplexNumber c(a);
	if (b == 0)
	{
		c.m_real = 1;
		c.m_imaginary = 0;
		return c;
	}
	for (int i = 1; i < b; i++)
	{
		c = c * a;
	}
	return c;
}

bool operator==(const ComplexNumber & a, const ComplexNumber & b)
{
	if (a.m_real == b.m_real && a.m_imaginary == b.m_imaginary)
		return true;
	else
		return false;

}

bool operator==(double a, const ComplexNumber & b)
{
	if (a == b.m_real && b.m_imaginary == 0)
		return true;
	else
		return false;
	
}

bool operator==(const ComplexNumber & a, double b)
{
	if (a.m_real == b && a.m_imaginary == 0)
		return true;
	else
		return false;
	
}

 bool operator!=(const ComplexNumber & a, const ComplexNumber & b)
 {
	 if (a.m_real == b.m_real && a.m_imaginary == b.m_imaginary)
		 return false;
	 else
		 return true;
	 
 }

 bool operator!=(double a, const ComplexNumber & b)
 {
	 if (a == b.m_real && b.m_imaginary == 0)
		 return false;
	 else
		 return true;
 }

 bool operator!=(const ComplexNumber & a, double b)
 {
	 if (a.m_real == b && a.m_imaginary == 0)
		 return false;
	 else
		 return true;
 }

 double ComplexNumber::modulus() 
 {
	 return sqrt(this->m_real * this->m_real + this->m_imaginary * this->m_imaginary);
 }

 ComplexNumber ComplexNumber::square_root(const ComplexNumber & a, int k)
 {
	 ComplexNumber ca(a);
	 double phi = atan(a.m_imaginary / a.m_real), r = ca.modulus();
	 ComplexNumber z;
	 z.m_real = sqrt(r) * cos((phi + 2 * k * PI) / 2);
	 z.m_imaginary = sqrt(r) * sin((phi + 2 * k * PI) / 2);
	 return z;
 }

 std::string ComplexNumber::ToString()
 {
	 std::string str = "";
	 if (this->m_real != 0)
	 {
		 str += std::to_string(this->m_real);
	 }
	 if (this->m_imaginary != 0)
	 {
		 if (this->m_imaginary > 0)
		 {
			 if (this->m_real != 0)
			 {
				 str += "+i*";
			 }
			 else 
			 {
				 str += "i*";
			 }
			 str += std::to_string(this->m_imaginary);
		 }
		 else
		 {
			 str += "-i*";
			 str += std::to_string(abs(this->m_imaginary));
		 }
	 }
	 return str;
 }
 
 