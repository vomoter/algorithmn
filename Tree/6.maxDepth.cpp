/*
 * @Author: YiFu
 * @Date: 2024-07-03 22:40:07
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-03 22:51:17
 * @FilePath: \Tree\6.maxDepth.cpp
 */
#include<iostream>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;

};

class Solution
{
public:

    /*recursive create binary tree*/
    TreeNode* createTree(void)
    {
        TreeNode * root;
        int value;
        //cout<<"Please input a val of node:";
        cin>>value;
        if(value == 0) 
        {
            return NULL;
        }
        else
        {
            root = new TreeNode;
            root->val = value;
            
        cout<<"input "<<value<<" left tree : ";
        root->left = createTree();
        cout<<"input "<<value<<" right tree : ";
        root->right = createTree();
        }
        return root;    
    }

    /*cursive get max depth of the tree */
    int maxDepth(TreeNode* node)
    {
    
        if(!node) return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return 1+max(leftDepth,rightDepth);
    }


};

int main()
{
    TreeNode* root = new TreeNode;
    Solution solution;

    cout<<"Enter 0 to indicate there no children under this node "<<endl;
	cout<<"Enter val of the first node : ";
    root = solution.createTree();
    int depth = solution.maxDepth(root);
    cout<<"max depth:"<<depth<<endl;

    system("pause");
    return 0;
}