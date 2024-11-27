
/*
 * @Author: YiFu
 * @Date: 2024-06-08 22:05:24
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-22 22:04:02
 * @FilePath: \Tree\tmp.cpp
 */
#include<iostream>
#include<queue>
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
    /*args constructor*/
   // TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode* root)
    {
        if(root == NULL) return {{0}};

        queue<TreeNode *> que;
        vector<int> result; 
        if(root!=NULL) que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            int temp = INT_MIN;
            int num1 = 0 , num2 = 0;
            
            /*there size is constantly change*/
            for(int i = 0 ; i < size; i++)
            { 
                TreeNode* node = que.front();
                que.pop();
                temp =  temp > node->val ? temp : node->val;
            //    result.push_back(temp);
                if(node->left)    que.push(node->left);
                if(node->right)   que.push(node->right);
            }
            result.push_back(temp);
        }
        return result;
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

    void perorder(TreeNode* root)
    {   
        TreeNode* node = root;
        if(node == NULL) return ;
       
        else
        {
            cout<<node->val<<" ";
            perorder(node->left);
            perorder(node->right);
        }
    }

    /*itrator diasplay arrys*/
    void dispalyElemnt(vector<int> &v)
    {
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
                cout << *it<< " ";
        }
            cout << endl;
    }
};

int main()
{
    TreeNode* root  = new TreeNode;
    Solution solution;

    cout<<"Enter 0 to indicate there no children under this node "<<endl;
	cout<<"Enter val of the first node : ";
    root = solution.createTree();

    solution.perorder(root);
    cout<<endl;
    vector<int> result = solution.levelOrder(root);
    solution.dispalyElemnt(result);

    
    system("pause");
    return 0;
}