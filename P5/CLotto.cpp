#include "CLotto.h"

vector<int> CLotto::sim()
{
	bool gezogen = false;
	vector<int> temp;
	for (int i = 0; i < 6; i++) {
		int w;
		do {
			w = zufall.wert(1, 49);
			for (int i = 0; i < temp.size(); i++) {
				if (w == temp[i]) {
					gezogen = true;
					break;
				}
				gezogen = false;
			}
		} while (gezogen);
		temp.push_back(w);
	}
	return temp;
}

CLotto::CLotto(int n)
{
	if (n < 0)
		n = time(NULL);
	zufall.initialisiere(n);
}

int CLotto::lottoziehung()
{
	int treffer = 0;
	vector<int> ziehung = sim();
	for (int i = 0; i < ziehung.size(); i++) {
		for (int z = 0; z < ziehung.size(); z++) {
			if (ziehung[i] == tippzettel[z])
				treffer++;
		}
	}
	return treffer;
}

int CLotto::lottoziehungzwei()
{
	int treffer = 0;
	vector<int> ziehung = sim();
	vector<int> ziehung2 = sim();
	for (int i = 0; i < ziehung.size(); i++) {
		for (int z = 0; z < ziehung.size(); z++) {
			if (ziehung[i] == ziehung2[z])
				treffer++;
		}
	}
	return treffer;
}
