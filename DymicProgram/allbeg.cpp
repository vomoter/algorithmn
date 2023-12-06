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
    int begweigth=4;
    vector<int> dp(begweigth+1,0);

    for(int i=0;i<weigth.size();i++)
    {
        for(int j=weigth[i];j<=begweigth;j++)
        {
            dp[j]=max(dp[j],dp[j-weigth[i]]+value[i]);
        }
    }
    display(dp);

    system("pause");
    return 0;
}