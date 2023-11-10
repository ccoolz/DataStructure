#include <iostream>

struct Node
{
	int data;
	Node* link;
};

Node* head;
int length = 0;

void Insert(int data, int n) //�ڵ�n��λ�ò�������
{
	if (n < 0 || n > length + 1)
	{
		std::cout << "The insert position is illigle, please try again." << std::endl;
		return;
	} //������λ�õĺϷ���
	
	Node* temp = new Node();
	temp->data = data;
	temp->link = nullptr;

	//case1: ��ͷ�ڵ㴦����ڵ�
	if (n == 1)
	{
		temp->link = head; //�����ǲ��ǿ�����������ôд�������������
		head = temp; //����ͷ�ڵ�
		length++;
		return;
	}

	//case2: �������ͷ�ڵ����ĳ��λ�ò���ڵ�
	Node* circle = head; //�ýڵ�����ѭ����Ҫ�����λ��
	for (int i = 1; i < n - 1; i++)	//��λ��1��ʼ��ѭ����λ��n-1 (����λ�õ�ǰ���ڵ�)
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

	//��������ʵ�ֵ������û���������Ľڵ�����Ȼ�������û����룺
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

			Insert(data, position); //��������
			Print(); //ÿ�β�����ӡ��������
		}

		std::cout << "Do u wanna continue or exist(1/0):";
		std::cin >> keep;
	}

	return 0;
}