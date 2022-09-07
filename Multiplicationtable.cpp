#include <iostream>
using namespace std;

int Bonus2(int a, int b)
{
	if (a <= 9)
	{
		cout << a << "*" << b << "=" << a * b << endl;
		if (b < 9)
		{
			Bonus2(a, b + 1);
		}
		else
		{
			return Bonus2(a + 1, 1);
		}
	}

}

int main()
{
	int i = 2, j = 1;
	Bonus2(i, j);

}