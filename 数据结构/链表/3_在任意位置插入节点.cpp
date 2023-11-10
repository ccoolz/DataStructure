#include <iostream>

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

void Print()
{
	Node* temp = head;
	while (temp->link != nullptr)
	{
		std::cout << temp->data << "->";
		temp = temp->link;
	}
	std::cout << temp->data <<std::endl;
}

int main()
{
	head = nullptr; //empty list

	//接下来想实现的是让用户输入链表的节点数，然后引导用户输入：
	int keep = 1;
	while(keep)
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

	return 0;
}