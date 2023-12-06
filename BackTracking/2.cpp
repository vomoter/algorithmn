#include<iostream>
#include<vector>
using namespace std;

class Soultion
{
    private:
        vector<vector<int>> result;     //存放每次组合的结果集
        vector<int> path;               //存放每次组合

        void backTracking(int targetSum,int k,int sum,int startIndex)
        {
            if(path.size()==k)
            {
                if(sum==targetSum)
                {
                    result.push_back(path);
                }
                return;
            }
            for (int i = startIndex; i <=9; i++)
            {
                path.push_back(i);
                sum+=i;
                backTracking(targetSum,k,sum,i+1);
                sum-=i;
                path.pop_back();
            }
        }

    public:
        vector<vector<int>> combine(int n,int k)
        {
            backTracking(n,k,0,1);
            return result;
        }
};

int main()
{
    vector<int> v ;
    for(int i=0;i<9;i++)
    {
        v.push_back(i+1);
    }
    Soultion s;
    vector<vector<int>> result=s.combine(9,3);
    for(vector<vector<int>>::iterator item=result.begin();item!=result.end();item++)
    {
        for(vector<int>::iterator it=(*item).begin();it!=(*item).end();it++ )
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}