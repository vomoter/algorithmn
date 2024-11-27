/*
 * @Author: YiFu
 * @Date: 2024-07-27 20:53:51
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-28 18:25:54
 * @FilePath: \Tree\dynamic.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = frame[i][j];
            }
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
            dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
            }
        }
    
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[m-1][n-1];
    }
};


int main()
{
    vector<vector<int>> frame = {{1,3,1},{1,5,1},{4,2,1}};
    Solution S;
    int m = frame.size();
    int n = frame[0].size();
  
    S.jewelleryValue(frame);
    cout<<S.jewelleryValue(frame)<<endl;

    system("pause");
    return 0;
}