/*
 * @Author: YiFu
 * @Date: 2024-05-27 16:22:37
 * @LastEditors: YiFu
 * @LastEditTime: 2024-11-15 20:40:16
 * @FilePath: \DymicProgram\rob_1.cpp
 * @Description: Copyright (c) 2024 by LiYiFu , All Rights Reserved.
 * @encoding: utf-8
 */

#include<iostream>
#include<vector>
using namespace std;

/**  198.打家劫舍
 *   给定一个代表每个房屋存放金额的非负
 *   整数数组，计算你能偷窃到的最高金额。
 *   不能偷相邻的两个房间。
 *    
 *    实例1：
 *    输入：[1,2,3,1]
 *    输出：4
 *    解释：偷窃1号房屋(金额=1),然后偷窃
 *    3号房屋（金额=3）。 偷窃的最高金额
 *    为 1 + 3 = 4     
 * */
class Soultion
{

public:
    int rob(vector<int> nums)
    {
        /*定义dp数组*/
        vector<int> dp(nums.size() + 1, 0);
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2 ; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
    
    return dp[nums.size()];
    }
};

int main()
{
    vector<int> nums = {1,2,3,1} ;
    // vector<int> nums  ;
    // int num;
    // while (cin>> num && num != 0)
    // {
    //     nums.push_back(num);
    // }
    
    Soultion soultion;
    int result = soultion.rob(nums);
    cout<<result<<endl;

    system("pause");
    return 0;
}