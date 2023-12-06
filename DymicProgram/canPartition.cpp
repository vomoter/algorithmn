#include<iostream>
#include<vector>
using namespace std;
bool canPartition(vector<int> &v)
{
    vector<int> dp(1001,0);
    int sum=0;
    for (int i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }
    if(sum%2==1)  return false;
    for(int i=0;i<v.size();i++)
    {
        for(int j=sum/2;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }

    return true;
}
int main()
{
    vector<int> v={1,5,11,5,9};
    cout<<canPartition(v)<<endl;


    system("pause");
    return 0;
}
