#pragma once
#include <math.h>
#include <vector>



class CKomplex
{
private:
	double a;
	double b;
public:
	CKomplex() : a(0), b(0) {};
	CKomplex(double a, double b) : a(a), b(b) {};
	CKomplex(double phi) : a(cos(phi)), b(sin(phi)) {};
	double re() { return a; };
	double im() { return b; };

	CKomplex operator + (const CKomplex & c);
	CKomplex operator - (const CKomplex & c);
	CKomplex operator * (const CKomplex & c);
	CKomplex operator * (const double lambda);

	double abs() { return sqrt(a * a + b * b); };
};