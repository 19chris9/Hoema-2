#include "CMyMatrix.h"

CMyVector funkt1(CMyVector v)
{
	double x1 = v.getVec(0);
	double x2 = v.getVec(1);
	double x3 = v.getVec(2);
	double x4 = v.getVec(3);
	CMyVector temp(3);
	temp.setVec(0, x1*x2*exp(x3));
	temp.setVec(1, x2*x3*x4);
	temp.setVec(2, x4);
	return temp;
}

CMyVector funkt2(CMyVector v)
{
	double x1 = v.getVec(0);
	double x2 = v.getVec(1);
	CMyVector temp(2);
	temp.setVec(0, x1*x1*x1*x2*x2*x2-2*x2);
	temp.setVec(1, x1-2);
	return temp;
}


int main()
{
	CMyVector(*funktion)(CMyVector) = funkt1;
	/*CMyVector x(4);
	x.setVec(0, 1);
	x.setVec(1, 2);
	x.setVec(2, 0);
	x.setVec(3, 3);
	CMyMatrix test(4, 3);
	test = jacobi(x, funktion);
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 4; b++)
			cout << test.getVal(a, b) << endl;
	}*/

	funktion = funkt2;
	CMyVector start2(2);
	start2.setVec(0, 1); start2.setVec(1, 1);
	newtonverfahren(start2, funktion);


	system("PAUSE");
}