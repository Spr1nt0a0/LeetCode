//����һ����������ȷ�����Ƿ��Ǹ߶�ƽ��ģ�������һ���ڵ�����֮�����1
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode{
    //int value;
    TreeNode* left;
	TreeNode* right;
};
int getbalanced(TreeNode *node)
{
	if(node==NULL)
		return 0;
	int left=getbalanced(node->left);
	if(left==-1)
		return -1;
	int right=getbalanced(node->right);
	if(right==-1)
		return -1;
	if(left-right>1||right-left>1)
		return -1;
	return left>right? left+1:right+1;
}
bool isbalanced(TreeNode *root)
{
	if(root==NULL)
		return true;
	int val=getbalanced(root);
	if(val==-1)
		return false;
	return true;
}

void main()
{

}
