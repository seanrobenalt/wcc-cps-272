class MyQueue
{
	int *elements;
	int capacity;
	int front;
	int back;
	int count;

public:
	MyQueue(int size);
	~MyQueue();

	void dequeue();
	void enqueue(int x);
	int size();
	bool isEmpty();
	bool isFull();
};
