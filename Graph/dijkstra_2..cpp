/*
 * @Author: YiFu
 * @Date: 2024-10-25 16:13:07
 * @LastEditors: YiFu
 * @LastEditTime: 2024-10-25 16:16:13
 * @FilePath: \Graph\dijkstra_2..cpp
 */
#include<iostream>
#include<vector>
#include<fstream>
#include<limits.h>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");  // 打开输入文件
    if (!inputFile) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }

    int n, m, p1, p2, val;
    inputFile >> n >> m;  // 从文件读取节点数和边数
    
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT16_MAX));  
    
    for (int i = 0; i < m; i++)
    {
        inputFile >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }
    
    inputFile.close();  // 关闭文件

    int start = 1, end = n;

    vector<int> minDist(n + 1, INT16_MAX);
    vector<bool> visited(n + 1, false);
    
    minDist[start] = 0;  
    
    for (int i = 1; i <= n; i++)
    {
        int minVal = INT16_MAX;
        int cur = 1;
        
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && minDist[v] < minVal)
            {
                minVal = minDist[v];
                cur = v;
            }
        }
        
        visited[cur] = true;
        
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && grid[cur][v] != INT16_MAX && minDist[cur] + grid[cur][v] < minDist[v])
            {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }
    
    if (minDist[end] == INT16_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minDist[end] << endl;
    }

    system("pause");
    return 0;
}
