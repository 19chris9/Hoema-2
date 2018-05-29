#include "CMyVector.h"

CMyVector::CMyVector()
{
}

CMyVector::CMyVector(int dim)
{
	dimension = dim;
	vec.resize(dim);
}

double CMyVector::laenge()
{
	double laenge = 0;
	for(int i = 0; i < dimension; i++) {
		laenge += vec[i] * vec[i];
	}
	return sqrt(laenge);
}

CMyVector CMyVector::operator+(CMyVector b)
{
	CMyVector temp(dimension);
	for (int i = 0; i < dimension; i++) {
		temp.vec[i] = vec[i] + b.vec[i];
	}
	return temp;
}

CMyVector CMyVector::operator*(double lambda)
{
	CMyVector temp(dimension);
	for (int i = 0; i < dimension; i++) {
		temp.vec[i] = lambda * vec[i];
	}
	return temp;
}