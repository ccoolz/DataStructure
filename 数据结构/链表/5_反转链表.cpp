#include <iostream>
#include <string>

struct Node
{
	int data;
	Node* link;
};

Node* head;			//��Ϊȫ�ֱ����ǳ���Ҫ��ʼ��Ҫ���浱ǰ����ͷ�ڵ��ֵ
int length = 0;

void Reverse() 
{
	Node *current, *prev, *next;	//�⼸�������Ľ��渳ֵ���Թ�����ʵ������ת

	//�����ϼ�������ֲ����������ʵĳ�ֵ
	current = head; //����תͷ�ڵ�
	prev = nullptr;	//ԭͷ�ڵ���תӦָ��NULL

	while (current != nullptr) //��ѭ�����е�˳���֪����current = ���һ���ڵ� ʱ������ִ�У�next = null -> currentָ�����ڶ��ڵ� -> prevָ�����һ���ڵ� -> currentָ��null����ʱӦ�˳�ѭ��
	{
		next = current->link; //nextָ��ǰ�ڵ����Ľڵ㣬�Է��ýڵ㶪ʧ
		current->link = prev; //��ǰ�ڵ�ָ��ָ��ǰһ�ڵ�
		prev = current; //�ƶ���ǰһ�ڵ㡱ָ�뵽��ǰλ��
		current = next; //�ƶ�����ǰ�ڵ㡱ָ�뵽��һλ��
	} //�������������������б��ֻ��һ���ڵ������ͬ������
	head = prev; //ѭ���˳���ֻ��prev��ָ�����ڵ㴦����prev����headָ��

}

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

void Delete(int position)
{
	if (position < 0 || position > length || head == nullptr)
	{
		std::cout << "The delete position is illigle, please try again." << std::endl;
		return;
	} //���ɾ��λ�õĺϷ���

	Node* circle = head; //�ýڵ�����ѭ����Ҫ�����λ��
	for (int i = 1; i < position - 1; i++)	//��λ��1��ʼ��ѭ����λ��n-1 (ɾ��λ�õ�ǰ���ڵ�)
	{
		circle = circle->link;
	}

	//case1: ��ͷ�ڵ㴦ɾ���ڵ�
	if (position == 1)
	{
		head = head->link;

		if (head != NULL)
		{
			delete circle; //deleteָ���ͷŵ���ָ��ָ��Ŀռ�
		}
		length--;
		return;
	}

	//case2: �������ͷ�ڵ����ĳ��λ�ò���ڵ�
	Node* temp = circle;
	circle = circle->link;	//ѭ��ָ��ָ��ɾ��λ�õĽڵ�
	temp->link = circle->link; //ɾ��λ�õ�ǰ���ڵ����̽ڵ�����

	delete circle; //deleteָ���ͷŵ���ָ��ָ��Ŀռ�
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

		//-------------�����б�-------------
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

					Insert(data, position); //��������
					Print(); //ÿ�β�����ӡ��������
				}

				std::cout << "Do u wanna [Continue(enter'1')] or [Turn to Another Operation(enter'0')]:";
				std::cin >> keep;
			}
		}

		//-------------ɾ������-------------
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

					Delete(position); //ɾ������
					Print(); //ÿ��ɾ�����ӡ��������
				}

				std::cout << "Do u wanna [Continue(enter'1')] or [Turn to Another Operation(enter'0')]:";
				std::cin >> keep;
			}
		}

		//-------------��ת����-------------
		if (option == 'r')
		{
			Reverse();
			Print();
		}
	}

	return 0; //�˳�����
}
