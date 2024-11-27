<!--

 * @Author: YiFu
 * @Date: 2024-06-08 21:59:12
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-03 09:25:11
 * @FilePath: \Tree\Redeme.md
-->

# 二叉树
## 1.二叉树的递归遍历
```c++

```



## 2.二叉树的迭代遍历
### 2.1 前序遍历
   先处理根节点，再根据栈的特点，先把右节点放入栈中,再把
左节点放入栈中，则出栈顺序采为根左右。
```c++
       1
      / \
     2   3
    / \
   4   5
   输出：1 - 2 - 4 - 5 - 3
   vector<int> perorder(TreeNode* root)
   {
      TreeNode* cur = root;
      stack<TreeNode*> st;
      vector<int> result;
      st.push(cur);
      while(!st.empty())
      {
         cur = st.top();
         st.pop();
         result.push_back(cur->val);
         if(cur->right) st.push(cur->right);
         if(cur->left) st.push(cur->left);
      }
   }

```
### 2.2 中序遍历
```c++
       1
      / \
     2   3
    / \
   4   5
   输出：4 - 2 - 5 - 1 - 3
   vector<int> inorder(TreeNode* root)
   {
      TreeNode* cur = root;
      stack<TreeNode*> st;
      vector<int> result;
      while(!cur || !st.empty())
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
            cur= cur->right;
         }
      }
      return result;
   }
```
## 3.二叉树的层次遍历
```c++
       1
      / \
     2   3
    / \
   4   5
   输出：1 - 2 - 3 - 4 - 5
   vector<int> levelOrder(TreeNode* root)
   {
      TreeNode* cur = root;
      queue<TreeNode*> que;
      std::vector<int> result;
      que.push(cur);
      while(!cur || !que.empty())
      {
         int size = que.size();
         std::vector<int> temp;
         
         for(int i = 0 ; i < size; i++)
         {
            TreeNode* node = que.font();
            que.pop();
            temp.push_back(node->val);  
            if(cur->left)  que.push(cur->left);
            if(cur->right) que.push(cur->right);
         }
         result.push_back(temp);
      }

   }
```