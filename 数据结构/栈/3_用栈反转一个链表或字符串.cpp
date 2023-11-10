#include <iostream>
#include <stack>	//�˴�ʹ��C++��׼���ṩ��ջ

void Reverse(char* string, int length)
{
	std::stack<char> stack;

	for (int i = 0; i < length; i++)
	{
		stack.push(string[i]);
	}

	for (int i = 0; i < length; i++)
	{
		string[i] = stack.top();
		stack.pop();
	}
}

int main()
{
	char string[51];

	std::cout << "Enter a string: ";
	gets_s(string);

	Reverse(string, strlen(string));

	std::cout << "Reverse Output: " << string;
}

/*����������ʱ��ת����:

void Reverse()
{
	if(head == NULL) return;

	stack<struct Node*> S;
	Node* temp = head;
	while (temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}

	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty())
	{
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}*/