#include <iostream>
using namespace std;


void Hanoi(int num, char from, char by, char to) {
	if (num == 1)
		cout << "원반 1을" << from << "에서" << to << "로 이동" << endl;
	else
	{
		Hanoi(num - 1, from, to, by);

		cout << "원반" << num << "을" << from << ":에서" << to << "로이동" << endl;

			Hanoi(num - 1, by, from, to);
	}
}

int main() {
	Hanoi(3, 'A', 'B', 'C');
}