/*
 * @Author: YiFu
 * @Date: 2024-05-02 15:51:09
 * @LastEditors: YiFu
 * @LastEditTime: 2024-05-02 17:32:01
 * @FilePath: \Graph\797.cpp
 */
#include<iostream>
#include<vector>
using namespace std;
class Soulotion
{
private:
    vector<vector<int>> result;     //收集符合条件的路径
    vector<int> path;               //0节点到终点的路径

    /**
     * @brief 深度搜索当前节点到其他节点的路径
     * @param graph 存储当前节点的到其他节点的路径
     * @param x 当前的节点
     * @retval 无
    */
    void dfs(vector<vector<int>> &graph, int x)
    {
        if(x == graph.size()-1)
        {
            result.push_back(path);
        }
        for(int i = 0 ; i < graph[x].size(); i++)
        {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
    }

public:
    /**
     * @brief 调用dfs遍历节点0到节点n-1的路径
     * @param graph 存储节点的0到其他节点的路径
     * @retval result 收集的从节点0到终点的路径 
    */
    vector<vector<int>> allPathSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);      //无论什么路径都已经是从0节点开始
        dfs(graph,0);           //开始深度搜索从节点0遍历
        return result;
    }

    /**
     *  @brief  遍历vector二维数组的元素 
     *  @param  graph 要遍历的vector二维数组
     *  @retval 无
    */
    void dispalyGraph(vector<vector<int>> &graph)
    {
       for (vector<vector<int>>::iterator it = graph.begin(); it != graph.end(); ++it)
       {
	        for (vector<int>::iterator item = (*it).begin(); item != (*it).end();item++)
            {
                cout<<*item<<" ";
            } 
            cout<<endl;
       }
	}
};

int main()
{
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    Soulotion Soulotion;
    vector<vector<int>> result;
    result =Soulotion.allPathSourceTarget(graph);
    Soulotion.dispalyGraph(result);

    system("pause");
    return 0;
}