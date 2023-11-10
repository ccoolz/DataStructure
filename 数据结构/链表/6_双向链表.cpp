#include <iostream>
#include <string>

struct DNode //双向链表，实现反向打印等功能，或查找数据都更方便
{
	int data;
	DNode* prev;
	DNode* next;
};

DNode* head;
int length = 0;

DNode* GetNewNode(int data)
{
	DNode* newNode = new DNode(); //函数中的临时变量及其数据在函数结束后会自动清除(即虽然返回了指针，但指针指向的数据已被清除)，要在堆上创建，用malloc

	newNode->data = data;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	return newNode;
}

void InsertAtHead(int data)
{
	DNode* temp = GetNewNode(data);

	//1.链表为空
	if (head == nullptr)
	{
		head = temp;
		length++;
		return;
	}

	//2.链表不为空
	temp->next = head;
	head->prev = temp;
	head = temp;
	length++;
}

void InsertAtTail(int data)
{
	DNode* temp = GetNewNode(data);

	//1.链表为空
	if (head == nullptr)
	{
		head = temp;
		length++;
		return;
	}

	//2.链表不为空
	DNode* circle = head;
	while (circle->next != nullptr)
	{
		circle = circle->next;
	} //循环到尾部

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
	} //循环到尾部，过程中打印数据
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
	} //循环到尾部

	while (circle->prev != nullptr)
	{
		std::cout << circle->data << "->";
		circle = circle->prev;
	} //再循环到头部，过程中打印数据
	std::cout << circle->data << std::endl;
}

void Delete(int position)	//要分多种情况讨论，一些情况下会因为给null赋null等问题退出
{
	if (head == nullptr || position > length )
	{
		std::cout << "wrong position\n";
		return;
	} //删除位置超出链表长度或链表为空时报错

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
	} //删除的是头节点

	for (int i = 1; i <= position - 1; i++)
	{
		circle = circle->next;
	} //循环到要删除的位置

	if (position == length)	//删除的是末尾节点
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
	head = nullptr; //初始化头指针

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
		std::cout << "choise Number：";
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
				std::cout << "data：";
				int data;
				std::cin >> data;
				InsertAtHead(data); break;
			}
			else if (insert == 't')
			{
				std::cout << "data：";
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

/*BUG：链表节点数为1时，删除该节点会造成程序退出。
解决方法，在Delete函数中多加一个如下判断
	if (head->next == nullptr)
	{
		head = nullptr;
		length--;
		delete circle;
		return;
	}
*/