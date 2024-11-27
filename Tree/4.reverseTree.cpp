/*
 * @Author: YiFu
 * @Date: 2024-05-30 18:37:27
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-24 17:41:57
 * @FilePath: \Tree\4.reverseTree.cpp
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
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

    TreeNode* reverseTree(TreeNode* root)
    {
        if(!root) return root;
        swap(root->left,root->right);
        reverseTree(root->left);
        reverseTree(root->right);
        return root;
    }
    /*preorder iterative traversal*/
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode *> st;   //create a stack to iterate the binary tree
        vector<int> result;     //store result
        
        if(root == NULL) return result;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* node = st.top();       // top node of stack 
            st.pop();                        // pop top node
            result.push_back(node->val);     // push val of node to result

            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return result;       
    }

    /*inorder iterative traversal*/
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        TreeNode* cur = root;

        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }            
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    /*display the result of traversal*/
    void display(vector<int> result)
    {
        /*use iterator display element*/
        for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }  
};

int main()
{
    TreeNode* root  = new TreeNode;
    Solution solution;

    cout<<"Enter 0 to indicate there no children under this node "<<endl;
	cout<<"Enter val of the first node : ";
    root = solution.createTree();
    cout<<"preorder : "<<endl;

    root = solution.reverseTree(root);

    vector<int> preResult = solution.preorderTraversal(root);
    solution.display(preResult);

    

    system("pause");
    return 0;
}