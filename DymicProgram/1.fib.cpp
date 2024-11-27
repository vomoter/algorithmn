/*
 * @Author: YiFu
 * @Date: 2024-06-04 21:52:55
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-04 22:01:03
 * @FilePath: \DymicProgram\1.fib.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

int fib(int n)
{
    if( n == 0 || n == 1 || n == 2) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n ; i++)
    {
        dp[i] = dp[i-1] + dp[i - 2];
    } 
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

    system("pause");
    return 0;
}