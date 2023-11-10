#include <iostream>
#define CAPACITY 5
//������������Ϊ���ף��ұ�Ϊ��β

class Queue
{
private:
	int m_front;
	int m_rear;
	int A[CAPACITY];

public:
	Queue() : m_front(-1), m_rear(-1) {} //��ʼ������Ϊ��

	bool IsEmpty()
	{
		if (m_front == -1 || m_rear == -1)
			return true;
		return false;
	}

	bool IsFull()
	{
		if ((m_rear + 1) % CAPACITY == m_front)	//ѭ�����еĸ���ټ�һ�Ḳ�Ƕ�����Ϊ������ʾ��ͼ����Ƶ12:29
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
		}	//��Ϊ�գ������һ��Ԫ��ʱ��ʼ��front��rear

		else
		{
			m_rear = (m_rear + 1) % CAPACITY;
		}	//��β����

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
		}	//���н�һ��Ա�����Ӻ��ö�Ϊ�գ�����tokenΪ-1

		else
		{
			m_front = (m_front + 1) % CAPACITY;
		}	//���׳���
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
