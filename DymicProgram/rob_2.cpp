/*
 * @Author: YiFu
 * @Date: 2024-05-27 17:10:14
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-05 22:58:01
 * @FilePath: \DymicProgram\rob_213.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Soultion
{
private:
    int robRange(vector<int> &nums, int start, int end)
    {
        if( end == start ) return nums[start];
        vector<int> dp(nums.size(),0);
        dp[start] = nums[start];
        dp[ start + 1] = max(nums[start],nums[start + 1]);
        for (int i = start + 2; i < end; i++)
        {
            dp[i] = max( dp[i-2] + nums[i], dp[i - 1]);

        }
        return dp[end - 1];

    }
public:
    int rob(vector<int> &nums)
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 1);
        int result2 = robRange(nums, 1, nums.size());

        return max(result1,result2);
    }
};

int main()
{
    vector<int> nums = {1,2,3,1};
    Soultion Soultion;
    int result = Soultion.rob(nums);
    cout<<result<<endl;
    
    system("pause");
    return 0;
}