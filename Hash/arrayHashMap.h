/*
 * @Author: YiFu
 * @Date: 2024-07-05 21:22:18
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-07 17:50:57
 * @FilePath: \Hash\arrayHashMap.h
 */
#ifndef __ARRAYHASHMAP_H
#define __ARRAYHASHMAP_H
#include<string>
#include<vector>
/*键值对*/
struct Pair
{
    int key;
    std::string value;
    Pair(int key, std::string value)
    {
        this->key = key;
        this->value = value;
    }
};

/*基于数组实现的哈希表*/
class ArrayHashMap
{
private:
    std::vector<Pair*> buckets;

public:
    ArrayHashMap();
    ~ArrayHashMap();
    int hashFunc(int key);
    std::string get(int key);
    void put(int key, std::string value);
    void remove(int key);
    std::vector<Pair*> pairSet();
    std::vector<int> keySet();
    std::vector<std::string> valueSet();
    void print();
};

#endif