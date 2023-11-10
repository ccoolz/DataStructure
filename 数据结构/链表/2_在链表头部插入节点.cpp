#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Node* head; //声明指向头节点的指针；建立全局变量可以让Insert和main函数的head值同步，否则可能会失去对链表头的引用，这也是用临时变量temp的原因，如果将head设为main中的局部变量，则在Insert函数中应传入head参数，并返回修改后的head值。

void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	(*temp).data = x;
	(*temp).link = NULL;

	//情况1：head为NULL，则让头指针head直接指向该要插入的节点即可
	if (head == NULL)
	{
		head = temp;
	}
	else //情况2：该链表不是空链表，则需要让该插入节点链接原来的头节点，再让头指针head指向该插入节点，即更新头指针
	{
		temp->link = head;
		head = temp;
	}
}

void Print()
{
	struct Node* temp = head;
	while (temp->link != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->link;
	} //此时指向尾节点，但尾节点的数据还没打印，因此要在下面加一条语句
	printf("%d\n", temp->data);

	/* or
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->link;
	}
	printf("\n") */
}

int main()
{
	head = NULL; //初始化为空链表

	//接下来想实现的是让用户输入链表的节点数，然后引导用户输入：
	int n;
	printf("The numbers of Nodes you wanna insert:");
	scanf_s("%d", &n);

	int i;
	int x;
	for (i = 0; i < n; i++)
	{
		printf("Enter the data:");
		scanf_s("%d", &x);

		Insert(x); //插入数据
		Print(); //每次插入后打印整个链表
	}

	return 0;
}

/*第一次尝试时一直直接退出，
原因在于没有进行head指针初始化的行为，
就开始循环用head指针赋给temp1，
而head没赋初值时，给它的初值是NULL，
造成了程序无报错直接退出*/