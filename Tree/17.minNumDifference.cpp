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
    TreeNode() : val(0), left(NULL), right(NULL) {}           // default constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}     // constructor
};

class Solution
{
private:
    vector<int> arr; 

    /**
     * @brief 先序遍历二叉树，将节点值存入数组
     * @param root 根节点
     * @return void
     */
    void travel(TreeNode* root)  
    {
        if(!root)   return ;
        /* 先序遍历，将节点值存入数组 */
        travel(root->left);
        arr.push_back(root->val);   
        travel(root->right);
    }

public:
    /**
     * @brief 数组转化为二叉树
     * @param nums 数组
     * @return 二叉树的根节点
     */
    TreeNode* arrToBinaryTre(vector<int>& nums)
    {
        if(nums.empty()) return NULL;    // 空数组返回空树

        std::vector<TreeNode*> nodes(nums.size(), nullptr); // 存放树节点
        // 将非零元素转换为树节点
        for (size_t i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] != 0) 
            {
                nodes[i] = new TreeNode(nums[i]);
            }
        }
        // 连接树节点
        for (size_t i = 0; i < nums.size(); ++i) 
        {
            if (nodes[i] != nullptr) 
            {
                /*构建左子树 */
                if (2 * i + 1 < nums.size() && nodes[2 * i + 1] != nullptr) 
                {
                    nodes[i]->left = nodes[2 * i + 1];
                }
                /*构建右子树 */
                if (2 * i + 2 < nums.size() && nodes[2 * i + 2] != nullptr) 
                {
                    nodes[i]->right = nodes[2 * i + 2];
                }
            }
        }
        return nodes[0];
    }

    int minNumDifference(TreeNode* root)
    {
        arr.clear();
        travel(root);
        if(arr.size() < 2)  return 0;
        int min_diff = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            min_diff = min(min_diff, abs(arr[i]) - arr[i-1]);
        }

        return min_diff;
    }

    /**
     * @brief 前序遍历二叉树
     * @param root 根节点
     * @return void
     */
    void preorder(TreeNode* root)
    {   
        TreeNode* node = root;
        if(node == NULL) return ;
        else
        {
            cout<<node->val<<" ";
            preorder(node->left);
            preorder(node->right);
        }
    }
};
int main()
{
    Solution solution;

    vector<int> nums = {5, 1, 4, 0, 0, 3, 6};       //不是平衡二叉树
    vector<int> nums2 ={2,1,3};                    //是平衡二叉树   
    vector<int> nums3 ={10, 5 ,15, 0, 0, 6, 20};   //不是平衡二叉树
    TreeNode* root = solution.arrToBinaryTre(nums2);
    cout << "The  binary tree is : " << endl;
    solution.preorder(root);
    int result = solution.minNumDifference(root);
    cout<<endl<<""<<result<<endl;
    system("pause");
    return 0;
}