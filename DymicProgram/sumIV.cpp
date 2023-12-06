#include<iostream>
#include<vector>
using namespace std;
class Soultion
{
    public:
    int findSumWays(vector<int> &v,int target)
    {
        vector<int> dp(v.size()+1,0);
        dp[0]=1;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<=target;j++)
            {
                dp[j]+=dp[j-v[i]];
            }
        }
        return dp[target];
    }
};
int main()
{
    vector<int> nums={1,2,3};
    int target=4;
    Soultion S;
    int result=S.findSumWays(nums,target);
    cout<<result<<endl;
    system("pause");
    return 0;
}
