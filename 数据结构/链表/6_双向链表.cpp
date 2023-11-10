#include <iostream>
#include <string>

struct DNode //˫������ʵ�ַ����ӡ�ȹ��ܣ���������ݶ�������
{
	int data;
	DNode* prev;
	DNode* next;
};

DNode* head;
int length = 0;

DNode* GetNewNode(int data)
{
	DNode* newNode = new DNode(); //�����е���ʱ�������������ں�����������Զ����(����Ȼ������ָ�룬��ָ��ָ��������ѱ����)��Ҫ�ڶ��ϴ�������malloc

	newNode->data = data;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	return newNode;
}

void InsertAtHead(int data)
{
	DNode* temp = GetNewNode(data);

	//1.����Ϊ��
	if (head == nullptr)
	{
		head = temp;
		length++;
		return;
	}

	//2.����Ϊ��
	temp->next = head;
	head->prev = temp;
	head = temp;
	length++;
}

void InsertAtTail(int data)
{
	DNode* temp = GetNewNode(data);

	//1.����Ϊ��
	if (head == nullptr)
	{
		head = temp;
		length++;
		return;
	}

	//2.����Ϊ��
	DNode* circle = head;
	while (circle->next != nullptr)
	{
		circle = circle->next;
	} //ѭ����β��

	circle->next = temp;
	temp->prev = circle;
	length++;
}

void Print()
{
	if (head == nullptr)
	{
		std::cout << "empty list\n";
		return;
	}

	DNode* circle = head;
	while (circle->next != nullptr)
	{
		std::cout << circle->data << "->";
		circle = circle->next;
	} //ѭ����β���������д�ӡ����
	std::cout << circle->data << std::endl;
}

void PrintReverse()
{
	if (head == nullptr)
	{
		std::cout << "empty list\n";
		return;
	}

	DNode* circle = head;
	while (circle->next != nullptr)
	{
		circle = circle->next;
	} //ѭ����β��

	while (circle->prev != nullptr)
	{
		std::cout << circle->data << "->";
		circle = circle->prev;
	} //��ѭ����ͷ���������д�ӡ����
	std::cout << circle->data << std::endl;
}

void Delete(int position)	//Ҫ�ֶ���������ۣ�һЩ����»���Ϊ��null��null�������˳�
{
	if (head == nullptr || position > length )
	{
		std::cout << "wrong position\n";
		return;
	} //ɾ��λ�ó��������Ȼ�����Ϊ��ʱ����

	DNode* circle = head;

	if (position == 1)
	{
		if (length == 1)
		{
			head = nullptr;
			length--;
			delete circle;
			return;
		}

		head = head->next;
		head->prev = nullptr;
		delete circle;
		length--;
		return;
	} //ɾ������ͷ�ڵ�

	for (int i = 1; i <= position - 1; i++)
	{
		circle = circle->next;
	} //ѭ����Ҫɾ����λ��

	if (position == length)	//ɾ������ĩβ�ڵ�
	{
		DNode* temp = circle->prev;
		temp->next = nullptr;
		delete circle;
		length--;
		return;
	}

	DNode* tempPrev = circle->prev;
	DNode* tempNext = circle->next;

	tempPrev->next = tempNext;
	tempNext->prev = tempPrev;
	delete circle;
	length--;
}

int main()
{
	head = nullptr; //��ʼ��ͷָ��

	int keep = 1;
	while(keep)
	{
		std::cout << "\nchoose an operation Below\n";
		std::cout
			<< "1:Insert\n"
			<< "2:Delete\n"
			<< "3:Print\n"
			<< "4:PrintReverse\n"
			<< "5:End\n";
		std::cout << "choise Number��";
		int choise;
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			std::cout << "headInsret(h) or TailInsert(t) : ";
			char insert;
			std::cin >> insert;
			if (insert == 'h')
			{
				std::cout << "data��";
				int data;
				std::cin >> data;
				InsertAtHead(data); break;
			}
			else if (insert == 't')
			{
				std::cout << "data��";
				int data;
				std::cin >> data;
				InsertAtTail(data); break;
			}
			else
				std::cout << "wrong choise\n";
									break;

		case 2:
			std::cout << "position you'd delete:";
			int position;
			std::cin >> position;
			Delete(position);
									break;

		case 3:		Print();		break;

		case 4:		PrintReverse(); break;

		case 5:		keep = 0;		break;

		default:	std::cout << "wrong choise\n";
		}
	}

	return 0;
}

/*BUG������ڵ���Ϊ1ʱ��ɾ���ýڵ����ɳ����˳���
�����������Delete�����ж��һ�������ж�
	if (head->next == nullptr)
	{
		head = nullptr;
		length--;
		delete circle;
		return;
	}
*/