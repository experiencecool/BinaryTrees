#include "TreeNode.h"


using namespace std;

TreeNode *AddElement(TreeNode *p, double k)
{
	cout << "add\n";
	if (p == 0) {
		/*cout << "create new node\n";
		p = new TreeNode;
		p->data = k;
		p->left = 0;
		p->right = 0;
		p->height = 1;
		cout << p->data << endl;
		return p;*/
		return new TreeNode(k);
	}
	if (k < (p->data)){
		cout << "in left\n";
		p->left = AddElement(p->left, k);
	}
	else {
		cout << "in right\n";
		p->right = AddElement(p->right, k);
	}
	return balance(p);
}

void out(TreeNode *p)
{
	if (!p) {
		cout << "[NULL]";
		return;
	}
	out(p->left);
	cout << p->data << " ";
	out(p->right);
	cout << "\n";
}

void printTree(TreeNode* p, int indent)
{
	if (p != 0)
	{
		if (p->right)
		{
			printTree(p->right, indent + 4);
		}
		if (indent)
		{
			std::cout << std::setw(indent) << ' ';
		}
		if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << p->data << "\n ";
		if (p->left)
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			printTree(p->left, indent + 4);
		}
	}
}

void getfromfile(TreeNode **p)
{
	ifstream fin("input.txt");
	ofstream fout("out.txt");
	double n;
	
	while (!fin.eof())
	{
		fin >> n;
		*p = AddElement(*p, n);
	}
}

//---------------

unsigned char height(TreeNode *p)
{
	return p ? p->height : 0;
}

int balancefactor(TreeNode *p)
{
	return height(p->right) - height(p->left);
}

void fixheight(TreeNode *p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

TreeNode *rotateright(TreeNode *p)
{
	TreeNode *q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TreeNode *rotateleft(TreeNode *p)
{
	TreeNode *q = p->right;
	p->right = q->left;
	q->left = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TreeNode *balance(TreeNode *p)
{
	fixheight(p);
	if (balancefactor(p) == 2) {
		if (balancefactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (balancefactor(p) == -2) {
		if (balancefactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

TreeNode *findmin(TreeNode *p)
{
	return p->left ? findmin(p->left) : p;
}

TreeNode* searchForElem(int value, TreeNode* p)
{
	if (p != 0)
	{
		if (p->data == value)
			return p;
		else
		{
			TreeNode* foundNode = searchForElem(value, p->left);
			if (foundNode == 0)
				foundNode = searchForElem(value, p->right);
			return foundNode;
		}
	}
	else
		return 0;
}

TreeNode* deleteElem(double value, TreeNode* p)
{
	if (p == 0) return p;

	if (value < p->data)
		p->left = deleteElem(value, p->left);
	else if (value > p->data)
		p->right = deleteElem(value, p->right);

	else
	{
		if (p->left == 0)
		{
			TreeNode* temp = p->right;
			delete p;
			return balance(temp);
		}
		else if (p->right == 0)
		{
			TreeNode* temp = p->left;
			delete p;
			return balance(temp);
		}

		TreeNode *temp = findmin(p->right);

		p->data = temp->data;

		p->right = deleteElem(p->data, p->right);
	}
	return balance(p);
}

void preorderTraversal(TreeNode* p)
{
	if (p == 0) return;

	std::cout << p->data << " ";
	preorderTraversal(p->left);
	preorderTraversal(p->right);
}

void inorderTraversal(TreeNode* p)
{
	if (p == 0) return;

	inorderTraversal(p->left);
	std::cout << p->data << " ";
	inorderTraversal(p->right);
}

void postorderTraversal(TreeNode* p)
{
	if (p == 0) return;

	postorderTraversal(p->left);
	postorderTraversal(p->right);
	std::cout << p->data << " ";
}