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
			continue;		//�� ��,��Ϊ���������������ķָ��

		else if ( IsNumericDigit(expression[i]) )
		{
			int operand = 0;
			while (i < expression.length() && IsNumericDigit(expression[i]))
			{
				operand = (operand * 10) + (expression[i] - '0');
				i++;
			} //��ȡ��ǰ�±���ָ���ֵ�����
			i--; //��Ϊѭ�����������ڷ������ַ�������ѭ���л�i++һ�Σ������ַ�����

			S.push(operand);
		}

		else if ( IsOperator(expression[i]) )
		{
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();

			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);		//������ѹ��ջ
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
getline��istream&& is��string��str��char delim)
������ȡ�ߵ��ַ�����
1.����ȡ���ַ��ǲ�����洢��STRֱ�������ַ�DELIM�����֣�getline(istream && is, string & str)Ĭ�Ϸָ���ǡ�\ n���� ����
2.��������ļ�ĩβ��������������������г���������������ȡҲ��ֹͣ��
3.����ҵ��ָ�����������ȡ�������������洢����һ����������������ʼ����
4.��ע�⣬����֮ǰ��str�е��κ����ݶ�������ȡ�������滻��
5.ÿ����ȡ���ַ������ӵ����ַ�������ʹ��push_back()��Ч��һ����
*/
