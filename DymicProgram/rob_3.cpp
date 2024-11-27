/*
 * @Author: YiFu
 * @Date: 2024-06-05 22:29:29
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-06 12:26:52
 * @FilePath: \DymicProgram\rob_3.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
private:
    vector<int> robTree(TreeNode* root)
    {
        if(root == NULL) return vector<int>{0,0};

        vector<int> leftdp = robTree(root->left);
        vector<int> rightdp = robTree(root->right);

        int val1 = root->val + leftdp[0] + rightdp[0];
        int val2 = max(leftdp[0],leftdp[1]) +  max(rightdp[0],rightdp[1]);

        return {val2,val1};
    }
public:
    int rob(TreeNode* root)
    {
        vector<int> result = robTree(root);
        return max(result[0],result[1]);
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
    Solution solution;
    TreeNode* root = solution.createTree();
    int result  = solution.rob(root);
    
    cout<<result<<endl;



    system("pause");
    return 0;
}