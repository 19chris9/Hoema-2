#include "CLotto.h"
#include <iostream>

using namespace std;

void printanzahl(int a, int b, vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Zahl " << a + i << ": " << vec[i] << " mal aufgetreten." << endl;
	}
	cout << endl;
}


double monte_carlo(int anzahl)
{
	int ergebnis = 0;
	vector<int> tzettel; tzettel.push_back(10); tzettel.push_back(20); tzettel.push_back(30);
	tzettel.push_back(40); tzettel.push_back(28); tzettel.push_back(46);
	CLotto temp(-1);
	temp.settippzettel(tzettel);
	for (int i = 0; i < anzahl; i++) {
		int treffer = temp.lottoziehung();
		if (treffer == 3)
			ergebnis++;

	}
	return ergebnis / double(anzahl);
}

double monte_carlo2(int anzahl)
{
	int ergebnis = 0;
	CLotto temp(-1);
	for (int i = 0; i < anzahl; i++) {
		int treffer = temp.lottoziehungzwei();
		if (treffer == 3)
			ergebnis++;

	}
	return ergebnis / double(anzahl);
}

int main()
{
	/*Aufgabe1
	CZufall zufall;
	int a = 3, b = 7, n = 10000;
	zufall.initialisiere(n);
	printanzahl(a, b, zufall.test(a, b, n));
	printanzahl(a, b, zufall.test_falsch(a, b, n));*/

	 double wert = monte_carlo(100000);
	 double wert2 = monte_carlo(1000000);
	 double wert3 = monte_carlo2(100000);
	 double wert4 = monte_carlo2(1000000);

	 cout << "Wahrscheinlichkeit fuer 100000 Ziehungen / 3 richtige Zahlen: " << wert * 100 << "%." << endl;
	 cout << "Wahrscheinlichkeit fuer 1000000 Ziehungen / 3 richtige Zahlen: " << wert2 * 100 << "%." << endl;
	 cout << "Wahrscheinlichkeit fuer 100000 Ziehungen / 3 uebereinstimmende Zahlen: " << wert3 * 100 << "%." << endl;
	 cout << "Wahrscheinlichkeit fuer 1000000 Ziehungen / 3 uebereinstimmende Zahlen: " << wert4 * 100 << "%." << endl;

	 system("PAUSE");
}