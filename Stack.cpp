#include <iostream>
using namespace std;

#define SIZE 10

typedef struct
{
	char stackArr[SIZE];
	int topIndex;
	char name;
}stack;

typedef stack* pstack;

void init(pstack ps, char c);

void push(pstack ps, char ch);

char pop(pstack ps);

int main()
{
	stack s1, s2;
	int i;

	init(&s1, 'A');
	init(&s2, 'B');
	cout << endl;
	push(&s1, 'd');
	push(&s1, 'a');
	push(&s1, 't');
	push(&s1, 'a');
	
	push(&s2, 's');
	push(&s2, 't');
	push(&s2, 'a');
	push(&s2, 'c');
	push(&s2, 'k');

	for (i = 0; i < 5; i++)
		cout << "Pop s1: " << pop(&s1) << "\n";
	cout << endl;

	for (i = 0; i < 5; i++)
	
		cout << "Pop s2:" << pop(&s2) << "\n";
	return 0;
}

void init(pstack ps, char c)
{
	ps->topIndex = 0;
	ps->name = c;
	cout << "Constructing stack " << ps->name << "\n";
}

void push(pstack ps, char ch)
{
	if (ps->topIndex == SIZE) {
		cout << "Stak " << ps->name << "is full\n";
		return;
	}

	ps->stackArr[ps->topIndex] = ch;
	ps->topIndex++;
}

char pop(pstack ps)
{
	if (ps->topIndex == 0)
	{
		cout << "Stack" << ps->name << "is empty \n";
		return 0;
	}
	ps->topIndex--;

	return ps->stackArr[ps->topIndex];
}