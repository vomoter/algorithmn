/*
 * @Author: YiFu
 * @Date: 2024-11-20 19:32:31
 * @LastEditTime: 2024-11-23 20:11:45
 * @FilePath: \DymicProgram\find_length_LCIS.cpp
 * @Copyright: Copyright (c) 2024 by LiYiFu , All Rights Reserved.
 * @encoding: UTF-8
 */
#include <iostream>
#include <vector>
using namespace std;
/**
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定,
如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

示例 1：
输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。

提示：
0 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9

 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1; // 连续子序列最少也是1
        std::vector<int> dp(nums.size(), 1); // 记录每个位置的最长连续递增子序列长度
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > nums[i - 1]) // 连续记录
            { 
                dp[i] = dp[i - 1] + 1;
            } 
            if (dp[i] > result) result = dp[i]; // 记录最长连续递增子序列长度
        } 
        return result;
    }
};

int main() 
{
    vector<int> nums = {1,3,5,4,7};
    Solution solution;
    int result = solution.findLengthOfLCIS(nums);
    cout<<"result ="<<result<<endl;

    system("pause");
    return 0;
}