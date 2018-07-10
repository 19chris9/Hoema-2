#include "CZufall.h"

int CZufall::wert(int a, int b)
{
	return (rand() % ((b + 1) - a)) + a;
}

std::vector<int> CZufall::test(int a, int b, int N)
{
	vector<int> ergebnis;
	ergebnis.resize(b - a + 1);
	for (int i = 0; i < N; i++) {
		int w = wert(a, b);
		ergebnis[w - a]++;
	}
	return ergebnis;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N)
{
	vector<int> ergebnis;
	ergebnis.resize(b - a + 1);
	initialisiere(time(NULL));
	for (int i = 0; i < N; i++) {
		int w = wert(a, b);
		ergebnis[w - a]++;
		initialisiere(time(NULL));
	}
	return ergebnis;
}
