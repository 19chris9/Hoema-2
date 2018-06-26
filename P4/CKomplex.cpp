#include "CKomplex.h"
using namespace std;

CKomplex CKomplex::operator+(const CKomplex & c)
{
	CKomplex ergebnis;
	ergebnis.a = this->a + c.a;
	ergebnis.b = this->b + c.b;
	return ergebnis;
}

CKomplex CKomplex::operator-(const CKomplex & c)
{
	CKomplex ergebnis;
	ergebnis.a = this->a - c.a;
	ergebnis.b = this->b - c.b;
	return ergebnis;
}

CKomplex CKomplex::operator*(const CKomplex & c)
{
	CKomplex ergebnis;
	ergebnis.a = (this->a * c.a) + (this->b * c.b * -1);
	ergebnis.b = (this->b * c.a) + (this->a * c.b);
	return ergebnis;
}

CKomplex CKomplex::operator*(const double lambda)
{
	CKomplex ergebnis;
	ergebnis.a = this->a * lambda;
	ergebnis.b = this->b * lambda;
	return ergebnis;
}
