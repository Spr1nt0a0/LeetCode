//给定一个二叉树，返回其节点的值的前序遍历
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
	TreeNode* right;
};
vector<int> preorderTraversal(TreeNode *root)
{
	stack<TreeNode*> tstack;
	vector<int> result;
	while(tstack.size()>0 || root!=NULL)
	{
		if(root!=NULL)
		{
			result.push_back(root->val);
			if(root->right!=NULL)
				tstack.push(root->right);
			root=root->left;
		}
		else
		{
			root=tstack.top();
			tstack.pop();
		}
	}
	return result;
}
void main()
{

}

