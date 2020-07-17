#pragma once
class Equation
{
public:
	Equation(double a, double b, double c);
	double get_a() { return a; };
	double get_b() { return b; };
	double get_c() { return c; };
	void set_a(double a) { this->a = a; };
	void set_b(double b) { this->b = b; };
	void set_c(double c) { this->c = c; };

private:
	double a;
	double b;
	double c;
};

