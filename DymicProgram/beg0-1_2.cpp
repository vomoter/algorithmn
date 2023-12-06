#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
int main()
{
    vector<int> weigth={1,3,4};
    vector<int> value={15,20,30};
    int begweight=4;

    vector<int> dp(begweight+1,0);
    display(dp);
    for(int i=0;i<weigth.size();i++)
    {
        for(int j=begweight;j>=weigth[i];j--)
        {
           
            dp[j]=max(dp[j],dp[j-weigth[i]]+value[i]);     
        }
    }
    display(dp);
    cout<<dp[begweight]<<endl;

    system("pause");
    return 0;
}