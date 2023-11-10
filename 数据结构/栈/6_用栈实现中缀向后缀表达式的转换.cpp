//简单起见，本例使用一位数字，而不能使用两位以上数字
//测试用例：((1+2)*3-4)*5	||	 (2+4/3)*5
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

std::string InfixToPostfixConversion(std::string expression) //核心步骤！
{
	std::stack<char> S;

	std::string postfix = "";
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];		//数字直接插到新表达式中
		} 

		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}	//当当前操作符优先级更低，且当前栈顶不是(，那么将整个栈中优先级更高的操作符全部弹出并插入后缀表达式中

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
			S.pop();	//弹出 ( 字符，该字符不插入后缀表达式
		}
	}

	while (!S.empty())
	{
		//将最后剩余的栈中元素全弹并插入后缀表达式
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

	return top_weight >= this_weight ? true : false; //从左向右扫描，栈中元素一定在左，同级别下左边即栈顶元素权重更高
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

