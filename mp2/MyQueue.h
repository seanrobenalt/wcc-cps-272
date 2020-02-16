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

MyQueue::MyQueue(int size)
{
	elements = new int[size];
	capacity = size;
	front = 0;
	back = -1;
	count = 0;
}

MyQueue::~MyQueue()
{
	delete elements;
}

void MyQueue::dequeue()
{
	if (isEmpty())
	{
		count = 0;
	} else {

		front = (front + 1) % capacity;
		count--;
	}
}

void MyQueue::enqueue(int item)
{
	if (isFull())
	{
		return;
	}

	back = (back + 1) % capacity;
	elements[back] = item;
	count++;
}

int MyQueue::size()
{
	return count;
}

bool MyQueue::isEmpty()
{
	return (size() == 0);
}

bool MyQueue::isFull()
{
	return (size() == capacity);
}
