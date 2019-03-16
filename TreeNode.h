#ifndef TREENODE_H
#define TREENODE_H

#include "staff.h"

struct TreeNode
{
	double data;
	unsigned char height;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {};
	TreeNode(double k) { data = k; left = right = 0; height = 1; }
};

TreeNode *AddElement(TreeNode *p, double k);
void out(TreeNode *p);
void printTree(TreeNode* p, int indent = 0);
void getfromfile(TreeNode **p);

unsigned char height(TreeNode *p);
int balancefactor(TreeNode *p);
void fixheight(TreeNode *p);
TreeNode *rotateright(TreeNode *p);
TreeNode *rotateleft(TreeNode *p);
TreeNode *balance(TreeNode *p);
TreeNode *findmin(TreeNode *p);
TreeNode* searchForElem(int value, TreeNode* p);
TreeNode* deleteElem(double value, TreeNode* p);
void preorderTraversal(TreeNode* p);
void inorderTraversal(TreeNode* p);
void postorderTraversal(TreeNode* p);



#endif // !TREENODE_H
