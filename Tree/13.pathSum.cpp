/*
 * @Author: YiFu
 * @Date: 2024-07-25 21:41:59
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-26 17:59:50
 * @FilePath: \Tree\13.pathSum.cpp
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
    /*inorder traversal to find the path sum equal to target*/
    bool traversal(TreeNode* root, int count)
    {
        /*reach the leaf node and the count quantity is 0, return true*/
        if(root->left == NULL && root->right == NULL && count == 0)
        {
            return true;
        }
        /*reach the leaf node and return false*/
        if(!root->left && !root->right)
        {
            return false;
        }
        /*traverse left subtree*/
        if(root->left)     // if root->left is not null
        {
            count -= root->left->val;           // subtract the value of left child
            if(traversal(root->left, count))    return true;    // if find the path sum equal to target, return true
            count += root->left->val;           //backtrack, add the value of left child
        }
        /*traverse right subtree*/
        if(root->right)     // if root->right is not null
        {
            count -=root->right->val;        // subtract the value of right child
            if(traversal(root->right, count))   return true;    // if find the path sum equal to target, return true
            count += root->right->val;       //backtrack, add the value of right child
        }
        return false;      // if all the path sum equal to target not found, return false
    }


public:
    /*find the path sum equal to target*/
    bool findTargetSumPath(TreeNode* root, int target)
    {    
        if(!root)   return false;                    // if root is null, return false
        return traversal(root, target - root->val);  // call the traversal function to find the path sum equal to target
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

    //call the function to find the path sum equal to target
    bool Boolen = solution.findTargetSumPath(root,4);
    cout<<"the result are : "<<Boolen<<endl;
    system("pause");
    return 0;
}