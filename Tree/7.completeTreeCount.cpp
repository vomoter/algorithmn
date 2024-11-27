/*
 * @Author: YiFu
 * @Date: 2024-07-15 20:13:23
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-16 22:14:26
 * @FilePath: \Tree\7.completeTreeCount.cpp
 */
#include<iostream>
#include<vector>
using namespace std;
/**
 *  definition binary tree 
 */
struct TreeNode
{
    int val;            //value of TreeNode
    TreeNode *left;     //point to left TreeNode
    TreeNode *right;    //point to right TreeNode
};
class Solution
{
public:
    /*get node sum of the complete binary tree*/
    int GetNodeSum(TreeNode* root)
    {
        if(!root)   return 0;               //if root is null, return 0
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        /*get node sum of the left child tree  */
        while(left)
        {
            left = left->left;
            leftDepth++;
        }
        
        /*get node sum of the right child tree */
        while (right)
        {
            right = right->right;
            rightDepth++;
        }

        /*if it is a complete binary tree, use the formula to calculate */
        if(leftDepth == rightDepth)
        {
            return (2<<leftDepth) - 1;
        }
        
        return GetNodeSum(root->left) + GetNodeSum(root->right) + 1;

    }
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
};

int main()
{
    TreeNode* root  = new TreeNode;
    Solution solution;

    cout<<"Enter 0 to indicate there no children under this node "<<endl;
	cout<<"Enter val of the first node : ";
    root = solution.createTree();

    /*get node sum of the complete binary tree. */
    cout<<"node sum are :"<<solution.GetNodeSum(root)<<endl;



    system("pause");
    return 0;
}