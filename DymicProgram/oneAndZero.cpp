#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Soultion
{
public:
    int findMaxForm(vector<string> &str,int m,int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string temp : str)
        {
           int zeroNum=0,oneNum=0;
           for(char ch : temp)
           {
                if(ch=='0') zeroNum++;
                else        oneNum++;
           }

            for (int i = m; i >= zeroNum; i--)
            {
                for(int j = n; j >= oneNum; j--)
                {
                    dp[i][j]=max(dp[i][j], dp[i-zeroNum][j-oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    vector<string> v={"10","0001","111001","1","0"};
    Soultion s;
    int result=s.findMaxForm(v,5,3);
    cout<<result<<endl;

    system("pause");
    return 0;
}