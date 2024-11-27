/*
 * @Author: YiFu
 * @Date: 2024-09-26 21:30:47
 * @LastEditors: YiFu
 * @LastEditTime: 2024-10-25 16:11:10
 * @FilePath: \Graph\dijkstra.cpp
 */
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n, m, p1, p2, val;
    cin>>n>>m;  //n为节点数，m为边数
    
    vector<vector<int>> grid(n+1, vector<int>(n+1, INT16_MAX));
    /*初始化源点到其他节点的距离*/
    for(int i = 0; i < m; i++)
    {
        cin>>p1>>p2>>val;
        grid[p1][p2] = val;
    }

    int start = 1, end = n;

    vector<int> minDist(n + 1, INT16_MAX);  //记录源点到其他节点的距离
    vector<bool> visited(n + 1, false);      //记录节点是否被访问过
    
    minDist[start] = 0;  //源点到源点的距离为0
    
    for(int i = 1; i <= n ; i++)
    {
        int minVal = INT16_MAX;
        int cur = 1;
        //1.选距离源点最近且没有访问过的节点
        for(int v = 1; v <= n ; v++)
        {
            if(!visited[v] && minDist[v] < minVal)
            {
                minVal = minDist[v];
                cur = v;
            }
        }
        //2.标记该节点已经被访问过
        visited[cur] = true;
        
        //3.更新非访问节点到源点的距离
        for(int v = 1; v <= n; v++)
        {
            //如果该节点没有被访问过，并且与当前节点的距离小于记录的距离，则更新记录的距离
            if(!visited[v] && grid[cur][v] != INT16_MAX && minDist[cur] + grid[cur][v] < minDist[v])
            {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }

    }
    
    if(minDist[end] == INT16_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<minDist[end]<<endl;
    }

    system("pause");
    return 0;
}