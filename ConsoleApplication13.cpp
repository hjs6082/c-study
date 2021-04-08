#include <iostream>
using namespace std;

int Fibonachi(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibonachi(n - 1) + Fibonachi(n - 2);
}

int main()
{
	int i;
	for (i = 1; i <= 15; i++)
		cout << Fibonachi(i) << endl;
}