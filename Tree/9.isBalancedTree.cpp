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
public:
    /*return the height of the binary tree, and if not is balanced tree retuen -1   */
    int getHeight(TreeNode *root)
    {
        // if this binary tree doesn't exist, return 0
        if (!root)   return 0;

        int leftHeight = getHeight(root->left);
        if (leftHeight == -1)   return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1)  return -1;

        
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight,rightHeight);
    }

    /*judge whether it is a balanced binary tree */
    bool isBalanced(TreeNode* root)
    {
        return getHeight(root)  != -1 ;
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
    TreeNode *root = new TreeNode;
    Solution solution;

    cout << "Enter 0 to indicate there no children under this node " << endl;
    cout << "Enter val of the first node : ";
    root = solution.createTree();

    //call isBalanced
    bool Boolean =solution.isBalanced(root);
    if(Boolean)
    {
        cout<<"It is a balanced tree."<<endl;
    }
    else
    {
        cout<<"It not a balanced tree."<< endl;
    }
    system("pause");
    return 0;
}