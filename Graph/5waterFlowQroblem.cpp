/*
 * @Author: YiFu
 * @Date: 2024-08-07 11:41:40
 * @LastEditors: YiFu
 * @LastEditTime: 2024-08-08 21:47:51
 * @FilePath: \Graph\5waterFlowQroblem.cpp
 */
#include<iostream>
#include<vector>

using namespace std;

    //定义方向二维数组，用于遍历四个方向，右、左、上、下
   const int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
   void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
    {  
         //如果当前节点已经访问过，则跳过
        if (visited[x][y] == true)  return;
        visited[x][y] = true;
    
        for(int i = 0; i < 4; i++)
        {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
            {
                continue;
            }
            if(grid[nextX][nextY] > grid[x][y]) continue;  //如果下一个节点的值大于当前节点的值，则跳过
            dfs(grid, visited, nextX, nextY);
        }
        return;
    }

    bool isResult(vector<vector<int>>& grid, int x, int y)
    {
        pair<int, int> result;
        int frist = 0;
        int second = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, visited, x, y);
        bool isFirst = false;
        bool isSecond = false;

        //第一边界的上边
        for (int j = 0; j < n; j++)
        {
            if(visited[0][j]) 
            {
                isFirst = true;
                break;
            }
        }
        //第一边界的左边
        for (int i = 0; i < m; i++)
        {
            if(visited[i][0]) 
            {
                isFirst = true;           
                break;
            }
        }
        //第二边界的右边
        for(int j = 0; j < n; j++)
        {
            if(visited[n-1][j])
            {
                isSecond = true;
                break;
            }
        }
        
        //第二边界的下边
        for(int i = 0; i < n; i++)
        {       

            if(visited[i][n-1]) 
            {
                isSecond = true;    
                break;
            }
        }
        if(isFirst && isSecond) return true;
        else return false;
    }

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isResult(grid, i, j))
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    


    system("pause");
    return 0;
}