#include <iostream>
using namespace std;

int Bonus2(int a, int b)
{
	if(a < b)
	{
		if(a % 2 == 0)
		{
			if(a < b - 2)
			{
				cout << a + 2 << endl;
				return Bonus2(a + 2, b);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			a++;
			cout << a << endl;
			if(a < b - 2)
			{
				cout << a + 2 << endl;
				return Bonus2(a + 2, b);
			}
			else
			{
				return a;
			}
		}
	}
	else
	{
		if (b % 2 == 0)
		{
			if (b < a - 2)
			{
				cout << b + 2 << endl;
				return Bonus2(a, b + 2);
			}
			else
			{
				return b;
			}	
		}
		else
		{
			b++;
			cout << b << endl;
			if (b < a - 2)
			{
				cout << b + 2 << endl;
				return Bonus2(a, b + 2);
			}
			else
			{
				return b;
			}

		}
	}
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	Bonus2(a, b);
}

