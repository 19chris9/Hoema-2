#define _USE_MATH_DEFINES
#include "CKomplex.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

vector<CKomplex> werte_einlesen(const char *dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i<N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}


void werte_ausgeben(const char *dateiname, vector<CKomplex> werte, double epsilon = -1.0)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
	// File schliessen
	fp.close();
}

vector<CKomplex> fourier_hin(vector<CKomplex> werte)
{
	vector<CKomplex> ergebnis;
	for (int i = 0; i < werte.size(); i++) {
		CKomplex temp;
		for (int z = 0; z < werte.size(); z++) {
			temp = temp + werte[z] * CKomplex(-1 * i *(2 * M_PI * z / werte.size()));
		}
		temp = temp * (1 / sqrt(werte.size()));
		ergebnis.push_back(temp);
	}
	return ergebnis;
}

vector<CKomplex> fourier_zurueck(vector<CKomplex> werte)
{
	vector<CKomplex> ergebnis;
	for (int i = 0; i < werte.size(); i++) {
		CKomplex temp;
		for (int z = 0; z < werte.size(); z++) {
			temp = temp + werte[z] * CKomplex(i *(2 * M_PI / werte.size()));
		}
		temp = temp * (1 / sqrt(werte.size()));
		ergebnis.push_back(temp);
	}
	return ergebnis;
}

vector<CKomplex> abweichung_vector(vector<CKomplex> &a, vector<CKomplex> &b)
{
	vector<CKomplex> ergebnis;
	for (int i = 0; i < a.size(); i++)
		ergebnis.push_back(b[i] - a[i]);
	return ergebnis;
}

double max_abweichung(vector<CKomplex> &a)
{
	double ergebnis;
	if (a.size() >= 1)
		ergebnis = a[0].abs();
	for (int i = 1; i < a.size(); i++)
		if (a[i].abs() > ergebnis)
			ergebnis = a[i].abs();
	return ergebnis;
}

int main()
{
	vector<CKomplex> test = werte_einlesen("Daten_original.txt");
	vector<CKomplex> fourier = fourier_hin(test);
	werte_ausgeben("default.txt", fourier);
	werte_ausgeben("0.1.txt", fourier, 0.1);
	werte_ausgeben("1.0.txt", fourier, 1);
	
	vector<CKomplex> fourier_default = werte_einlesen("default.txt");
	vector<CKomplex> fourier_01 = werte_einlesen("0.1.txt");
	vector<CKomplex> fourier_10 = werte_einlesen("1.0.txt");

	vector<CKomplex> zur_default = fourier_zurueck(fourier_default);
	vector<CKomplex> zur_01 = fourier_zurueck(fourier_01);
	vector<CKomplex> zur_10 = fourier_zurueck(fourier_10);

	vector<CKomplex> abweichung_default = abweichung_vector(fourier_default, zur_default);
	vector<CKomplex> abweichung_01 = abweichung_vector(fourier_01, zur_01);
	vector<CKomplex> abweichung_10 = abweichung_vector(fourier_10, zur_10);

	cout << "Max. Abweichung mit Epsilon = -1.0: " << max_abweichung(abweichung_default) << endl;
	cout << "Max. Abweichung mit Epsilon = 0.1: " << max_abweichung(abweichung_01) << endl;
	cout << "Max. Abweichung mit Epsilon = 1.0: " << max_abweichung(abweichung_10) << endl;
	system("PAUSE");
}