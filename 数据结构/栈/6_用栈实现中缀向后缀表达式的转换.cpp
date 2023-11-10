//�����������ʹ��һλ���֣�������ʹ����λ��������
//����������((1+2)*3-4)*5	||	 (2+4/3)*5
#include <iostream>
#include <stack>
#include <string>

std::string InfixToPostfixConversion(std::string expression);

bool IsOperand(char C);

bool IsOperator(char C);

int HasHigherPrecedence(char stack_top, char this_operator);

int GetWeight(char op);

int main()
{
	std::string exp;
	std::cout << "Enter an infix expression: \n";
	std::getline(std::cin, exp);

	std::string new_exp = InfixToPostfixConversion(exp);
	std::cout << "After conversion: \n" << new_exp << std::endl;
}

std::string InfixToPostfixConversion(std::string expression) //���Ĳ��裡
{
	std::stack<char> S;

	std::string postfix = "";
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];		//����ֱ�Ӳ嵽�±��ʽ��
		} 

		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}	//����ǰ���������ȼ����ͣ��ҵ�ǰջ������(����ô������ջ�����ȼ����ߵĲ�����ȫ�������������׺���ʽ��

			S.push(expression[i]);
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.empty() && S.top() != '(')
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();	//���� ( �ַ������ַ��������׺���ʽ
		}
	}

	while (!S.empty())
	{
		//�����ʣ���ջ��Ԫ��ȫ���������׺���ʽ
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

int GetWeight(char op)
{
	int weight;

	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;

	case '*':
	case '/':
		weight = 2;
		break;
	}

	return weight;
}

int HasHigherPrecedence(char stack_top, char this_operator)
{
	int top_weight = GetWeight(stack_top);
	int this_weight = GetWeight(this_operator);

	return top_weight >= this_weight ? true : false; //��������ɨ�裬ջ��Ԫ��һ������ͬ��������߼�ջ��Ԫ��Ȩ�ظ���
}

bool IsOperand(char C)
{
	if (C >= '0' && C <= '9')
		return true;

	return false;
}

bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

