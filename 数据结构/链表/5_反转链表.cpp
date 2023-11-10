#include <iostream>
#include <string>

struct Node
{
	int data;
	Node* link;
};

Node* head;			//作为全局变量非常重要，始终要保存当前链表头节点的值
int length = 0;

void Reverse() 
{
	Node *current, *prev, *next;	//这几个变量的交替赋值可以滚动的实现链表反转

	//对以上几个特殊局部变量赋合适的初值
	current = head; //先逆转头节点
	prev = nullptr;	//原头节点逆转应指向NULL

	while (current != nullptr) //由循环体中的顺序可知，在current = 最后一个节点 时，继续执行，next = null -> current指向倒数第二节点 -> prev指向最后一个节点 -> current指向null，此时应退出循环
	{
		next = current->link; //next指向当前节点后面的节点，以防该节点丢失
		current->link = prev; //当前节点指针指向前一节点
		prev = current; //移动“前一节点”指针到当前位置
		current = next; //移动“当前节点”指针到下一位置
	} //对于特殊用例，即空列表和只有一个节点的链表同样适用
	head = prev; //循环退出后，只有prev还指向最后节点处，以prev重置head指针

}

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
		std::cout << "Do u wanna End the program (yes/no):";
		std::cin >> End;
		if (End == "yes")
		{
			break;
		}

		std::cout << "Insert/Delete/Reverse(i/d/r):";
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

				std::cout << "Do u wanna [Continue(enter'1')] or [Turn to Another Operation(enter'0')]:";
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

				std::cout << "Do u wanna [Continue(enter'1')] or [Turn to Another Operation(enter'0')]:";
				std::cin >> keep;
			}
		}

		//-------------反转链表-------------
		if (option == 'r')
		{
			Reverse();
			Print();
		}
	}

	return 0; //退出程序
}
