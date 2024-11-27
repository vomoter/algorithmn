/*
 * @Author: YiFu
 * @Date: 2024-09-09 20:49:47
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-09 21:02:38
 * @FilePath: \Tree\1temp.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

// 定义树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 使用数组构建二叉树，0 表示该位置为空节点
TreeNode* createBinaryTree(const std::vector<int>& nums) {
    if (nums.empty() || nums[0] == 0) {
        return nullptr;
    }

    std::vector<TreeNode*> nodes(nums.size(), nullptr);

    // 将非零元素转换为树节点
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nodes[i] = new TreeNode(nums[i]);
        }
    }

    // 连接树节点
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nodes[i] != nullptr) {
            if (2 * i + 1 < nums.size() && nodes[2 * i + 1] != nullptr) {
                nodes[i]->left = nodes[2 * i + 1];
            }
            if (2 * i + 2 < nums.size() && nodes[2 * i + 2] != nullptr) {
                nodes[i]->right = nodes[2 * i + 2];
            }
        }
    }

    return nodes[0]; // 返回根节点
}

// 层序遍历打印树节点
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        std::cout << node->val << " ";
        
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    std::vector<int> nums = {5, 1, 4, 0, 0, 3, 6}; // 0 表示该位置为空节点
    TreeNode* root = createBinaryTree(nums);

    std::cout << "level order traversal: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    system("pause");
    return 0;
}
