/*
 * @Author: YiFu
 * @Date: 2024-06-24 17:37:20
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-25 21:49:45
 * @FilePath: \Tree\5.symmetryTree.cpp
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

    /*judge whether left and right node are symmetry */
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)  return true;
        else if(left == NULL && right != NULL)  return false;
        else if(left != NULL && right == NULL)  return false;
        else if(left->val != right->val)  return false;

        /* compare whether left and right node of ouside tree are symmetry*/
        bool ouside = compare(left->left, left->right);
        /* compare whether left and right noode of inside tree are symmetry*/
        bool inside = compare(right->left, right->right);

        return ouside && inside;
    }

    bool isSymmetry(TreeNode* root)
    {
        if(root == NULL) return true;
        return compare(root->left, root->right);
    }

};

int main()
{
    TreeNode* root = new TreeNode;
    Solution solution;

    cout<<"Enter 0 to indicate there no children under this node "<<endl;
	cout<<"Enter val of the first node : ";
    root = solution.createTree();
    
    bool boolean = solution.isSymmetry(root);
    if (boolean)
    {
        cout<<"the tree is symmetry\n";
    }
    else
    {
        cout<<"the tree is dissymmetry\n";
    }
    

    system("pause");
    return 0;
}