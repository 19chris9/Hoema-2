#include "CMyVector.h"
#include <iostream>
#include "math.h"
using namespace std;


class CMyMatrix
{
private:
	int n, m;
	CMyVector vec;
public:
	CMyMatrix(int länge, int breite) { n = länge; m = breite; vec.vec.resize(n*m); vec.dimension = n * m; };
	void setVal(double wert, int i, int j) { vec.setVec(i * n + j, wert); }
	double getVal(int i, int j) { return vec.getVec(i * n + j); }
	int getDimN() { return n; };
	int getDimM() { return m; };
	friend CMyMatrix invers(CMyMatrix A);
	friend CMyVector operator*(CMyMatrix A, CMyVector x);
};


CMyMatrix invers(CMyMatrix A);
CMyVector operator*(CMyMatrix A, CMyVector x);
CMyMatrix jacobi(CMyVector x, CMyVector(*funktion)(CMyVector x));
void newtonverfahren(CMyVector x, CMyVector(*funktion)(CMyVector x));