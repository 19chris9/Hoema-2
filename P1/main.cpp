#include "CMyVector.h"
#include <math.h>
#include <iostream>

double funkt1(CMyVector v)
{
	double x = v.getVec(0);
	double y = v.getVec(1);
	return sin(x + y * y) + y * y*y - 6 * y*y + 9 * y;
}

double funkt2(CMyVector v) {
	double x = v.getVec(0);
	double y = v.getVec(1);
	double z = v.getVec(2);
	return -(2 * x*x - 2 * x*y + y * y + z * z - 2 * x - 4 * z);
}

CMyVector gradient(CMyVector x, double(*funktion)(CMyVector x))
{
	double h = 0.00000001;
	CMyVector res(x.getDim());
	for (int i = 0; i < x.getDim(); i++) {
		CMyVector temp = x;
		temp.setVec(i, temp.getVec(i) + h);
		double t = ((*funktion)(temp) - (*funktion)(x)) / h;
		res.setVec(i, t);
	}
	return res;
}
void printvec(CMyVector x)
{
	for (int i = 0; i < x.getDim(); i++) {
		if (i != x.getDim() - 1)
			cout << x.getVec(i) << "; ";
		else
			cout << x.getVec(i) << ")" << endl;
	}
}

void gradientenverfahren(CMyVector x, double(*funktion)(CMyVector x), double lambda = 1.0)
{
	int count = 0;

	while (count < 51) {
		if (count == 50)
			break;
		cout << endl << "Schritt " << count << ":" << endl;
		cout << "X = ( "; printvec(x);
		double fx = (*funktion)(x);
		cout << "lambda = " << lambda << endl << "F(x) = " << fx << endl;
		CMyVector gradfx = gradient(x, funktion);
		cout << "grad f(x) = ( "; printvec(gradfx);
		cout << "||grad f(x)|| = " << gradfx.laenge() << endl << endl;
		CMyVector x_neu = x + gradfx * lambda;
		double fx_neu = funktion(x_neu);
		cout << "x_neu = ( "; printvec(x_neu); cout << "f(x_neu) = " << fx_neu << endl << endl;

		if (fx_neu > fx) {
			cout << "Test mit doppelter Schrittweite (lambda = " << lambda * 2 << "):" << endl;
			CMyVector x_test = x + gradfx * lambda * 2;
			double fx_test = funktion(x_test);
			cout << "x_test = ( "; printvec(x_test);
			cout << "f(x_test) = " << fx_test << endl;
			if (fx_test > fx_neu) {
				x = x_test;
				lambda = lambda * 2;
				cout << "Verdoppelte Schrittweite!" << endl;
			}
			else {
				cout << "behalte alte Schrittweite!" << endl;
				x = x_neu;
			}

		}
		else {
			while (fx_neu <= fx) {
				cout << "halbiere Schrittweite (lambda = " << lambda / 2 << "):" << endl;
				lambda = lambda / 2;
				x_neu = x + gradfx * (lambda);
				fx_neu = funktion(x_neu);
				cout << "x_neu = ( "; printvec(x_neu); cout << "f(x_neu) = " << fx_neu << endl << endl;
			}
			x = x_neu;
		}
		if (gradfx.laenge() < 0.00001)
			break;
		count++;
	}
	cout << endl << endl;
	if (count == 50)
		cout << "Ende wegen Schrittanzahl = 50 bei" << endl;
	else
		cout << "Ende wegen ||grad f(x)||<1e-5 bei " << endl;
	cout << "X = ( "; printvec(x);
	cout << "lambda = " << lambda << endl;
	cout << "f(x) = " << funktion(x) << endl;
	CMyVector gradfx = gradient(x, funktion);
	cout << "grad f(x) = ( "; printvec(gradfx);
	cout << "||grad f(x)|| = " << gradfx.laenge() << endl;
}

	


int main()
{
	double(*funktion)(CMyVector) = funkt1;
	CMyVector start(2);
	start.setVec(0, 3); start.setVec(1, 2);
	//gradientenverfahren(start, funktion);
	CMyVector start2(3);
	start2.setVec(0, 0); start2.setVec(1, 0); start2.setVec(2, 0);
	funktion = funkt2;
	gradientenverfahren(start2, funktion);
	cout << endl;
	system("PAUSE");

}