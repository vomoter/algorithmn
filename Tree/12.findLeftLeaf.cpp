/*
 * @Author: YiFu
 * @Date: 2024-07-24 18:07:11
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-24 21:44:46
 * @FilePath: \Tree\12.findLeftLeaf.cpp
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
private:
    int maxDepth = INT16_MIN;
    int result = 0;

    void traversal(TreeNode* root, int depth)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if(root->left)
        { 
            traversal(root->left, depth + 1);
        }

        if(root->right)
        {
            traversal(root->right,depth + 1);
        }
        return;
    }


public:

    int findLeftLeafValue(TreeNode* root)
    {    
        traversal(root, 0);
        return result;
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

    int sum = solution.findLeftLeafValue(root);
    cout<<"the sum are : "<<sum<<endl;
    system("pause");
    return 0;
}