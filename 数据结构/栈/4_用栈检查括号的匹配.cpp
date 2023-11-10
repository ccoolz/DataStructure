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
		} //左括号字符插入栈

		if (text[i] == ')' || text[i] == ']' || text[i] == '}')
		{
			if (stack.CheckChar(text[i]) == false) return false;
		} //右括号字符检测是否有匹配的左括号
	}

	if (stack.m_Top != 0)
	{
		return false;
	} //全部检测后Top应为0，不为0代表有左括号未匹配，即总的右括号数量小于总的左括号数量

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


/* 测试集:
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