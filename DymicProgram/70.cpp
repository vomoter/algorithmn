/*
 * @Author: YiFu
 * @Date: 2024-05-04 21:10:37
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-04 22:05:46
 * @FilePath: \DymicProgram\70.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public :
     /**
     * @breif:  求爬楼梯的种类数
     * @parm:   n 一共有多少楼梯数
     * @parm:   m 一次爬的楼梯数 1<=m<n
     * @retval: 爬楼梯的种数
    */
    int stairsWays(int n, int m)
    {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(i - j >= 0) dp[i] +=dp[i-j];
            }
        }
        return dp[n];
    }
};

int main()
{
    int n,m;
    /*从键盘输入总楼梯数和一个爬楼梯数*/
    cin>>n>>m;
    Solution Solution;
    int result = Solution.stairsWays(n,m);
    cout<<result<<endl;



    system("pause");
    return 0;
}