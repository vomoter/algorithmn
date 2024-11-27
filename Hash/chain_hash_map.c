/*
 * @Author: YiFu
 * @Date: 2024-07-08 11:10:52
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-14 22:13:23
 * @FilePath: \Hash\chain_hash_map.c
 */
#include"chain_hash_map.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*构造函数*/
LinkHashMap* newHashMapLink()
{
    LinkHashMap* hashMap = (LinkHashMap*)malloc(sizeof(LinkHashMap));
    hashMap->size = 0;                      //键值对数量
    hashMap->capacity = 4;                  //哈希表容量
    hashMap->loadThres = 3.0 / 4.0;         //触发扩容的负载因子阈值3/4                           
    hashMap->extendRatio = 2;               //扩容倍数
    hashMap->buckets = (Node**)malloc(hashMap->capacity * sizeof(Node *));
    
    /*初始化所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        hashMap->buckets[i] = NULL;
    }
    return hashMap;
}
/*析构函数 */
void deleteLinkHashMap(LinkHashMap* hashMap)
{
    /*遍历所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        /*遍历所有同一索引的键值对，并释放内存*/
        while (cur)
        {
            Node* temp = cur;
            cur = cur ->next;
            free(temp);             
        }
    }
    free(hashMap->buckets);
    free(hashMap);
}

/*哈希函数 */
int hashFuc(LinkHashMap* hashMap, int key)
{
    return key % hashMap->capacity;
}

/*负载因子 */
double loadFactor(LinkHashMap* hashMap)
{
    return (double)hashMap->size / (double)hashMap->capacity;
}

/*查询操作 ,根据键，返回值*/
char* getValue(LinkHashMap* hashMap, int key)
{
    int index = hashFuc(hashMap,key);
    Node* node = hashMap->buckets[index];
    while(node)
    {
        // 遍历桶，若找到 key ，则返回对应 value
        if(node->pair->key == key)
        {
            return node->pair->value;
        }
        node = node->next;
    }
    //没有找到key,返回空字符串
    return (char*)"";   
}

/*添加操作 */
void put(LinkHashMap* hashMap, int key, const char* value)
{
    int index = hashFuc(hashMap, key);
    Node* cur = hashMap->buckets[index];
    /*当负载因子超过阈值时，执行扩容*/
    if (loadFactor(hashMap)>hashMap->loadThres)
    {
        extend(hashMap); 
    }
    /*遍历桶，若遇到指定 key ，则更新对应 value 并返回*/
    while (cur)
    {
        if(cur->pair->key == key)
        {
            strcpy(cur->pair->value,value);
            return;
        }
        cur = cur->next;
    }

    /*没有找到key，将键值对添加到链表头部*/
    Pair* temp = (Pair*)malloc(sizeof(Pair));
    temp->key = key;                        
    temp->value = (char *)malloc(strlen(value) + 1);
    strcpy(temp->value, value);
    Node* newNode = (Node*)malloc(sizeof(Node));   //申请新链表
    newNode->pair = temp;
    /*链表指向key对应桶索引*/
    newNode->next = hashMap->buckets[index];    
    hashMap->buckets[index] = newNode;
    hashMap->size++;
}

/* 扩容哈希表 */
void extend(LinkHashMap *hashMap)
{
    /*暂存原哈希表*/
    Node **oldBuckts = hashMap->buckets;
    int oldCapacity = hashMap->capacity;
    /*初始化扩容后的新哈希表*/
    hashMap->capacity *= hashMap->extendRatio;
    hashMap->buckets = (Node**)malloc(sizeof(Node*)*hashMap->capacity);
    for (int i = 0; i < hashMap->capacity; i++)
    {
        hashMap->buckets[i] = NULL;
    }
    hashMap->size = 0;
    // 将键值对从原哈希表搬运至新哈希表
    for (int i = 0; i < oldCapacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        while (cur)
        {
            put(hashMap,cur->pair->key, cur->pair->value);
            cur = cur->next;
        }
    }
}
void removeItem(LinkHashMap* hashMap, int key)
{
    int index = hashFuc(hashMap,key);
    if(hashMap->buckets[index] == NULL) return;         //key不存在，退出
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        Node* pre = NULL;
        /*从当前链表查找key */
        while (cur)
        {
            /*找到key*/
            if (cur->pair->key == key)
            {
                if(pre)
                {     
                    pre->next = cur->next;          //删除key所在的节点
                }
                else
                {
                    hashMap->buckets[index] = pre; //cur为头节点时，删除cur,把buckets[index]指向空
                }
                free(cur->pair);
                free(cur);
                hashMap->size --;
                return;
            }
            pre = cur;
            cur = cur->next;
        }
    }
}

/*打印哈希表 */
void printHash(LinkHashMap* hasMap)
{
    /*遍历桶数组，打印所有键值对 */
    for (int i = 0; i < hasMap->capacity; i++)
    {
        Node* cur = hasMap->buckets[i];
        if(!cur) continue;
        /*打印索引相同的所有键值对 */
        printf("[\n");
        while (cur)
        {
            printf("  %d -> %s\n",cur->pair->key,cur->pair->value);
            cur = cur->next;
        }
        printf("]\n");
    }
    
}

/*获取所有键值对 */
Pair* pairSet(LinkHashMap* hashMap)
{
    Pair* result =(Pair*)malloc(sizeof(Pair) * hashMap->size);
    int index = 0;
    /*遍历所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        /*遍历当前索引的链表*/
        while (cur)
        {
            result[index].key = cur->pair->key;
            result[index].value = (char*)malloc(sizeof(strlen(cur->pair->value)+1));
            strcpy(result[index].value, cur->pair->value);
            index++;
            cur = cur->next;
        }
    }
    return result;
}

/*返回所有键 */
int* keySet(LinkHashMap* hashMap)
{
    int* result = (int*)malloc(sizeof(int) * hashMap->size);
    int index = 0;
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        if(!cur) continue;
        while (cur)
        {
            result[index] = cur->pair->key;
            index++;
            cur = cur->next;
        }
    }
    return result;
}

/*返回所有值*/
char** valueSet(LinkHashMap *hashMap)
{
    char** result = (char**)malloc(sizeof(char*) * hashMap->size);
    int index = 0;
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        if(!cur) continue;
        while (cur)
        {
            result[index] = cur->pair->value;
            index++;
            cur = cur->next;
        }
    }
    return result;
}
