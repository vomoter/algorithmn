#include<iostream>
#include<vector>
using namespace std;

int change(int amount,vector<int> &coins)
{
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for (int i = 0; i <coins.size(); i++)
    {
       for(int j=coins[i];j<=amount;j++)
       {
            dp[j]+=dp[j-coins[i]];
       }
    }
    return dp[amount];

}

int main()
{
    vector<int> coins={1,2,5};
    int amount=5;
    cout<<change(5,coins)<<endl;

    system("pause");
    return 0;

}