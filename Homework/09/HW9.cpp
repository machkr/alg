#include <iostream>
#include <math.h>

using namespace std;

int BS(int lo, int hi, int loex, int hiex, int n);

int main(void)
{
	int exp = 2;
	int num = 1;
	int n;

	cout << endl << "n: ";
	cin >> n;
	cin.ignore();

	while(exp <= n)
	{
		num *= 2;
		exp = pow(exp, 2);
	}

	cout << endl << "floor(lg(n)) = " << BS(num / 2, num, sqrt(exp), exp, n) << endl << endl;
}

int BS(int lo, int hi, int loex, int hiex, int n)
{
	int mid;
	int midex;

	if(lo == hi) 
	{
		return hi;
	}

	mid = (lo + hi) / 2;
	midex = sqrt(loex * hiex);

	if(midex <= n)
	{
		return BS(mid, hi, midex, hiex, n);
	}
	else
	{
		return BS(lo, mid, loex, midex, n);
	}
}