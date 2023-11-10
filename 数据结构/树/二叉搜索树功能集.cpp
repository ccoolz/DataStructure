#include <iostream>
#include <queue>	//ʵ�ֲ��������Ҫ�õ�����
//BstNode: BinarySearchTree Node
//���Լ�: 5 3 7 2 4 6 1 5
#define CAPACITY 101//IsBinarySearchTree_3()�õ�

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

//---------------����������------------------
BstNode* GetNewNode(int data);							//����ڵ�

BstNode* Insert(BstNode* root, int data);				//����ڵ�

BstNode* Search(BstNode* root, int data);				//��������

int FindMin(BstNode* root);								//�ҵ���С��������ֵ
BstNode* FindMinRoot(BstNode* root);					//�ҵ���С�������ظ�

int FindMax(BstNode* root);								//�ҵ������������ֵ
BstNode* FindMaxRoot(BstNode* root);					//�ҵ�����������ظ�

int Max(int left, int right);							//�������ȴ�С

int FindHeight(BstNode* root);							//������ĸ߶�

void LevelOrderTraversal(BstNode* root);				//�������
void PreOrderTraversal(BstNode* root);					//�������
void InOrderTraversal(BstNode* root);					//�������
void PostOrderTraversal(BstNode* root);					//�������

bool IsSubTreeGreater(BstNode* subRoot, int value);		//�ж��Ƿ������ĸ����ݸ���
bool IsSubTreeLesser(BstNode* subRoot, int value);		//�ж��Ƿ������ĸ����ݸ�С
bool IsBinarySearchTree_1(BstNode* root);				//�ж��Ƿ�Ϊ��������������1

bool IsBstUtil(BstNode* root, int min, int max);		//�÷�����Ϸ�2��Util�Ǽ��ϵ���˼���Ա�IBST2ֻ�贫��һ����������	
bool IsBinarySearchTree_2(BstNode* root);				//�ж��Ƿ�Ϊ��������������2

void InOrderComparison(BstNode* root);					//�÷�����Ϸ�3
bool IsArrayOrdered(int* A);							//�÷�����Ϸ�3
bool IsBinarySearchTree_3(BstNode* root);				//�ж��Ƿ�Ϊ��������������3

BstNode* Delete(BstNode* root, int data);				//������ɾ��ָ������

BstNode* FindSuccessor(int data, BstNode* root);		//�ҵ��洢�����ݵĽڵ��������������ڵ�
//--------------------------------------------

int main()
{
	BstNode* root;	//ָ����ڵ��ָ������Ǹ��ڵ㱾��
	root = nullptr;	//��ʼ��Ϊ����

	int keep = 1;
	int op1;
	int op2;
	int data;
	char m;
	BstNode* temp = nullptr;
	while (keep)
	{
		std::cout
			<< std::endl
			<< "1 �����в���ڵ� \n"
			<< "2 ɾ��ָ������  \n"
			<< "3 �ҵ���ֵ \n"
			<< "4 ������ĸ߶� \n"
			<< "5 �����������ӡ���� \n"
			<< "6 ��ȱ�������ӡ���� \n"
			<< "7 �ҵ��洢�����ݵĽڵ��������������ڵ� \n"
			<< "8 �жϸ����Ƿ�Ϊ���������� \n"
			<< "9 ���������Ƿ���� \n"
			<< "0 �˳� \n"
			<< "���������ѡ����: ";
		std::cin >> op1;
		switch (op1)
		{
		case 1:
			std::cout << "Ҫ���������: ";
			std::cin >> data;
			root = Insert(root, data);
				break;

		case 2:
			std::cout << "Ҫɾ��������: ";
			std::cin >> data;
			temp = Delete(root, data);
			if (temp == nullptr)
				std::cout << "���ݲ����� \n";
			else
				root = temp;
				break;

		case 3:
			std::cout << "���ֵ������Сֵ(g/l): ";
			std::cin >> m;
			if (m == 'g')		std::cout << FindMax(root) << "\n";
			else if (m == 'l')	std::cout << FindMin(root) << "\n";
			else	std::cout << "ERROR: wrong letter. \n";
				break;

		case 4:
			std::cout << "�߶�: " << FindHeight(root) << "\n";
				break;

		case 5:
			std::cout << "TREE: ";
			LevelOrderTraversal(root);
			std::cout << "\n";
				break;

		case 6:
			std::cout
				<< "1 ������� \n"
				<< "2 ������� \n"
				<< "3 ������� \n"
				<< "ѡ�������ʽ��Ӧ���: ";
			std::cin >> op2;
			switch (op2)
			{
			case 1:
				std::cout << "TREE: ";
				PreOrderTraversal(root);
					break;

			case 2:
				std::cout << "TREE: ";
				InOrderTraversal(root);
					break;

			case 3:
				std::cout << "TREE: ";
				PostOrderTraversal(root);
					break;

			default:
				std::cout << "ERROR: wrong chioce. \n";
					break;
			}
			std::cout << "\n";
				break;

		case 7:
			std::cout << "��Ҫ�ҵĽڵ������: ";
			std::cin >> data;
			temp = FindSuccessor(data, root);
			if (temp == nullptr)
				std::cout << "�Ҳ��������ݻ�û�к����ڵ� \n";
			else
				std::cout << "�ýڵ�ĺ����ڵ��Ӧ������Ϊ: " << temp->data << "\n";
				break;

		case 8:
			if (IsBinarySearchTree_1(root))
				std::cout << "�����Ƕ��������� \n";
			else
				std::cout << "�������Ƕ��������� \n";
				break;

		case 9:
			std::cout << "��Ҫ���ҵ�����: ";
			std::cin >> data;
			if(Search(root, data) == nullptr)
				std::cout << "���ݲ����� \n";
			else
				std::cout << "���ݴ��� \n";
				break;

		case 0:
			keep = 0; 
				break;

		default:
			std::cout << "EEEOR: wrong chioce. \n";
				break;
		}
	}
}


BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)	//�޷����ʱһ���������������ӵĹ���
{
	if (root == nullptr)	//empty tree
	{
		root = GetNewNode(data);
		return root;
	}

	/*�������������Կ������ڵ���������������ʽ�����Եݹ��ʵ�ֲ��룬
	������ĵط�Ϊ������ʱ�����ֻص���root == nullptr �������
	��ʱ�½ڵ㱻�����ز��뵽���У���������Ӧ�������ĸ��ڵ������,
	�ݹ��������ķ���ֵ���������Ӻ��������ĸ��ڵ�
	*/
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);	
		/*��������С�ڵ�ǰ�ڵ������ʱ�����ڵ�ݹ�ز��뵽�������У�
		�ں��ʵ�λ�ò���󣨴�ʱ�ݹ鵽��root = nullptr����
		�����λ�õĸ��ڵ����������ַָ�뽨������*/
	}

	else
	{
		root->right = Insert(root->right, data);
	}

	return root; //���˲�����һ�·��ص��������root������ص������ĸ��Ĺ��̶��Ƿ��������root
}

BstNode* Search(BstNode* root, int data)
{
	if (root == nullptr)
		return nullptr;

	else if (root->data == data)
		return root;

	else if (data < root->data)
		return Search(root->left, data);

	else
		return Search(root->right, data);
}

int FindMin(BstNode* root) //����ʵ��
{
	if (root == nullptr)
	{
		std::cout << "ERROR: empty tree! \n";
		return -1;
	}

	while (root->left != nullptr)
		root = root->left;
	//����Ĳ�����FindMin()������ľֲ��������޸�root����Ӱ��main()��root��ֵ
	
	return root->data;
}

BstNode* FindMinRoot(BstNode* root)
{
	while (root->left != nullptr)
		root = root->left;
	//����Ĳ�����FindMin()������ľֲ��������޸�root����Ӱ��main()��root��ֵ

	return root;
}

int FindMax(BstNode* root) //�ݹ�ʵ�֣��߼�Ϊ�ڵݹ���������������ֵ��ֱ��������Ϊ�գ������ҵ����÷���ֵ�����ϴ��ݸ�return FindMax(root->right)��return��
{
	if (root == nullptr)
	{
		std::cout << "ERROR: empty tree! \n";
		return -1;
	}

	else if (root->right == nullptr)
		return root->data;
	//��elseif�ǵݹ����ֹ����
	//����Ĳ�����FindMin()������ľֲ��������޸�root����Ӱ��main()��root��ֵ
	
	return FindMax(root->right);
}

BstNode* FindMaxRoot(BstNode* root)
{
	if (root->right == nullptr)
		return root;
	//��elseif�ǵݹ����ֹ����
	//����Ĳ�����FindMin()������ľֲ��������޸�root����Ӱ��main()��root��ֵ

	return FindMaxRoot(root->right);
}

int Max(int left, int right)
{
	return left > right ? left : right;
}

int FindHeight(BstNode* root)
{
	if (root == nullptr)
		return -1;

	return Max( FindHeight(root->left), FindHeight(root->right)) + 1;
}

void LevelOrderTraversal(BstNode* root)
{
	if (root == nullptr)
	{
		std::cout << "Empty Tree, Can't travel! \n";
		return;
	}

	std::queue<BstNode*> Q;
	Q.push(root);

	BstNode* current;
	while (!Q.empty())
	{	//���в�Ϊ��ʱ������δ����
		current = Q.front();
		std::cout << current->data << " ";
		if (current->left != nullptr) Q.push(current->left);
		if (current->right != nullptr) Q.push(current->right);
		Q.pop();
	}
}

void PreOrderTraversal(BstNode* root)
{
	if (root == nullptr) return;

	std::cout << root->data << " ";
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

void InOrderTraversal(BstNode* root)
{
	if (root == nullptr) return;

	InOrderTraversal(root->left);
	std::cout << root->data << " ";
	InOrderTraversal(root->right);
}

void PostOrderTraversal(BstNode* root)
{
	if (root == nullptr) return;
	
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	std::cout << root->data << " ";
}

bool IsSubTreeGreater(BstNode* subRoot, int value)
{
	if (subRoot == nullptr)
		return true;

	if (FindMin(subRoot) >= value)
		return true;
	else
		return false;
}
bool IsSubTreeLesser(BstNode* subRoot, int value)
{
	if (subRoot == nullptr)
		return true;

	if (FindMax(subRoot) <= value)
		return true;
	else
		return false;
}
bool IsBinarySearchTree_1(BstNode* root)	//�÷���ÿ�ζ�Ҫ����һ�������ҵ����\Сֵ��Ч�ʽϵ�
{
	if (root == nullptr)
		return true;	//�����ҵ�ͷ�ˣ�ֱ�ӷ���true

	if (IsSubTreeLesser(root->left, root->data) &&		//�������������ֵ��
		IsSubTreeGreater(root->right, root->data) &&	//������������СֵС
		IsBinarySearchTree_1(root->left) &&				//������Ҳ�������������
		IsBinarySearchTree_1(root->right))				//������Ҳ�������������
		return true;
	else
		return false;
}

bool IsBstUtil(BstNode* root, int min, int max)
{
	if (root == nullptr)
		return true;

	if (root->data >= min &&
		root->data <= max &&
		IsBstUtil(root->left, INT_MIN, root->data) &&
		IsBstUtil(root->right, root->data, INT_MAX))
		return true;
	else
		return false;
} 
bool IsBinarySearchTree_2(BstNode* root)
{
	return IsBstUtil(root, INT_MIN, INT_MAX); //INT_MIN��INT_MAX�Ǻ꣬����int���������ֵ����Сֵ�����������������
}
/*�˷����Ƚϵ���ÿ���ڵ�Ӧ�� �������������󣬱�����������С �������ڡ�
�Ӹ��ڵ㿪ʼ�����ڵ�����������ȣ����ڵ����������Ӧ��[������, ���ڵ�]������
���ڵ������������Ӧ��[���ڵ㣬������]�����ڣ��Դ˵ݹ���ÿ����֦��Ҷ�ӽڵ�*/

int A[CAPACITY];
int n = 0;
void InOrderComparison(BstNode* root)
{
	if (root == nullptr)
		return;

	InOrderComparison(root->left);
	A[n] = root->data;
	n++;
	InOrderComparison(root->right);
}
bool IsArrayOrdered(int* A, int length) 
{
	for (int j = 0; j < length - 1; j++)
	{
		if (A[j] > A[j + 1])
			return false;
	}

	return true;
}
bool IsBinarySearchTree_3(BstNode* root)
{
	InOrderComparison(root);		//����������ǰ�������-��-�������������ݴ�С�����˳��������ڱ����Ĺ����н�������������A��
	return IsArrayOrdered(A, n);	//�������A�е������Ƿ��Ǵ�С��������ģ�����ǣ������Ϊ����������
}

BstNode* Delete(BstNode* root, int value)	//����ɾ����ĸ��ڵ㣬��Ϊԭ���ڵ���ܱ�ɾ���������ĸ�ͬ�����
{
	if (root == nullptr)
		return root;

	else if (value < root->data)
		root->left = Delete(root->left, value);	//���Ҫ��������С�ڸ��ڵ��ֵ���ڸ��ڵ����������Ѱ�ң�ͬʱ����ɾ���ڵ��ǰ�ĸ�

	else if (value > root->data)
		root->right = Delete(root->right, value); //���Ҫ�������ݴ��ڸ��ڵ��ֵ���ڸ��ڵ����������Ѱ�ң�ͬʱ����ɾ���ڵ��ǰ�ĸ�

	else //��ʱ�ҵ�����value��ȵĽڵ�
	{
		//case1: no child
		if (root->left == nullptr && root->right == nullptr)
		{
			BstNode* temp = root;
			root = nullptr;
			delete temp;
		}	//��root�ڵ�ɾ���󣬷���һ��nullֵ����Ҷ�ӽڵ�ɾ�������ĸ��ڵ���null����

		//case2: one child
		else if (root->left == nullptr)	//�ýڵ�ֻ���ҽڵ㣬û����ڵ�
		{
			BstNode* temp = root;
			root = root->right;
			delete temp;	//��Ϊelse�����if��䣬����ֵʱ�Զ���������
		}
		
		else if (root->right == nullptr)	//�ýڵ�ֻ���ҽڵ㣬û����ڵ�
		{
			BstNode* temp = root;
			root = root->left;
			delete temp;	//��Ϊelse�����if��䣬����ֵʱ�Զ���������
		}

		//case3: two children
		else
		{
			BstNode* temp = FindMinRoot(root->right); //�ҵ��������е���Сֵ
			root->data = temp->data; //����ֵ����Ҫɾ���Ľڵ�
			root->right = Delete(root->right, temp->data); //����Ҫ�ҵ����������Ǹ��ظ�ֵ���ݹ�ؽ���ɾ��
		}	//������û������ɾ��ԭҪɾ���ڵ㣬ȡ����֮���Ǹ���ֵ��ɾ���ظ��ڵ㣬��˲��ø���rootֵ
	}

	return root;
}

BstNode* FindSuccessor(int data, BstNode* root)
{
	BstNode* temp = Search(root, data);
	if (temp == nullptr)
	{
		return nullptr;
	}	//�Ҳ��������ݣ��˳�

	//�ҵ������ݶ�Ӧ�Ľڵ�󣬷�������
	//case1: has right subtree
	if (temp->right != nullptr)	//��������
	{
		return FindMinRoot(temp->right);
	}	//�ڸýڵ�����������ҵ�����Сֵ���Ǹýڵ���������ĺ����ڵ�

	else //û��������
	{
		BstNode* ancestor = root;	//�Ӹ��ڵ㿪ʼ����������
		BstNode* successor = nullptr;
		while (ancestor != temp)	//���������ң�ֻҪ�ҵ��Ľڵ��temp��͸���successor(�����ڵ�)��ֱ������Ŀ��ڵ�
		{
			if (temp->data >= ancestor->data)	//��ǰ����ֵ��С�����������м���������
				ancestor = ancestor->right;
				
			else	//��ǰ����ֵ�󣬸���successor�����������м�����
			{
				successor = ancestor;	//Ŀǰ�����ֵ��������ȸ���Ϊ��̽ڵ�
				ancestor = ancestor->left;
			}
		}
		return successor;
	}
}