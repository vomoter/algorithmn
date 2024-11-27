/*
 * @nums1uthor: YiFu
 * @Date: 2024-11-23 20:08:46
 * @LastEditTime: 2024-11-23 20:26:53
 * @FilePath: \DymicProgram\1.find_length.cpp
 * @Copyright: Copyright (c) 2024 by LiYiFu , nums1ll Rights Reserved.
 * @encoding: UTF-8
 */
#include <iostream>
#include <vector>
using namespace std;

/***
 * 给两个整数数组 nums1 和 nums2 ,返回两个数组中公共的、长度最长的子数组的长度。

示例：

输入：

nums1: [1,2,3,2,1]
nums2: [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3, 2, 1] 。
提示：

1 <= len(nums1), len(nums2) <= 1000
0 <= nums1[i], nums2[i] < 100

 */

class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() == 0 || nums2.size() == 0)
        {
            return 0;
        }
        int max = -1;
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                if(dp[i][j] > max)
                {
                    max = dp[i][j];
                }
            }
        }
        return max;
    }
};

int main()
{
    vector<int> nums1={1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    Solution solution;
    int result = solution.findLength(nums1,nums2);
    cout<<result<<endl;


    system("pause");
    return 0;
}