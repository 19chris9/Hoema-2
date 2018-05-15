#include <vector>

using namespace std;


class CMyVector
{
private:
	int dimension;
	vector<double> vec;
public:
	CMyVector(int dim);
	int getDim() { return dimension; };
	void setVec(int stelle, double wert) { vec[stelle] = wert; }
	double getVec(int stelle) { return vec[stelle]; };
	double laenge();
	CMyVector  operator + (CMyVector b);
	CMyVector operator * (double lambda);

};