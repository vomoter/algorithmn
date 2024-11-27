/*
 * @Author: YiFu
 * @Date: 2024-08-06 21:31:01
 * @LastEditors: YiFu
 * @LastEditTime: 2024-08-07 10:58:57
 * @FilePath: \Graph\3.totalArea.cpp
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


    //define array of direction, which is 4 directions in total. 
    //up,down, left, right
    const int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int g_count = 0;  //count the number of islands.

    /*
        @brief: DFS algorithm to find all the islands in the grid.
        @param: grid, visited, x, y, which represent the grid, visited array, current position x, y.
        @return: void
    */
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
    {   
        grid[x][y] = 0;         //把当前节点标记为0，变为海洋，排除与其他岛屿的干扰。
        g_count++;
        for(int i = 0; i < 4; i++)
        {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
            {
                continue;
            }
            if(grid[nextX][nextY] == 1 &&!visited[nextX][nextY])
            {
                visited[nextX][nextY] = true;
                g_count++;
                dfs(grid, visited, nextX, nextY);
            }    
        }
    }
    
int main()
{
    int m, n;
    int count;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int result = 0;

    //从左侧边，和右侧边，向中间遍历
    for(int i = 0; i < m; i++)
    {
        if(grid[i][0] == 1 ) dfs(grid, visited, i, 0);  
        if(grid[i][n-1] == 1 ) dfs(grid, visited, i, n-1);
    }
    //从上侧边，和下侧边，向中间遍历
    for(int j=0; j<n; j++)
    {
        if(grid[0][j] == 1 ) dfs(grid, visited, 0, j);
        if(grid[m-1][j] == 1 ) dfs(grid, visited, m-1, j);
    }

    g_count = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1 )
            {
                dfs(grid, visited, i, j);
            }   
        }
    }
    cout <<g_count<< endl;

    system("pause");
    return 0;
}