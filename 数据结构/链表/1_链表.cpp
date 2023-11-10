#include <iostream>

struct Node
{
	int data;
	Node* link;	//C语言实现为：struct Node* link;
};

int main()
{
	//-----------------------创建头节点-----------------------
	Node* A;	//创建一个头指针指向头节点，新建的这个链表的名字叫A

	Node* temp = new Node();
	//C语言实现为：Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->data = 2;	//头节点的data设为2
	//C语言实现为: (*temp).data = 2;

	temp->link = nullptr; //头节点刚刚插入，它的下一个节点暂时为空
	//C语言实现为：(*temp).link = NULL

	A = temp;
	//-----------------------创建头节点-----------------------


	//----------------创建头节点的下一节点----------------
	temp = new Node();
	temp->data = 4;
	temp->link = nullptr;

	Node* temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//插入这条语句就可以打出除尾节点所有节点的值
		temp1 = temp1->link;
	} //在头节点之后的末尾节点后插入新节点，都需要先通过这样的循环到达链表的尾部

	temp1->link = temp;
	//----------------创建头节点的下一节点----------------

	//----------------创建"下一节点"的下一节点----------------
	temp = new Node();
	temp->data = 8;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//插入这条语句就可以打出除尾节点所有节点的值
		temp1 = temp1->link;
	} //在头节点之后的末尾节点后插入新节点，都需要先通过这样的循环到达链表的尾部
	std::cout << temp1->data << std::endl;	//打印尾节点的值，并换行

	temp1->link = temp;
	//----------------创建"下一节点"的下一节点----------------

	//----------------创建"下一节点"的下一节点----------------
	temp = new Node();
	temp->data = 16;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//插入这条语句就可以打出除尾节点所有节点的值
		temp1 = temp1->link;
	} //在头节点之后的末尾节点后插入新节点，都需要先通过这样的循环到达链表的尾部
	std::cout << temp1->data << std::endl;	//打印尾节点的值，并换行

	temp1->link = temp;
	//----------------创建"下一节点"的下一节点----------------

	//----------------创建"下一节点"的下一节点----------------
	temp = new Node();
	temp->data = 32;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//插入这条语句就可以打出除尾节点所有节点的值
		temp1 = temp1->link;
	} //在头节点之后的末尾节点后插入新节点，都需要先通过这样的循环到达链表的尾部
	std::cout << temp1->data << std::endl;	//打印尾节点的值，并换行

	temp1->link = temp;
	//----------------创建"下一节点"的下一节点----------------

	//----------------创建"下一节点"的下一节点----------------
	temp = new Node();
	temp->data = 64;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//插入这条语句就可以打出除尾节点所有节点的值
		temp1 = temp1->link;
	} //在头节点之后的末尾节点后插入新节点，都需要先通过这样的循环到达链表的尾部
	std::cout << temp1->data << std::endl;	//打印尾节点的值，并换行

	temp1->link = temp;
	//----------------创建"下一节点"的下一节点----------------
	
	return 0;
}