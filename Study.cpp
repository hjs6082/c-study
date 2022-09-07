#include <iostream>
using namespace std;

int s = 0;

int Bonus1(int n)
{
	int a = 0;
	if (n < 10)
	{
		a = n;
		s += n;
		return s;
	}
	else
	{
		a = n % 10;
		s += n;
		return Bonus1(n / 10);
	}

}

int main()
{
	int d;
	cin >> d;
	cout << Bonus1(d) << endl;
}