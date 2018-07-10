#pragma once
#include "CZufall.h"

using namespace std;

class CLotto
{
private:
	CZufall zufall;
	vector<int> tippzettel;
	vector<int> sim();

public:
	CLotto(int n);
	void settippzettel(vector <int> vec) { tippzettel = vec; }
	int lottoziehung();
	int lottoziehungzwei();
};