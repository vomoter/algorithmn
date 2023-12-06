#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &v, int S)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
        }
        int bagSize=(S+sum)/2;
        if((S+sum)%2==1) return 0;
        if(abs(S)>sum)  return 0;
        vector<int> dp(bagSize+1,0);
        dp[0]=1;
        for (int i = 0; i < v.size(); i++)
        {
            for(int j=bagSize;j>=v[i];j--)
            {
                dp[j]+=dp[j-v[i]];
            }
        }
        return dp[bagSize];
    }
};



int main()
{
    vector<int> nums={1,1,1,1,1};
    Solution S;
    int result=S.findTargetSumWays(nums,3);
    cout<<result<<endl;
 
    system("pause");
    return 0;
}