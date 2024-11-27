/*
 * @Author: YiFu
 * @Date: 2024-09-20 21:34:12
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-20 22:02:47
 * @FilePath: \Graph\prim.cpp
 */
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int v, e;
    int x, y, k;
    cin>>v>>e;
    /*填写一个默认最大值，题目描述val最大值为10000*/
    vector<vector<int>> grid(v+1, vector<int>(v + 1, 10001));
    while(e--)
    {
        cin>>x>>y>>k;
        /*无向图，两个方向都要填充 */
        grid[x][y] = k;
        grid[y][x] = k;
    }

    /*所有节点到最小生成树的最小距离 */
    vector<int> minDist(v + 1, 10001);
    
    /*节点是否在生成树中 */
    vector<bool> isInTree(v + 1, false);

    for(int i = 1; i < v; i++)
    {
        int cur = -1;
        int minVal = INT16_MAX;
        for(int j = 1; j <= v; j++)
        {
            if(!isInTree[j] && minDist[j] < minVal)
            {
                minVal = minDist[j];
                cur = j;
            }
        }

        isInTree[cur] = true;

        for(int j = 1; j <= v; j++)
        {
            if(!isInTree[j] && grid[cur][j] <minDist[j])
            {
                minDist[j] = grid[cur][j];
            }
        }
    }

    int result = 0;
    for(int i = 2; i <= v; i++)
    {
        result += minDist[i];
    }

    cout<<result<<endl;


    system("pause");
    return 0;
}