/*
 * @Author: YiFu
 * @Date: 2024-07-08 11:10:20
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-13 22:36:38
 * @FilePath: \Hash\chain_hash_map.h
 */
#ifndef __CHAIN_HASH_MAP_H
#define __CHAIN_HASH_MAP_H

/*键值对 */
typedef struct 
{
    int key;        //键
    char *value;    //值
}Pair;

/*链表节点 */
typedef struct Node
{
    Pair  *pair;         //键值对指针
    struct Node* next;  //链表节点指针
}Node;

/*链式地址哈希表*/
typedef struct 
{
    int size;           //键值对数量
    int capacity;       //哈希表容量
    double loadThres;   //触发扩容的负载因子阈值
    int extendRatio;    //扩容倍数
    Node **buckets;     //桶数组
    
}LinkHashMap;

LinkHashMap* newHashMapLink();
void deleteLinkHashMap(LinkHashMap* hashMap);
int hashFuc(LinkHashMap* hashMap, int key);
double loadFactor(LinkHashMap* hashMap);
char* getValue(LinkHashMap* hashMap, int key);
void put(LinkHashMap* hashMap, int key, const char* value);
void removeItem(LinkHashMap* hashMap, int key);
void extend(LinkHashMap* hashMap);
Pair* pairSet(LinkHashMap* hashMap);
int* keySet(LinkHashMap* hashMap);
char** valueSet(LinkHashMap *hashMap);
void printHash(LinkHashMap* hasMap);

#endif