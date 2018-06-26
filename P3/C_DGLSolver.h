#pragma once
#include "CMyVector.h"


class C_DGLSolver
{
private:
	bool dgl;
	CMyVector (*f_DGL_System) (CMyVector y, double x);
	double (*f_DGL_nterOrdnung) (CMyVector y, double x);
	CMyVector ableitungen(CMyVector y, double x);
public:
	C_DGLSolver  (CMyVector(*f_DGL_System)(CMyVector y, double x)) { this->f_DGL_System = f_DGL_System; dgl = true; };
	C_DGLSolver (double(*f_DGL_nterOrdnung)(CMyVector y, double x)) { this->f_DGL_nterOrdnung = f_DGL_nterOrdnung; dgl = false; };
	void euler (double x_start, double x_end, int schritte, CMyVector y_start);
	void heun(double x_start, double x_end, int schritte, CMyVector y_start);
};