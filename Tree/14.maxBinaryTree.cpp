#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 *  definition binary tree
 */
struct TreeNode
{
    int val;         // value of TreeNode
    TreeNode *left;  // point to left TreeNode
    TreeNode *right; // point to right TreeNode
    TreeNode() : val(0), left(NULL), right(NULL) {}           // default constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}     // constructor
};

class Solution
{
private:
    /*recursively build a binary tree from vector*/
    TreeNode* traversal(vector<int>& nums)
    {
        TreeNode* root = new TreeNode(0);
        /*if nums size is 1, return root*/
        if(nums.size() == 1)
        {
            root->val = nums[0];
            return root;
        } 
        int maxValue = 0;
        int maxIndex = 0;  
       
        /*find the max value in vector and its index*/
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxIndex = i;
                break;
            }
        } 
        root->val = maxValue;

        /*build left and right subtrees nums*/
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        /*recursively build left subtree */
        if( maxIndex > 0)                // if maxIndex is 0, there is no left subtree
        {
            root->left = traversal(leftNums);
        }
        /*recursively build right subtree */
        if(maxIndex < nums.size() - 1)   // if maxIndex is nums.size() - 1, there is no right subtree
        {
            root->right = traversal(rightNums);
        }
        return root;
    }

public:
    /*find the path sum equal to target*/
    TreeNode* findMaxBinaryTre(vector<int>& nums)
    {
        if(nums.empty())     return NULL;
        return traversal(nums);
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
            root = new TreeNode();
            root->val = value;

            cout << "input " << value << " left tree : ";
            root->left = createTree();
            cout << "input " << value << " right tree : ";
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
    Solution solution;

    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = solution.findMaxBinaryTre(nums);
    cout << "The max binary tree is : " << endl;
    solution.perorder(root);
    cout<<endl;

    system("pause");
    return 0;
}