/*
 * @Author: YiFu
 * @Date: 2024-06-03 22:26:15
 * @LastEditors: YiFu
 * @LastEditTime: 2024-08-03 11:30:39
 * @FilePath: \Tree\2.buildTree.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size() == 0) return NULL;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
    
        if(postorder.size() == 1) return root;
      
        int delimiterIndex;
        for(delimiterIndex = 0;  delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootValue)
            break;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;

        return traversal(inorder, postorder);
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
};

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode *root = solution.buildTree(inorder, postorder);
    cout<<root<<endl;
    solution.perorder(root);
    cout<<endl;

    system("pause");
    return 0;
}
