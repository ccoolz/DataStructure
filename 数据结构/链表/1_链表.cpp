#include <iostream>

struct Node
{
	int data;
	Node* link;	//C����ʵ��Ϊ��struct Node* link;
};

int main()
{
	//-----------------------����ͷ�ڵ�-----------------------
	Node* A;	//����һ��ͷָ��ָ��ͷ�ڵ㣬�½��������������ֽ�A

	Node* temp = new Node();
	//C����ʵ��Ϊ��Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->data = 2;	//ͷ�ڵ��data��Ϊ2
	//C����ʵ��Ϊ: (*temp).data = 2;

	temp->link = nullptr; //ͷ�ڵ�ող��룬������һ���ڵ���ʱΪ��
	//C����ʵ��Ϊ��(*temp).link = NULL

	A = temp;
	//-----------------------����ͷ�ڵ�-----------------------


	//----------------����ͷ�ڵ����һ�ڵ�----------------
	temp = new Node();
	temp->data = 4;
	temp->link = nullptr;

	Node* temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//�����������Ϳ��Դ����β�ڵ����нڵ��ֵ
		temp1 = temp1->link;
	} //��ͷ�ڵ�֮���ĩβ�ڵ������½ڵ㣬����Ҫ��ͨ��������ѭ�����������β��

	temp1->link = temp;
	//----------------����ͷ�ڵ����һ�ڵ�----------------

	//----------------����"��һ�ڵ�"����һ�ڵ�----------------
	temp = new Node();
	temp->data = 8;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//�����������Ϳ��Դ����β�ڵ����нڵ��ֵ
		temp1 = temp1->link;
	} //��ͷ�ڵ�֮���ĩβ�ڵ������½ڵ㣬����Ҫ��ͨ��������ѭ�����������β��
	std::cout << temp1->data << std::endl;	//��ӡβ�ڵ��ֵ��������

	temp1->link = temp;
	//----------------����"��һ�ڵ�"����һ�ڵ�----------------

	//----------------����"��һ�ڵ�"����һ�ڵ�----------------
	temp = new Node();
	temp->data = 16;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//�����������Ϳ��Դ����β�ڵ����нڵ��ֵ
		temp1 = temp1->link;
	} //��ͷ�ڵ�֮���ĩβ�ڵ������½ڵ㣬����Ҫ��ͨ��������ѭ�����������β��
	std::cout << temp1->data << std::endl;	//��ӡβ�ڵ��ֵ��������

	temp1->link = temp;
	//----------------����"��һ�ڵ�"����һ�ڵ�----------------

	//----------------����"��һ�ڵ�"����һ�ڵ�----------------
	temp = new Node();
	temp->data = 32;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//�����������Ϳ��Դ����β�ڵ����нڵ��ֵ
		temp1 = temp1->link;
	} //��ͷ�ڵ�֮���ĩβ�ڵ������½ڵ㣬����Ҫ��ͨ��������ѭ�����������β��
	std::cout << temp1->data << std::endl;	//��ӡβ�ڵ��ֵ��������

	temp1->link = temp;
	//----------------����"��һ�ڵ�"����һ�ڵ�----------------

	//----------------����"��һ�ڵ�"����һ�ڵ�----------------
	temp = new Node();
	temp->data = 64;
	temp->link = nullptr;

	temp1 = A;
	while (temp1->link != nullptr)
	{
		std::cout << temp1->data << "->";	//�����������Ϳ��Դ����β�ڵ����нڵ��ֵ
		temp1 = temp1->link;
	} //��ͷ�ڵ�֮���ĩβ�ڵ������½ڵ㣬����Ҫ��ͨ��������ѭ�����������β��
	std::cout << temp1->data << std::endl;	//��ӡβ�ڵ��ֵ��������

	temp1->link = temp;
	//----------------����"��һ�ڵ�"����һ�ڵ�----------------
	
	return 0;
}