#include <iostream>

struct Node
{
	int data;
	Node* link;
};

Node* front = nullptr;
Node* rear = nullptr;

void EnQueue(int data)
{
	Node* temp = new Node();	//需要malloc分配初始空间
	temp->data = data;
	temp->link = nullptr;

	if (front == nullptr && rear == nullptr)
	{
		front = temp;
		rear = temp;
		return;
	}

	rear->link = temp;
	rear = rear->link;
}

void DeQueue()
{
	if (front == nullptr)
	{
		std::cout << "Empty Queue, can't DeQueue. \n";
		return;
	}

	if (front == rear)
	{
		front = nullptr;
		rear = nullptr;
		return;
	}

	Node* temp = front;
	front = front->link;
	delete temp;
}

//...获得队首元素等其他简单功能略

int main()
{
	//...
}