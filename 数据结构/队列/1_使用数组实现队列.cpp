#include <iostream>
#define CAPACITY 5
//定义数组的左边为队首，右边为队尾

class Queue
{
private:
	int m_front;
	int m_rear;
	int A[CAPACITY];

public:
	Queue() : m_front(-1), m_rear(-1) {} //初始化队列为空

	bool IsEmpty()
	{
		if (m_front == -1 || m_rear == -1)
			return true;
		return false;
	}

	bool IsFull()
	{
		if ((m_rear + 1) % CAPACITY == m_front)	//循环队列的概念，再加一会覆盖队首则为队满，示意图见视频12:29
			return true;
		return false;
	}

	void EnQueue(int data)
	{
		if (IsFull())
		{
			std::cout << "Queue is FULL! \n";
			return;
		}

		else if (IsEmpty())
		{
			m_front = 0;
			m_rear = 0;
		}	//若为空，插入第一个元素时初始化front和rear

		else
		{
			m_rear = (m_rear + 1) % CAPACITY;
		}	//队尾进队

		A[m_rear] = data;
	}

	void DeQueue()
	{
		if (IsEmpty())
		{
			std::cout << "Queue is EMPTY! \n";
			return;
		}

		else if (m_front == m_rear)
		{
			m_front = -1;
			m_rear = -1;
		}	//队中仅一成员，出队后置队为空，且置token为-1

		else
		{
			m_front = (m_front + 1) % CAPACITY;
		}	//队首出队
	}

	int Front()
	{
		if (IsEmpty())
		{
			std::cout << "Empty Queue. \n";
		}

		return A[m_front];
	}
	
	int Rear()
	{
		if (IsEmpty())
		{
			std::cout << "Empty Queue. \n";
		}

		return A[m_rear];
	}

	void ShowQueue()
	{
		if (IsEmpty())
		{
			std::cout << "Empty Queue.\n";
			return;
		}

		int i = m_front;
		std::cout << "front| ";
		while (i != m_rear)
		{
			std::cout << A[i] << " ";
			i = (i + 1) % CAPACITY;
		}
		std::cout << A[i] << " |rear \n";
	}
};

void QueueExecutionMunu(Queue Q);

int main()
{
	Queue Q;
	QueueExecutionMunu(Q);
	return 0;
}

void QueueExecutionMunu(Queue Q)
{
	int keep = 1;
	while (keep)
	{

		std::cout << "\n0. End \n";
		std::cout << "1. EnQueue \n";
		std::cout << "2. DeQueue \n";
		std::cout << "3. Show Queue \n";

		int op;
		std::cout << "Choice Number: ";
		std::cin >> op;

		switch (op)
		{
		case 0:
			keep = 0;
			break;

		case 1:
			int data;
			std::cout << "data: ";
			std::cin >> data;
			Q.EnQueue(data);
			break;

		case 2:
			Q.DeQueue();
			break;

		case 3:
			Q.ShowQueue();
			break;

		default:
			std::cout << "Wrong choice! \n";
			break;
		}
	}
}
