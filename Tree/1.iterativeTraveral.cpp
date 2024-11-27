
/*
 * @Author: YiFu
 * @Date: 2024-05-30 18:37:27
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-20 22:06:56
 * @FilePath: \Tree\1.iterativeTraveral.cpp
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

    /*postorder iterative traversal*/
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<TreeNode* > st;
        vector<int> result;

        st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);

            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        /*reverse resultArray gain the last result*/
        reverse(result.begin(), result.end());  
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
    vector<int> preResult = solution.preorderTraversal(root);
    solution.display(preResult);

    cout<<"inorder : "<<endl;
    vector<int> inorderResult = solution.inorderTraversal(root);
    
    solution.display(inorderResult);
    cout<<"postorder : "<<endl;
    vector<int> postResult = solution.postorderTraversal(root);
    solution.display(postResult);

    system("pause");
    return 0;
}