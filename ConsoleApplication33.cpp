#include <iostream>
using namespace std;

#define NEXT(index,QSIZE) ((index+1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
}Queue;

void InitQueue(Queue* queue, int qsize);
int IsFull(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);

int main(void) {
	int i, size;
	int select = -1;

	Queue queue;

	cout << "큐의 크기를 입력하세요.:";
	cin >> size;

	InitQueue(&queue, size);

	while (1) {
		cout << "1. Enqueue 2. Dequeue" << endl;
		cout << ">> ";
		cin >> select;

		switch (select) {
		case 1:
			int value;
			cout << "input data : ";
			cin >> value;
			Enqueue(&queue, value);
			break;

		case 2:
			Dequeue(&queue);
			break;
		}
		cout << "\n";
	}
}
	void InitQueue(Queue * queue, int qsize) {
		queue->buf = new int[qsize];
		queue->qsize = qsize;
		queue->front = queue->rear = 0;
		queue->count = 0;
	}

	int IsFull(Queue* queue) { return queue->count == queue->qsize; }

	int IsEmpty(Queue* queue) { return queue->count == 0; }

	void Enqueue(Queue* queue,int data) {
		if (IsFull(queue)) {
			cout << "큐가 꽉 찼음\n";
			return;
		}
		queue->buf[queue->rear] = data;
		queue->rear = NEXT(queue->rear, queue->qsize);
		queue->count++;
	}
	int Dequeue(Queue* queue) {
		int re = 0;
		if (IsEmpty(queue)) {
			cout << "큐가 비었음\n";
			return re;
		}
		re = queue->buf[queue->front];
		queue->front = NEXT(queue->front, queue->qsize);
		cout << "dequeue : " << re;
		queue->count--;
		return re;
	}
