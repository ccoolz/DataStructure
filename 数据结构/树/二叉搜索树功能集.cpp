#include <iostream>
#include <queue>	//实现层序遍历需要用到队列
//BstNode: BinarySearchTree Node
//测试集: 5 3 7 2 4 6 1 5
#define CAPACITY 101//IsBinarySearchTree_3()用到

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

//---------------函数声明区------------------
BstNode* GetNewNode(int data);							//申请节点

BstNode* Insert(BstNode* root, int data);				//插入节点

BstNode* Search(BstNode* root, int data);				//查找数据

int FindMin(BstNode* root);								//找到最小数，返回值
BstNode* FindMinRoot(BstNode* root);					//找到最小数，返回根

int FindMax(BstNode* root);								//找到最大数，返回值
BstNode* FindMaxRoot(BstNode* root);					//找到最大数，返回根

int Max(int left, int right);							//两整数比大小

int FindHeight(BstNode* root);							//检测树的高度

void LevelOrderTraversal(BstNode* root);				//层序遍历
void PreOrderTraversal(BstNode* root);					//先序遍历
void InOrderTraversal(BstNode* root);					//中序遍历
void PostOrderTraversal(BstNode* root);					//后序遍历

bool IsSubTreeGreater(BstNode* subRoot, int value);		//判断是否子树的根数据更大
bool IsSubTreeLesser(BstNode* subRoot, int value);		//判断是否子树的根数据更小
bool IsBinarySearchTree_1(BstNode* root);				//判断是否为二叉搜索树方法1

bool IsBstUtil(BstNode* root, int min, int max);		//该方法配合法2，Util是集合的意思，以便IBST2只需传入一个树根参数	
bool IsBinarySearchTree_2(BstNode* root);				//判断是否为二叉搜索树方法2

void InOrderComparison(BstNode* root);					//该方法配合法3
bool IsArrayOrdered(int* A);							//该方法配合法3
bool IsBinarySearchTree_3(BstNode* root);				//判断是否为二叉搜索树方法3

BstNode* Delete(BstNode* root, int data);				//在树中删除指定数据

BstNode* FindSuccessor(int data, BstNode* root);		//找到存储该数据的节点的中序遍历后续节点
//--------------------------------------------

int main()
{
	BstNode* root;	//指向根节点的指针而不是根节点本身
	root = nullptr;	//初始化为空树

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
			<< "1 在树中插入节点 \n"
			<< "2 删除指定数据  \n"
			<< "3 找到最值 \n"
			<< "4 检查树的高度 \n"
			<< "5 层序遍历并打印数据 \n"
			<< "6 深度遍历并打印数据 \n"
			<< "7 找到存储该数据的节点的中序遍历后续节点 \n"
			<< "8 判断该树是否为二叉搜索树 \n"
			<< "9 查找数据是否存在 \n"
			<< "0 退出 \n"
			<< "请输入序号选择功能: ";
		std::cin >> op1;
		switch (op1)
		{
		case 1:
			std::cout << "要插入的数据: ";
			std::cin >> data;
			root = Insert(root, data);
				break;

		case 2:
			std::cout << "要删除的数据: ";
			std::cin >> data;
			temp = Delete(root, data);
			if (temp == nullptr)
				std::cout << "数据不存在 \n";
			else
				root = temp;
				break;

		case 3:
			std::cout << "最大值还是最小值(g/l): ";
			std::cin >> m;
			if (m == 'g')		std::cout << FindMax(root) << "\n";
			else if (m == 'l')	std::cout << FindMin(root) << "\n";
			else	std::cout << "ERROR: wrong letter. \n";
				break;

		case 4:
			std::cout << "高度: " << FindHeight(root) << "\n";
				break;

		case 5:
			std::cout << "TREE: ";
			LevelOrderTraversal(root);
			std::cout << "\n";
				break;

		case 6:
			std::cout
				<< "1 先序遍历 \n"
				<< "2 中序遍历 \n"
				<< "3 后序遍历 \n"
				<< "选择遍历方式对应序号: ";
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
			std::cout << "您要找的节点的数据: ";
			std::cin >> data;
			temp = FindSuccessor(data, root);
			if (temp == nullptr)
				std::cout << "找不到该数据或没有后续节点 \n";
			else
				std::cout << "该节点的后续节点对应的数据为: " << temp->data << "\n";
				break;

		case 8:
			if (IsBinarySearchTree_1(root))
				std::cout << "该树是二叉搜索树 \n";
			else
				std::cout << "该树不是二叉搜索树 \n";
				break;

		case 9:
			std::cout << "您要查找的数据: ";
			std::cin >> data;
			if(Search(root, data) == nullptr)
				std::cout << "数据不存在 \n";
			else
				std::cout << "数据存在 \n";
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

BstNode* Insert(BstNode* root, int data)	//无法理解时一步步画出建立链接的过程
{
	if (root == nullptr)	//empty tree
	{
		root = GetNewNode(data);
		return root;
	}

	/*搜索二叉树可以看作根节点与两个子树的形式，可以递归地实现插入，
	当插入的地方为空子树时，则又回到了root == nullptr 的情况，
	此时新节点被真正地插入到树中，并建立相应的与它的父节点的链接,
	递归的最后，最后的返回值即建立连接后整个树的根节点
	*/
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);	
		/*插入数据小于当前节点的数据时，将节点递归地插入到左子树中，
		在合适的位置插入后（此时递归到了root = nullptr），
		与插入位置的父节点的左子树地址指针建立链接*/
	}

	else
	{
		root->right = Insert(root->right, data);
	}

	return root; //除了插入那一下返回的是上面的root，后面回到真正的根的过程都是返回这里的root
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

int FindMin(BstNode* root) //迭代实现
{
	if (root == nullptr)
	{
		std::cout << "ERROR: empty tree! \n";
		return -1;
	}

	while (root->left != nullptr)
		root = root->left;
	//传入的参数是FindMin()函数里的局部变量，修改root不会影响main()中root的值
	
	return root->data;
}

BstNode* FindMinRoot(BstNode* root)
{
	while (root->left != nullptr)
		root = root->left;
	//传入的参数是FindMin()函数里的局部变量，修改root不会影响main()中root的值

	return root;
}

int FindMax(BstNode* root) //递归实现，逻辑为在递归地右子树中找最大值，直到右子树为空，代表被找到，该返回值被不断传递给return FindMax(root->right)的return中
{
	if (root == nullptr)
	{
		std::cout << "ERROR: empty tree! \n";
		return -1;
	}

	else if (root->right == nullptr)
		return root->data;
	//该elseif是递归的终止条件
	//传入的参数是FindMin()函数里的局部变量，修改root不会影响main()中root的值
	
	return FindMax(root->right);
}

BstNode* FindMaxRoot(BstNode* root)
{
	if (root->right == nullptr)
		return root;
	//该elseif是递归的终止条件
	//传入的参数是FindMin()函数里的局部变量，修改root不会影响main()中root的值

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
	{	//队列不为空时，遍历未结束
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
bool IsBinarySearchTree_1(BstNode* root)	//该方法每次都要遍历一次子树找到最大\小值，效率较低
{
	if (root == nullptr)
		return true;	//子树找到头了，直接返回true

	if (IsSubTreeLesser(root->left, root->data) &&		//比左子树的最大值大
		IsSubTreeGreater(root->right, root->data) &&	//比右子树的最小值小
		IsBinarySearchTree_1(root->left) &&				//左子树也满足二叉搜索树
		IsBinarySearchTree_1(root->right))				//右子树也满足二叉搜索树
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
	return IsBstUtil(root, INT_MIN, INT_MAX); //INT_MIN和INT_MAX是宏，代表int型数的最大值和最小值，这里替代正负无穷
}
/*此方法比较的是每个节点应在 比它的左子树大，比它的右子树小 的区间内。
从根节点开始，根节点与正负无穷比，根节点的左子树根应在[负无穷, 根节点]区间内
根节点的右子树根与应在[根节点，正无穷]区间内，以此递归至每条树枝的叶子节点*/

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
	InOrderComparison(root);		//中序遍历就是按左子树-根-右子树，即数据从小到大的顺序遍历，在遍历的过程中将数据填入数组A中
	return IsArrayOrdered(A, n);	//检查数组A中的数据是否是从小到大排序的，如果是，则该树为二叉排序树
}

BstNode* Delete(BstNode* root, int value)	//返回删除后的根节点，因为原根节点可能被删除，子树的根同样如此
{
	if (root == nullptr)
		return root;

	else if (value < root->data)
		root->left = Delete(root->left, value);	//如果要查找数据小于根节点的值，在根节点的左子树中寻找，同时更新删除节点后当前的根

	else if (value > root->data)
		root->right = Delete(root->right, value); //如果要查找数据大于根节点的值，在根节点的右子树中寻找，同时更新删除节点后当前的根

	else //此时找到了与value相等的节点
	{
		//case1: no child
		if (root->left == nullptr && root->right == nullptr)
		{
			BstNode* temp = root;
			root = nullptr;
			delete temp;
		}	//将root节点删除后，返回一个null值，即叶子节点删除后，它的父节点与null相连

		//case2: one child
		else if (root->left == nullptr)	//该节点只有右节点，没有左节点
		{
			BstNode* temp = root;
			root = root->right;
			delete temp;	//因为else上面的if语句，返回值时自动建立连接
		}
		
		else if (root->right == nullptr)	//该节点只有右节点，没有左节点
		{
			BstNode* temp = root;
			root = root->left;
			delete temp;	//因为else上面的if语句，返回值时自动建立连接
		}

		//case3: two children
		else
		{
			BstNode* temp = FindMinRoot(root->right); //找到右子树中的最小值
			root->data = temp->data; //将该值赋给要删除的节点
			root->right = Delete(root->right, temp->data); //现在要找到右子树中那个重复值，递归地将它删掉
		}	//这个情况没有真正删除原要删除节点，取而代之的是覆盖值后删除重复节点，因此不用更新root值
	}

	return root;
}

BstNode* FindSuccessor(int data, BstNode* root)
{
	BstNode* temp = Search(root, data);
	if (temp == nullptr)
	{
		return nullptr;
	}	//找不到该数据，退出

	//找到该数据对应的节点后，分类讨论
	//case1: has right subtree
	if (temp->right != nullptr)	//有右子树
	{
		return FindMinRoot(temp->right);
	}	//在该节点的右子树中找到的最小值就是该节点中序遍历的后续节点

	else //没有右子树
	{
		BstNode* ancestor = root;	//从根节点开始找最深祖先
		BstNode* successor = nullptr;
		while (ancestor != temp)	//不断向下找，只要找到的节点比temp大就更新successor(后续节点)，直到到达目标节点
		{
			if (temp->data >= ancestor->data)	//当前祖先值更小，在右子树中继续找祖先
				ancestor = ancestor->right;
				
			else	//当前祖先值大，更新successor后在左子树中继续找
			{
				successor = ancestor;	//目前最深的值更大的祖先更新为后继节点
				ancestor = ancestor->left;
			}
		}
		return successor;
	}
}