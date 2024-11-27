/*
 * @Date: 2024-06-07 16:02:04
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-09 15:07:07
 * @FilePath: \DymicProgram\maxProfit.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 *  给定一个prices，它的第i个元素prices[i]表示一支
 *  给定股票第i天的价格。你只能选定一天买入，未来卖出，
 *  计算收益最大值
 */
class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] -= nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i][0] - nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }
        return dp[nums.size() - 1][1];
    }
};

int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int result = solution.maxProfit(price);
    cout << result << endl;

    system("pause");
    return 0;
}