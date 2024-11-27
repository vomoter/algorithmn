/*
 * @Author: YiFu
 * @Date: 2024-07-16 22:00:16
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-17 14:26:13
 * @FilePath: \Tree\8.levelOrderToArray.cpp
 */
#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> leverOrder(TreeNode *root)
    {
        if (root == NULL)  return {{0}};

        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root!=NULL)  que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp;

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(temp);
        }
    return result;    
    }

    /*recursive create binary tree*/
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
        TreeNode* root  = new TreeNode;
        Solution solution;

        cout<<"Enter 0 to indicate there no children under this node "<<endl;
        cout<<"Enter val of the first node : ";
        root = solution.createTree();

        cout<<endl;
        vector<vector<int>> result = solution.leverOrder(root);
        solution.dispalyElemnt(result);


        system("pause");
        return 0;
    }