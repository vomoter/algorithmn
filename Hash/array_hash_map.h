/*
 * @Author: YiFu
 * @Date: 2024-06-30 18:36:01
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-07 18:11:23
 * @FilePath: \Hash\array_hash_map.h
 */
#ifndef __ARRAY_HASH_MAP_H
#define __ARRAY_HASH_MAP_H

//最大桶数量
#define MAX_SIZE 100

/*键值对*/
typedef struct 
{
    int key;        //键
    char *value;    //值
}Pair;

/* 基于数组实现的哈希表 */
typedef struct {
    Pair *buckets[MAX_SIZE];
} ArrayHashMap;

ArrayHashMap *newArrayHashMap();
void delArrayHashMap(ArrayHashMap *hashMap);
int hashFunc(int key);
char* getValue(ArrayHashMap *ArrayHashMap, int key);
void put(ArrayHashMap *hashMap, int key, char *value);
void removeItem(ArrayHashMap *hashMap, int key);
int totalValid(ArrayHashMap *hashMap);
Pair* pairSet(ArrayHashMap *hashMap);
int* keySet(ArrayHashMap *hashMap);
char** valueSet(ArrayHashMap *hashMap);
void printHashMap(ArrayHashMap *hashMap);


#endif