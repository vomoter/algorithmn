/*
 * @Author: YiFu
 * @Date: 2024-11-15 20:27:58
 * @LastEditTime: 2024-11-20 19:36:39
 * @FilePath: \DymicProgram\legth_LIS1.cpp
 * @Copyright: Copyright (c) 2024 by LiYiFu , All Rights Reserved.
 * @encoding: UTF-8
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 最长递增子序列
 * 力扣题目链接(https://leetcode.cn/problems/longest-increasing-subsequence/)

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
提示：

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 104
*/
class Solution
{
public:
    /**
     * @brief 最长递增子序列
     * @param nums    整数数组
     * @return result  最长递增子序列的长度
     */
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);         // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        int result = 0;                         // 最长递增子序列的长度 result 初始化为 0
       
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {  
                    //  dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : (dp[j] + 1);
                    dp[i] = max(dp[i], dp[j] + 1);       //动态状态转移方程
                }
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution solution;
    int result = solution.lengthOfLIS(nums);
    cout << "result: " << result << endl;
    return 0;
}
