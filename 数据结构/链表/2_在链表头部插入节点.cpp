#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Node* head; //����ָ��ͷ�ڵ��ָ�룻����ȫ�ֱ���������Insert��main������headֵͬ����������ܻ�ʧȥ������ͷ�����ã���Ҳ������ʱ����temp��ԭ�������head��Ϊmain�еľֲ�����������Insert������Ӧ����head�������������޸ĺ��headֵ��

void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	(*temp).data = x;
	(*temp).link = NULL;

	//���1��headΪNULL������ͷָ��headֱ��ָ���Ҫ����Ľڵ㼴��
	if (head == NULL)
	{
		head = temp;
	}
	else //���2���������ǿ���������Ҫ�øò���ڵ�����ԭ����ͷ�ڵ㣬����ͷָ��headָ��ò���ڵ㣬������ͷָ��
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
	} //��ʱָ��β�ڵ㣬��β�ڵ�����ݻ�û��ӡ�����Ҫ�������һ�����
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
	head = NULL; //��ʼ��Ϊ������

	//��������ʵ�ֵ������û���������Ľڵ�����Ȼ�������û����룺
	int n;
	printf("The numbers of Nodes you wanna insert:");
	scanf_s("%d", &n);

	int i;
	int x;
	for (i = 0; i < n; i++)
	{
		printf("Enter the data:");
		scanf_s("%d", &x);

		Insert(x); //��������
		Print(); //ÿ�β�����ӡ��������
	}

	return 0;
}

/*��һ�γ���ʱһֱֱ���˳���
ԭ������û�н���headָ���ʼ������Ϊ��
�Ϳ�ʼѭ����headָ�븳��temp1��
��headû����ֵʱ�������ĳ�ֵ��NULL��
����˳����ޱ���ֱ���˳�*/