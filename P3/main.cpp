#include "C_DGLSolver.h"

CMyVector DGLSystem(CMyVector y, double x)
{
	CMyVector ergebnis(2);
	ergebnis.setVec(0, (2.0 * y.getVec(1)) - (x * y.getVec(0)));
	ergebnis.setVec(1, (y.getVec(0) * y.getVec(1)) - (2.0 * x * x * x));
	return ergebnis;
}

double DGLdritt(CMyVector y, double x)
{
	return (2.0 * x * y.getVec(1) * y.getVec(2)) + (2.0 * y.getVec(0) * y.getVec(0) * y.getVec(1));
}

int main()
{
	C_DGLSolver dgl(DGLSystem);
	CMyVector y(2);
	y.setVec(0, 0);
	y.setVec(1, 1.0);

	//dgl.euler(0, 2, 100, y);
	dgl.heun(0, 2, 100, y);

	/*C_DGLSolver dgl2(DGLdritt);
	CMyVector y(3);
	y.setVec(0, 1);
	y.setVec(1, -1);
	y.setVec(2, 2);
	dgl2.heun(0, 2, 100, y);*/

	system("PAUSE");
	return 0;
}