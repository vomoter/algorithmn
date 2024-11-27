/*
 * @Author: YiFu
 * @Date: 2024-07-22 11:21:12
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-23 20:56:10
 * @FilePath: \Tree\10.allPath.cpp
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
    vector<vector<int>> result;     //store paths of result vector
    vector<int> path;               //store every path of the tree
    
    /*get path of the tree, use the travle of preorder */
    void getPath(TreeNode* root)
    {
        path.push_back(root->val);
        /*if it is a leaf node, push path to the result ,and then return  */
        if(root->left == NULL && root->right == NULL)
        {
            result.push_back(path);
            return;
        }
        /*pointer to the left child the root */
        if(root->left) 
        {
            getPath(root->left);    //recursion 
            path.pop_back();        //backtrack 
        }
        /*pointer to the right child the root */
        if(root->right)
        {
            getPath(root->right);
            path.pop_back();
        }
    }
public:

    /*return all paths of the tree */
    vector<vector<int>> allPath(TreeNode* root)
    {
        result.clear();     //clear the double dimensional vector array.
        path.clear();
        getPath(root);
        return result;
    }

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

    
    vector<vector<int>> result = solution.allPath(root);
    solution.dispalyElemnt(result);
    system("pause");
    return 0;
}
