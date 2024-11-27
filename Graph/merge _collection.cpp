/*
 * @Author: YiFu
 * @Date: 2024-09-15 21:17:25
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-25 19:37:15
 * @FilePath: \Graph\merge _collection.cpp
 */
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

#define ASSERT(expr) ((expr) ? (void)0 : logError(#expr, __FILE__, __LINE__))   // 断言宏定义
int global_num = 0;             // 全局变量，记录节点个数
vector<int> father(10001, 0);   // 父节点数组

/**
 * @brief 断言失败时输出错误信息
 * @param expr 断言表达式
 * @param file 断言所在文件
 * @param line 断言所在行号
 * @return void
 */
void logError(const char* expr, const char* file, int line) {
    std::cerr << "Assertion failed: (" << expr << "), "  \
              << "file " << file << ", line " << line << ".\n";
}
/**
 * @brief 并查集初始化
 * @param void
 * @return void
 */
void init(void)
{
    /* 初始化父节点数组 */
    for(int i = 0; i <= global_num; i++)
    {
        father[i] = i;   // 每个节点的父节点初始化为自身
    }
}

/**
 * @brief 并查集查找
 * @param u 节点u
 * @return 节点u的根节点
 */
int find(int u)
{
    /* 路径压缩 */
    if(father[u] == u)  
    {
        return u;
    }
    else
    {
        return father[u] = find(father[u]);    //递归查找父节点
    }
    //三元运算符的写法
    //return u == father[u] ? u : father[u] = find(father[u]);
    
}

/**
 * @brief 判断两个节点是否属于同一个集合
 * @param u 节点u
 * @param v 节点v
 * @return 两个节点是否属于同一个集合
 */
bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return  u == v;
}

/**
 * @brief 并查集合并
 * @param u 节点u
 * @param v 节点v
 * @return void
 */
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
    {
        return;
    }
    father[u] = v;
}

void testUnionFind() {
    // 测试初始化
    global_num = 10; // 设置节点数量
    init();
    
    // 测试单个节点是否在不同集合中
    ASSERT(isSame(1, 2)); // 1 和 2 应不在同一集合中

    // 测试合并
    join(1, 2);
    ASSERT(isSame(1, 2)); // 1 和 2 现在应在同一集合中

    // 测试多次合并
    join(2, 3);
    ASSERT(isSame(1, 3)); // 1 和 3 现在应在同一集合中

    // 测试与已有集合的合并
    join(1, 3); // 不应有变化
    ASSERT(isSame(2, 3)); // 2 和 3 应仍在同一集合中

    // 测试自我合并的边界情况
    join(4, 4); // 不应有任何变化
    ASSERT(!isSame(4, 1)); // 4 不应与 1 在同一集合中

    // 测试合并后的个别节点
    join(4, 5);
    ASSERT(!isSame(4, 6)); // 4 和 6 不应在同一集合中

    // 测试查找功能
    ASSERT(find(1) != find(4)); // 1 和 4 应有不同的根节点
    join(4, 1);
    ASSERT(isSame(1, 4)); // 合并后，1 和 4 应在同一集合中
}

int main()
{
    testUnionFind();
    cout << "All tests passed!" << endl;


    system("pause");
    return 0;
}