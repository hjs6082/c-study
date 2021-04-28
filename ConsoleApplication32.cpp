#include <iostream>
using namespace std;

#define QUEUE_SIZE 5
#define NEXT(index)  ((index +1)%QUEUE_SIZE)

typedef struct Queue
{
	int buf[QUEUE_SIZE];
	int front;
	int rear;
}Queue;

void InitQueue(Queue* queue);
int IsFull(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);

int main(void) {
	int select = -1;
	Queue queue;
	InitQueue(&queue);

	while (1) {
		cout << "1. Enqueue 2. Dequeue" << endl;
		cout << ">> ";
		cin >> select;

		switch (select) {
		case 1:
			int value;
			cout << "input data :";
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

void InitQueue(Queue* queue) { queue->front = queue->rear = 0; }

int IsFull(Queue* queue) { return NEXT(queue->rear) == queue->front; }

int IsEmpty(Queue* queue) { return queue->front == queue->rear; }

void Enqueue(Queue* queue, int data) {
	if (IsFull(queue)) {
		printf("큐가 꽉 찼음\n");
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear);
}

int Dequeue(Queue* queue) {
	int re = 0;
	if (IsEmpty(queue)) {
		cout << "큐가 비었음\n";
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	cout << "dequeue :" << re;
	return re;
}