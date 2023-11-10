#include <iostream>
#include <string>
#include <stack>

int EvaluatePostfix(std::string expression);

bool IsNumericDigit(char C);

bool IsOperator(char C);

int PerformOperation(char operation, int operand1, int operand2);

int main()
{
	std::string expression;
	std::cout << "Enter Postfix Expression \nSplit with commas[,] or spaces[ ]\n";
	std::getline(std::cin, expression);

	int result = EvaluatePostfix(expression);
	std::cout << "Evaluating Result = " << result << "\n";

	return 0;
}


int EvaluatePostfix(std::string expression)
{
	std::stack<int> S;

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ' || expression[i] == ',')
			continue;		//以 和,作为操作数或操作符间的分割符

		else if ( IsNumericDigit(expression[i]) )
		{
			int operand = 0;
			while (i < expression.length() && IsNumericDigit(expression[i]))
			{
				operand = (operand * 10) + (expression[i] - '0');
				i++;
			} //截取当前下标所指数字的数据
			i--; //因为循环结束后标记在非数字字符处，大循环中会i++一次，将该字符跳过

			S.push(operand);
		}

		else if ( IsOperator(expression[i]) )
		{
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();

			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);		//计算结果压入栈
		}

		else
			std::cout << "Wrong expression! End the program and try again.\n";
	}
	return S.top();
}

bool IsNumericDigit(char C)
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

int PerformOperation(char operation, int operand1, int operand2)
{
	if (operation == '+') return operand1 + operand2;
	if (operation == '-') return operand1 - operand2;
	if (operation == '*') return operand1 * operand2;
	if (operation == '/') return operand1 / operand2;
}






/*
getline（istream&& is，string＆str，char delim)
从流获取线到字符串：
1.从提取的字符是并将其存储到STR直到划界字符DELIM被发现（getline(istream && is, string & str)默认分割符是“\ n”， ）。
2.如果到达文件末尾，或者在输入操作过程中出现其他错误，则提取也会停止。
3.如果找到分隔符，则将其提取并丢弃（即不存储，下一个输入操作将在其后开始）。
4.请注意，调用之前的str中的任何内容都被新提取的序列替换。
5.每个提取的字符都附加到该字符串，和使用push_back()的效果一样。
*/
