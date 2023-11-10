#include <iostream>
#include <string>

struct Node
{
	int data;
	Node* link;
};

Node* head;
int length = 0;

void Insert(int data, int n) //在第n个位置插入数据
{
	if (n < 0 || n > length + 1)
	{
		std::cout << "The insert position is illigle, please try again." << std::endl;
		return;
	} //检测插入位置的合法性

	Node* temp = new Node();
	temp->data = data;
	temp->link = nullptr;

	//case1: 在头节点处插入节点
	if (n == 1)
	{
		temp->link = head; //不论是不是空链表都可以这么写，无需分类讨论
		head = temp; //更新头节点
		length++;
		return;
	}

	//case2: 在链表除头节点外的某个位置插入节点
	Node* circle = head; //该节点用以循环到要到达的位置
	for (int i = 1; i < n - 1; i++)	//从位置1开始，循环到位置n-1 (插入位置的前驱节点)
	{
		circle = circle->link;
	}
	temp->link = circle->link;
	circle->link = temp;
	length++;
}

void Delete(int position)
{
	if (position < 0 || position > length || head == nullptr)
	{
		std::cout << "The delete position is illigle, please try again." << std::endl;
		return;
	} //检测删除位置的合法性

	Node* circle = head; //该节点用以循环到要到达的位置
	for (int i = 1; i < position - 1; i++)	//从位置1开始，循环到位置n-1 (删除位置的前驱节点)
	{
		circle = circle->link;
	}

	//case1: 在头节点处删除节点
	if (position == 1)
	{
		head = head->link;

		if (head != NULL)
		{
			delete circle; //delete指针释放的是指针指向的空间
		}
		length--;
		return;
	}

	//case2: 在链表除头节点外的某个位置插入节点
	Node* temp = circle;
	circle = circle->link;	//循环指针指向到删除位置的节点
	temp->link = circle->link; //删除位置的前驱节点与后继节点连接

	delete circle; //delete指针释放的是指针指向的空间
	length--;
}

void Print()
{
	Node* temp = head;
	while (temp->link != nullptr)
	{
		std::cout << temp->data << "->";
		temp = temp->link;
	}
	std::cout << temp->data << std::endl;
}

int main()
{
	head = nullptr; //empty list

	std::string End = "no";
	while (true)
	{
		std::cout << "Do u wanna End the program(yes/no):";
		std::cin >> End;
		if (End == "yes")
		{
			break;
		}

		std::cout << "Insert/Delete(i/d):";
		char option;
		std::cin >> option;

		//-------------插入列表-------------
		if (option == 'i')
		{
			int keep = 1;
			while (keep)
			{
				int n;
				printf("The numbers of Nodes you wanna insert:");
				std::cin >> n;

				int i;
				int data, position;
				for (i = 0; i < n; i++)
				{
					std::cout << "Enter the data:";
					std::cin >> data;
					std::cout << "Enter the position you wanna Insert:";
					std::cin >> position;

					Insert(data, position); //插入数据
					Print(); //每次插入后打印整个链表
				}

				std::cout << "Do u wanna continue or exist(1/0):";
				std::cin >> keep;
			}
		}

		//-------------删除链表-------------
		if (option == 'd')
		{
			int keep = 1;
			while (keep)
			{
				int n;
				printf("The numbers of Nodes you wanna Delete:");
				std::cin >> n;

				int i;
				int position;
				for (i = 0; i < n; i++)
				{
					std::cout << "Enter the position you wanna Delete:";
					std::cin >> position;

					Delete(position); //删除数据
					Print(); //每次删除后打印整个链表
				}

				std::cout << "Do u wanna continue or exist(1/0):";
				std::cin >> keep;
			}
		}
	}

	return 0; //退出程序
}