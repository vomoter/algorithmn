/*
 * @Author: YiFu
 * @Date: 2024-06-30 18:36:12
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-08 15:45:17
 * @FilePath: \Hash\array_hash_map.c
 */
#include"array_hash_map.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*构造函数*/
ArrayHashMap* newArrayHashMap()
{
    ArrayHashMap* hashMap = (ArrayHashMap*)malloc(sizeof(ArrayHashMap));
    /*所有桶内存初始化 */
    for(int i = 0; i < MAX_SIZE; i++)
    {
        hashMap->buckets[i] = NULL;
    }
    return hashMap;
}

/*析构函数*/
void deleteArrayHashMap(ArrayHashMap* hashMap)
{
    /*释放所有桶内存*/
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(hashMap->buckets[i]);
    }
    free(hashMap);
}

/*哈希函数*/
int hashFunc(int key)
{
    return key % MAX_SIZE;
}

/*查询操作，根据键，查询对应的值 */
char* getValue(ArrayHashMap *ArrayHashMap, int key)
{
    int index = hashFunc(key);
    //不存在该键，返回空字串
    if(ArrayHashMap->buckets[index]->key == 0)
    {
        return " ";
    }
    char *str = malloc((strlen(ArrayHashMap->buckets[index]->value)+1));
    strcpy(str,ArrayHashMap->buckets[index]->value);
    return str;
}
/*插入元素*/
void put(ArrayHashMap* hashMap, int key, char *value)
{
    Pair *pair = (Pair*)malloc(sizeof(Pair));
    pair->key = key;
    pair->value = malloc(strlen(value) + 1);
    strcpy(pair->value, value);

    /*通过哈希函数，获取桶的索引*/
    int index = hashFunc(key);
    hashMap->buckets[index] = pair;
}

/*删除元素*/
void removeItem(ArrayHashMap *hashMap, int key)
{
    int index = hashFunc(key);
    free(hashMap->buckets[index]->value);
    free(hashMap->buckets[index]);
    hashMap->buckets[index] = NULL;
}

int totalValid(ArrayHashMap *hashMap)
{    
    int total = 0;  
    /*统计有效键值对数量*/     
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if(hashMap->buckets[i] != NULL)     total++;
    }
    return total;
}

/*获取所有键*/
Pair* pairSet(ArrayHashMap *hashMap)
{
    int total = totalValid(hashMap);                     //获取桶中存在的键值对个数
    int index = 0;                                       //初始化Pair的索引
    Pair* pair = (Pair*)malloc(sizeof(Pair)* total);     //为Pair申请内存
    for(int i = 0; i < MAX_SIZE; i++)                  
    {
        if(hashMap->buckets[i]!= NULL)                   //桶中存在键值对存
        {
            pair[index].key = hashMap->buckets[i]->key;

            /*拷贝字符串*/
            pair[index].value = malloc(strlen(hashMap->buckets[i]->value) + 1);
            strcpy(pair[index].value, hashMap->buckets[i]->value);
            index++;
        }
    }
    return pair;
}

/*获取所有键*/
int* keySet(ArrayHashMap *hashMap)
{   
    int total = totalValid(hashMap);                    //获取桶中存在的键个数
    int index = 0;                                      //初始化result的索引
    int* result = (int *)malloc(sizeof(int)*total);     //申请内存
    for(int i = 0 ; i < MAX_SIZE; i++)                  
    {
        if(hashMap->buckets[i] != NULL)                 //桶中存在键值对存
        {
            result[index] = hashMap->buckets[i]->key;
            index++;
        }
    }
    return result;
}

/*获取所有值 */
char** valueSet(ArrayHashMap *hashMap)
{
    int total = totalValid(hashMap);                    //获取桶中存在的键个数
    int index = 0;                                      //初始化result的索引
    char** result = (char**)malloc(sizeof(char*)*total);     //申请内存
    for(int i = 0 ; i < MAX_SIZE; i++)                  
    {
        if(hashMap->buckets[i] != NULL)                 //桶中存在键值对存
        {
            result[index] = (char*)malloc(sizeof(char*)*sizeof(hashMap->buckets[i]->value)+1);
            strcpy(result[index], hashMap->buckets[i]->value);
            index++;
        }
    }
    return result;
}
/*打印哈希表*/
void printHashMap(ArrayHashMap *hashMap)
{
    int total = totalValid(hashMap);                    //获取桶中存在的键个数
    Pair* pair = pairSet(hashMap);
    for (int i = 0; i < totalValid(hashMap); i++)
    {
        printf("%d -> %s\n",pair[i].key, pair[i].value);
    }
    printf("\n");
}