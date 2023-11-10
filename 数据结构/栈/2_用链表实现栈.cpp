#include <iostream>

struct Node
{
	int data;
	Node* link;
};

Node* top = NULL;

Node* GetNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->link = NULL;
	return temp;
}

void Push(int data)
{
	Node* temp = GetNode(data);
	temp->link = top;
	top = temp;
}

void Pop()
{
	if (top == NULL) return;

	Node* temp;
	temp = top;
	top = top->link;
	delete temp;
}

void Show()
{
	if (top == NULL) return;

	Node* temp = top;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->link;
	}   std::cout << std::endl;
}

//ÂÔTop() ºÍ isEmpty() º¯Êý

int main()
{
	int keep = 1;
	int data = 0;

	while (keep)
	{
		std::cout
			<< "1.Push\n"
			<< "2.Pop\n"
			<< "3.Show\n"
			<< "ELSE NOM.End\n"
			<< "Choice:";
		int option;
		std::cin >> option;
		
		switch (option)
		{
		case 1:
			std::cout << "data: ";
			std::cin >> data;
			Push(data);
			break;

		case 2:
			Pop();
			break;

		case 3:
			Show();
			break;

		default:
			keep = 0;
			break;
		}
	}

	return 0;
}