/*
 * @Author: YiFu
 * @Date: 2024-06-02 22:19:44
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-02 22:30:27
 * @FilePath: \CodeCpp\algorithmn\DymicProgram\bag0-1_1.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Soultion
{
public:
    int getWay(int n, int m)
    {
        vector<int> dp( n + 1, 0);
        if(m > n) return 0;

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 2; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(i - j)
                {
                    dp[i] += dp[i - j];
                }
            }

        }    
        return dp[n];
    }    

};

int main()
{
    int m,n;
    cin>>n>>m;
    Soultion soultion;
    int result = soultion.getWay(n,m);
    cout<<result<<endl;



    system("pause");
    return 0;
}