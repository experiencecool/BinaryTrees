
#include "TreeNode.h"

using namespace std;



int main()
{
	
	//TreeNode *atree = new TreeNode(3);
	TreeNode *atree = 0;

	//atree = AddElement(atree, 3.1);
	//cout << atree->data;
	//cout << atree->left;
	//cout << atree->right;
	//atree = AddElement(atree, 4.1);
	//atree = AddElement(atree, 2.1);
	//atree = AddElement(atree, 5.1);
	//getfromfile(&atree);

	//printTree(atree);
	//out(atree);
	int i = -1;
	while (i)
	{
		cout << endl;
		cout << "Chose an option: " << endl;
		cout << "1. Load a tree FoF" << endl;
		cout << "2. Print your trees" << endl;
		cout << "3. Add an element in your tree" << endl;
		//cout << "4. Delete an element in your tree" << endl;
		cout << endl;
		cout << "0. Exit!" << endl;
		cout << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			getfromfile(&atree);
			break;
		case 2:
			printTree(atree);
			break;
		case 3:
			cout << "Enter your element\n";
			double k;
			cin >> k;
			atree = AddElement(atree, k);
			break;
		case 4:
			cout << "Enter your element\n";
			double m;
			cin >> m;
			deleteElem(m, atree);
			break;
		default:
			return 0;
		}
	}
	cin >> i;
	return 0;
}
