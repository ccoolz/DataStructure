#include <iostream>

#define TEXT_LENGTH 101
#define STACK_LENGTH 101

class Stack
{
public:
	char m_array[STACK_LENGTH];
	int m_Top = -1;

	void Push(char c)
	{
		m_Top++;
		m_array[m_Top] = c;
	}
	bool CheckChar(char c)
	{
		if (c == ')')
		{
			if (m_array[m_Top] == '(')
			{
				Pop();
				return true;
			}
		}
		if (c == '}')
		{
			if (m_array[m_Top] == '{')
			{
				Pop();
				return true;
			}
		}
		if (c == ']')
		{
			if (m_array[m_Top] == '[')
			{
				Pop();
				return true;
			}
		}

		return false;
	}

	void Pop()
	{
		m_Top--;
	}
};
Stack stack;

bool CheckString(char* text)
{
	for (int i = 0; i < strlen(text) - 1; i++)
	{
		if (text[i] == '(' || text[i] == '[' || text[i] == '{')
		{
			stack.Push(text[i]);
		} //�������ַ�����ջ

		if (text[i] == ')' || text[i] == ']' || text[i] == '}')
		{
			if (stack.CheckChar(text[i]) == false) return false;
		} //�������ַ�����Ƿ���ƥ���������
	}

	if (stack.m_Top != 0)
	{
		return false;
	} //ȫ������TopӦΪ0����Ϊ0������������δƥ�䣬���ܵ�����������С���ܵ�����������

	return true;
}

int main()
{
	char text[TEXT_LENGTH] = "[(nihao )]";
	
	if (CheckString(text) == true)
	{
		std::cout << "The parentheses are matched!\n";
	}
	else
	{
		std::cout << "The parentheses are NOT matched!\n";
	}


}


/* ���Լ�:
* (
* )
* ()
* ( )
* ) (
* ({})
* {[()]}
* ([)]
* (()
* [(nihao )]
*/