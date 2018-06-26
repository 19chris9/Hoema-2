#include "C_DGLSolver.h"
#include <iostream>

using namespace std;

void printvec(CMyVector x)
{
	for (int i = 0; i < x.getDim(); i++) {
		if (i != x.getDim() - 1)
			cout << x.getVec(i) << "; ";
		else
			cout << x.getVec(i) << ")" << endl;
	}
}

CMyVector C_DGLSolver::ableitungen(CMyVector y, double x)
{
	CMyVector erg;
	if (dgl) {
		CMyVector ergebnis;
		ergebnis = f_DGL_System(y, x);
		erg = ergebnis;
	}
	else {
		CMyVector ergebnis(y.getDim());
		ergebnis.setVec(y.getDim() - 1, f_DGL_nterOrdnung(y, x));
		for (int i = y.getDim() - 2; i >= 0; i--)
			ergebnis.setVec(i, y.getVec(i + 1));
		erg = ergebnis;
	}
	return erg;
}

void C_DGLSolver::euler(double x_start, double x_end, int schritte, CMyVector y_start)
{
	double h = (x_end - x_start) / schritte;
	cout << "h = " << h << endl << endl;
	int count = 0;
	CMyVector ys;
	double x = x_start;
	CMyVector y = y_start;
	while (count < schritte)
	{
		cout << "Schritt " << count << ":" << endl;
		cout << "x = " << x << endl;
		cout << "y = ( "; printvec(y);
		ys = ableitungen(y, x);
		cout << "y' = ( "; printvec(ys);
		y = y + ableitungen(y, x) * h;
		x = x + h;


		count++;
	}
}

void C_DGLSolver::heun(double x_start, double x_end, int schritte, CMyVector y_start)
{
	double h = (x_end - x_start) / schritte;
	cout << "h = " << h << endl << endl;
	int count = 0;
	double x = x_start;
	CMyVector y = y_start;
	CMyVector y_test, y_tests;
	CMyVector y_mittels(y.getDim());

	while (count < schritte)
	{
		cout << "Schritt " << count << ":" << endl;
		cout << "x = " << x << endl;
		cout << "y = ( "; printvec(y);
		CMyVector ys;
		ys = ableitungen(y, x);
		cout << "y'_orig = ( "; printvec(ys); cout << endl;
		y_test = y + ableitungen(y, x) * h;
		x = x + h;
		cout << "y_Test = ( "; printvec(y_test);
		y_tests = ableitungen(y_test, x);
		cout << "y'_Test = ( "; printvec(y_tests); cout << endl;
		y_mittels = (ys + y_tests) * 0.5;
		cout << "y'_Mittel = ( "; printvec(y_mittels); cout << endl;
		y = y + y_mittels * h;

		count++;
	}
}
