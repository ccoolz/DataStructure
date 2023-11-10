#include <iostream>

#define CAPACITY 101	//�������������
int array[CAPACITY];	//������Ϊջ������
int top = -1;			//ջ���������һ���������±꿪ʼ����ջʱtopӦΪ-1

void Push(int data)
{
	if (top == CAPACITY - 1)
	{
		std::cout << "stack is overflow! Can not Push.\n";
		return;
	} //ջ����ֹͣpush

	top++;
	array[top] = data;
}

void Pop()
{
	if (top == -1)
	{
		std::cout << "stack is empty! Can not Pop.\n";
		return;
	}

	top--;
}

int GetTop()
{
	return array[top];
}

void Print()
{
	std::cout << "Stack:";
	for (int i = 0; i <= top; i++)
	{
		std::cout << " | " << array[i];
	}
	std::cout << " |<-TOP\nPress Enter to continue..."; std::cin.get(); std::cin.get();
}

int main()
{
	int topData = -1; //��case���ʼ���ᱨ��

	bool keep = true;
	while (keep)
	{
		std::cout
			<< "\nOPERATIONS-------\n"
			<< "1: PUSH DATA\n"
			<< "2: POP\n"
			<< "3: GET TOP DATA\n"
			<< "4: SHOW STACK\n"
			<< "0: END PROGRAM\n\n";

		std::cout << "Enter an operation number: ";
		int option;
		std::cin >> option;
		switch (option)
		{
		case 1:
			std::cout << "Data: ";
			int data;
			std::cin >> data;
			Push(data);		break;

		case 2:
			Pop();			break;

		case 3:
			topData = GetTop();
			std::cout << "Stack top's data: " << topData << "\nPress Enter to continue..."; std::cin.get(); std::cin.get();;
							break;

		case 4:
			Print();		break;

		case 0:
			keep = false;
			std::cout << "Program exists......\n";
							break;

		default:
			std::cout << "Wrong choice.\nPress Enter to continue..."; std::cin.get(); std::cin.get();
		}
	}

	return 0;
}