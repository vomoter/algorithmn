#include <iostream>
#include <vector>
using namespace std;

/**
 *  definition binary tree
 */
struct TreeNode
{
    int val;                                             // value of TreeNode
    TreeNode *left;                                      // point to left TreeNode
    TreeNode *right;                                     // point to right TreeNode
    TreeNode() : val(0), left(NULL), right(NULL) {}      // default constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // constructor
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
    void travel(TreeNode *root)
    {
        if (!root)
            return;
        /* 先序遍历，将节点值存入数组 */
        travel(root->left);
        arr.push_back(root->val);
        travel(root->right);
    }

public:
    /**
     * @brief 获取二叉树节点数量
     * @param root 根节点
     * @return 节点数量
     */
    int getNodesNum(TreeNode *root)
    {
        if (!root)
            return 0;
        /* 先序遍历，将节点值存入数组 */
        return 1 + getNodesNum(root->left) + getNodesNum(root->right);
    }

    /**
     * @brief 数组转化为二叉树
     * @param nums 数组
     * @return 二叉树的根节点
     */
    TreeNode *arrToBinaryTre(vector<int> &nums)
    {
        if (nums.empty())
            return NULL; // 空数组返回空树

        std::vector<TreeNode *> nodes(nums.size(), nullptr); // 存放树节点
        // 将非零元素转换为树节点
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nodes[i] = new TreeNode(nums[i]);
                cout << "node " << i << " is " << nodes[i]->val << endl;
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

    vector<int> findMode(TreeNode *root)
    {
        arr.clear();
        travel(root);
        int n = getNodesNum(root);
        vector<int> map(n + 1, 0);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; i < arr.size(); j++)
            {
                if (arr[j] == i)
                {
                    map[i]++;
                }

            }
            cout<<endl;
            cout<<"arr size is "<<arr.size()<<" and map size is "<<map.size()<<endl;
        }
        return map;
    }

    /**
     * @brief 前序遍历二叉树
     * @param root 根节点
     * @return void
     */
    void preorder(TreeNode *root)
    {
        TreeNode *node = root;
        if (node == NULL)
            return;
        else
        {
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
};
int main()
{
    Solution solution;

    vector<int> nums = {1, 0, 2, 0, 0, 2};     //是平衡二叉树
    TreeNode *root = solution.arrToBinaryTre(nums);
    cout << "The binary tree is :" << endl;
    solution.preorder(root);
    vector<int> result = solution.findMode(root);
    cout<<endl<<"node nums of the binary tree are :"<<solution.getNodesNum(root)<<endl;
    cout<<"----------"<<endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}