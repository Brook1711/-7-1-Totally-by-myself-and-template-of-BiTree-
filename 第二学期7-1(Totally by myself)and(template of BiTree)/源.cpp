#include<iostream>
#include<vector>

using namespace std;

template<class T>
class BiNode
{
public:
	T data;
	//	BiNode<T>* parent;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};

template<class T>
class BiTree
{
private:
	void Create(BiNode<T> * &R, vector<T> &v, int i, int n);
	void Release(BiNode<T> * R);

public:

	BiNode<T> * root;
	BiTree()
	{
		root = NULL;
	}

	BiTree(vector<T>& v, int n);
	void PreOrder(BiNode<T> * R);
	void InOrder(BiNode<T> * R);
	void PostOrder(BiNode<T> * R);
	int GetHight(BiNode<T> * R);
	int GetMinHight(BiNode<T> * R);
	bool JudgeOneNode(BiNode<T> * R);
	bool JudgeEveryNode(BiNode<T> * R);
	//	void SPreOrder(BiNode<T> * R);
	//	void SInOrder(BiNode<T> * R);
	//	void SPostOrder(BiNode<T> * R);
	//	void LevelOrder(BiNode<T> * R);
	~BiTree();

};
template<class T>
void BiTree<T>::Create(BiNode<T> * &R, vector<T> &v, int i, int n)
{
	if (i <= n && v[i - 1] != '0')
	{
		R = new BiNode<T>;
		R->data = v[i - 1];
		Create(R->lchild, v, 2 * i, n);
		Create(R->rchild, v, 2 * i + 1, n);
	}
	else
		R = NULL;
}

template<class T>
void BiTree<T>::Release(BiNode<T> * R)
{
	if (R != NULL)
	{
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}

template<class T>
BiTree<T>::BiTree(vector<T>& v, int n)
{
	Create(root, v, 1, n);
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		cout << R->data;
		PreOrder(R->lchild);
		PreOrder(R->rchild);
	}
}

template<class T>
void BiTree<T>::InOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		InOrder(R->lchild);
		cout << R->data;
		InOrder(R->rchild);
	}
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		PostOrder(R->lchild);
		PostOrder(R->rchild);
		cout << R->data;
	}
}

template<class T>
bool BiTree<T>::JudgeOneNode(BiNode<T> * R)
{
	int left = GetHight(R->lchild);
	int right = GetHight(R->rchild);
	int m;
	if (left > right)
		m = left - right;
	else
		m = right - left;
	if (m > 1)
		return false;
	else
		return true;
}

template<class T>
bool BiTree<T>::JudgeEveryNode(BiNode<T> * R)
{
	if (R == NULL)
		return true;
	int leftDepth = GetHight(R->lchild);
	int rightDepth = GetHight(R->rchild);
	int diff = leftDepth - rightDepth;
	if (diff > 1 || diff < -1)
		return false;
	return JudgeEveryNode(R->lchild) && JudgeEveryNode(R->rchild);
}

template<class T>
BiTree<T>::~BiTree()
{
	Release(root);
}

template<class T>
int BiTree<T>::GetHight(BiNode<T> *R)
{
	if (R != NULL)
	{
		int m = GetHight(R->lchild);
		int n = GetHight(R->rchild);
		return (m > n ? m : n) + 1;
	}
	else
		return 0;
}

template<class T>
int BiTree<T>::GetMinHight(BiNode<T> *R)
{
	if (R != NULL)
	{
		int m = GetMinHight(R->lchild);
		int n = GetMinHight(R->rchild);
		return (m < n ? m : n) + 1;
	}
	else
		return 0;
}

int main()
{
	vector<char> v;

	char temp;
	while (cin >> temp)
	{
		v.push_back(temp);
	}
	int n = v.size();
	BiTree<char> MyTree(v, n);


	if (MyTree.JudgeEveryNode(MyTree.root))
		cout << "True";
	else
		cout << "False";

	//	cout << max << " " << min << endl;

	//	system("pause");
	return 0;
}