#include "CMyMatrix.h"

void printvec(CMyVector x)
{
	for (int i = 0; i < x.getDim(); i++) {
		if (i != x.getDim() - 1)
			cout << x.getVec(i) << "; ";
		else
			cout << x.getVec(i) << ")" << endl;
	}
}

void printmat(CMyMatrix x)
{
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			if (a != 1 || b != 1)
				cout << x.getVal(a, b) << "; ";
			else
				cout << x.getVal(a, b) << ")" << endl;
		}
	}
}


CMyMatrix invers(CMyMatrix A)
{
	if (A.n == 2 && A.m == 2 && A.getVal(0, 0) * A.getVal(1, 1) - A.getVal(0, 1) * A.getVal(1, 0) != 0) {
		CMyMatrix temp(2, 2);
		double a = A.getVal(0, 0); double b = A.getVal(0, 1); double c = A.getVal(1, 0); double d = A.getVal(1, 1);
		double formel = 1 / (a*d - b * c);
		temp.setVal(d * formel, 0, 0);
		temp.setVal(-b * formel, 0, 1);
		temp.setVal(-c * formel, 1, 0);
		temp.setVal(a * formel, 1, 1);
		return temp;
	}
	else {
		cout << "Das Programm muss beendet werden.";
		system("PAUSE");
		exit(0);
	}
}

CMyVector operator*(CMyMatrix A, CMyVector x)
{
	CMyVector temp(A.m);
	for (int a = 0; a < A.m; a++) {
		double t = 0.0;
		for (int b = 0; b < A.n; b++) {
			t += A.getVal(a, b) * x.getVec(b);
		}
		temp.setVec(a, t);
	}
	return temp;
}

CMyMatrix jacobi(CMyVector x, CMyVector(*funktion)(CMyVector x))
{
	double h = 0.0001;
	CMyMatrix res(x.getDim(), funktion(x).getDim());
	for (int a = 0; a < res.getDimM(); a++) {
		for (int b = 0; b < x.getDim(); b++) {
			CMyVector temp = x;
			temp.setVec(b, temp.getVec(b) + h);
			double t = ((*funktion)(temp).getVec(a) - (*funktion)(x).getVec(a)) / h;
			res.setVal(t, a, b);
		}
	}
	return res;
}

void newtonverfahren(CMyVector x, CMyVector(*funktion)(CMyVector x))
{
	int count = 0;
	while (count < 50)
	{
		cout << endl << "Schritt " << count << ":" << endl;
		cout << "X = ( "; printvec(x);
		CMyVector fx = (*funktion)(x);
		cout << "f(x) = ( "; printvec(fx);
		CMyMatrix jx = jacobi(x, funktion);
		cout << "f'(x) = ( "; printmat(jx);
		CMyMatrix invjx = invers(jx);
		cout << "(f'(x))^(-1) = ( "; printmat(invjx);
		CMyVector dx = invjx * funktion(x) * -1;
		cout << "dx = ( "; printvec(dx);
		double fxlaenge = fx.laenge();
		cout << "||f(x)|| = " << fxlaenge << endl << endl;

		x = x + dx;

		if (fxlaenge < 0.00001)
			break;
		count++;
	}

	if (count == 50)
		cout << "Ende wegen Schrittanzahl = 50 bei" << endl;
	else
		cout << "Ende wegen ||grad f(x)||<1e-5 bei " << endl;
	cout << "X = ( "; printvec(x);
	cout << "f(x) ( = "; printvec(funktion(x));
	cout << "||f(x)|| = " << funktion(x).laenge() << endl;
}

