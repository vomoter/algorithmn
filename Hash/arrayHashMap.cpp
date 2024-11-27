/*
 * @Author: YiFu
 * @Date: 2024-07-05 21:21:30
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-07 18:32:02
 * @FilePath: \Hash\arrayHashMap.cpp
 */
#include "arrayHashMap.h"
#include <iostream>

/*构造函数*/
ArrayHashMap::ArrayHashMap()
{
    //初始化数组，包含100个桶
    buckets = std::vector<Pair *>(100);
    
}

/*析构函数*/
ArrayHashMap::~ArrayHashMap()
{
    //释放内存
    for(auto &bucket : buckets)
    {
        delete bucket;
    }
    buckets.clear();
    
}

/*哈希函数*/
int ArrayHashMap::hashFunc(int key)
{
    return key%100;
}

/*查询操作*/
std::string ArrayHashMap::get(int key)
{
    int index = hashFunc(key);              //用哈希函数求索引
    Pair *pair = buckets[index];
    if (pair == nullptr) return " ";
    return pair->value;
    
}   

/*添加操作 */
void ArrayHashMap::put(int key, std::string value)
{
    int index = hashFunc(key);  
    Pair *pair = new Pair(key,value);
    buckets[index] = pair;
}

/*删除操作 */
void ArrayHashMap::remove(int key)
{
    int index  = hashFunc(key);
    //释放内存
    delete buckets[index];
    //设置为空
    buckets[index] = nullptr;

}

/*获取所有键值对 */
std::vector<Pair*> ArrayHashMap::pairSet()
{
    std::vector<Pair*> result;
    /*把桶内的键值对加入到结果集中 */
    for (Pair *pair : buckets)
    {
        if (pair != nullptr) result.push_back(pair);
    }
    return result;
}

/*获取所有键 */
std::vector<int> ArrayHashMap::keySet()
{
    std::vector<int> result;
    /*把桶内的键加入到结果集中 */
    for(Pair *pair : buckets)
    {
        if(pair != nullptr) result.push_back(pair->key);
    }
    return result;
}

/*获取所有所有值 */
std::vector<std::string> ArrayHashMap::valueSet()
{
    std::vector<std::string> result;
    /*把桶内的值加入到结果集中 */
    for(Pair *pair : buckets)
    {
        if(pair != nullptr) result.push_back(pair->value);
    }
    return result;
}
/*打印哈希表 */
void ArrayHashMap::print()
{
    for (Pair *pair : buckets)
    {
        if (pair != nullptr) std::cout << pair->key << "->" << pair->value << std::endl;
    }
    
}