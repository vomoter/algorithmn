/*
 * @Author: YiFu
 * @Date: 2024-07-29 21:37:02
 * @LastEditors: YiFu
 * @LastEditTime: 2024-08-03 19:50:08
 * @FilePath: \Graph\1numberOfIsland.cpp
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
    
    /* 
        @brief: BFS algorithm to find all the islands in the grid.
        @param: grid, visited, x, y, which represent the grid, visited array, current position x, y.
        @return: void
    */
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        queue<int> que;          //queue to store the position of the islands.
        que.push(x);
        que.push(y);
        visited[x][y] = true;   
        g_count++;            
        while(!que.empty())
        {
            int xx = que.front();
            que.pop();
            int yy = que.front();
            que.pop();
            for(int i = 0; i < 4; i++)
            {
                int nextX = xx + dir[i][0];
                int nextY = yy + dir[i][1];
                if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                {
                    continue;
                }
                if(grid[nextX][nextY] == 1 && !visited[nextX][nextY])
                {
                    visited[nextX][nextY] = true;
                    g_count++;
                    que.push(nextX);
                    que.push(nextY);
                }
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
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j])
            {
               //DFS handle the current node, thus reset the g_count of islands which count number begin 1.
                g_count = 0; 
                bfs(grid, visited, i, j);       //sign the current node as visited, and use BFS to find all the islands.
                result = max(result, g_count);
            }
        }
    }
    cout <<result << endl;

    system("pause");
    return 0;
}