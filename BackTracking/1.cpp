#include<iostream>
#include<vector>
using namespace std;
class Soultion
{
    private:
        vector<vector<int>> result;
        vector<int> path;

        void backTracking(int n,int k,int startIndex)
        {
            if(path.size()==k)
            {
                result.push_back(path);
                return;
            }
            for (int i = startIndex; i <= n; i++)
            {
                path.push_back(i);
                backTracking(n,k,i+1);
                path.pop_back();
            }
        }

    public:
        vector<vector<int>> combine(int n,int k)
        {
            backTracking(n,k,1);
            return result;
        }
};

int main()
{
    vector<int> v={1,2,3,4};
    Soultion s;
    vector<vector<int>> result=s.combine(v.size(),2);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}