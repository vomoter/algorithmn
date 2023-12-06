#include<iostream>
#include<vector>
using namespace std;
int lastStoneWeight(vector<int> &v)
{
    vector<int> dp(1500,0);
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=sum/2;j>v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    return sum-dp[sum/2]-dp[sum/2];
}
int main()
{
    vector<int> v={2,4,1,1};
    cout<<lastStoneWeight(v)<<endl;

    system("pause");
    return 0;
}