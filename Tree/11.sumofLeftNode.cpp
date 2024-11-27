/*
 * @Author: YiFu
 * @Date: 2024-07-23 20:40:33
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-23 21:08:19
 * @FilePath: \Tree\11.sumofLeftNode.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 *  definition binary tree
 */
struct TreeNode
{
    int val;         // value of TreeNode
    TreeNode *left;  // point to left TreeNode
    TreeNode *right; // point to right TreeNode
};

class Solution
{
public:

    /*get sum of left node of the tree, use posrtorder travel  */
    int sumofLeftNode(TreeNode* root)
    {
        /*if the tree is not exist, return 0 */
        if(!root)   return 0; 
        
        int leftSum = sumofLeftNode(root->left);
        /*only the left node exist,  left */
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            leftSum = root->left->val;
        }
       
        int rightSum = sumofLeftNode(root->right);      //right 
        return leftSum + rightSum;                      //middle
    }
    /*recursively build a binary tree from keyboard input*/
    TreeNode *createTree(void)
    {
        TreeNode *root;
        int value;
        // cout<<"Please input a val of node:";
        cin >> value;
        if (value == 0)
        {
            return NULL;
        }
        else
        {
            root = new TreeNode;
            root->val = value;

            cout << "input " << value << " left tree : ";
            root->left = createTree();
            cout << "input " << value << " right tree : ";
            root->right = createTree();
        }
        return root;
    }

    /*itrator diasplay arrys*/
    void dispalyElemnt(vector<vector<int>> &temp)
    {
        for (vector<vector<int>>::iterator it = temp.begin(); it != temp.end(); it++)
        {
            for (vector<int>::iterator item = (*it).begin(); item != (*it).end(); item++)
            {
                cout << *item << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    TreeNode *root = new TreeNode;
    Solution solution;

    cout << "Enter 0 to indicate there no children under this node " << endl;
    cout << "Enter val of the first node : ";
    root = solution.createTree();

    int result = solution.sumofLeftNode(root);
    cout<<"the sum are : "<<result<<endl;
    system("pause");
    return 0;
}