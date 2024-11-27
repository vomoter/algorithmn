/*
 * @Author: YiFu
 * @Date: 2024-07-07 18:40:48
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-08 15:46:20
 * @FilePath: \Hash\arrayHashC.c
 */
#include"array_hash_map.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    ArrayHashMap* hashMap = newArrayHashMap();
    put(hashMap, 1, "apple");
    put(hashMap, 2, "hello");
    put(hashMap, 3, "world");
    put(hashMap, 104, "nob");
    put(hashMap, 5, "continent");
    
    removeItem(hashMap,104);
    printf("2 -> %s\n",getValue(hashMap,2));
   //removeItem(hashMap,1);
    Pair* pair = pairSet(hashMap);
    printf("pair:%p\n",pair);
    printf("size:%d\n",totalValid(hashMap));
    /*打印所有键值对*/
    for (int i = 0; i < totalValid(hashMap); i++)
    {
        printf("%d -> %s\n", pair[i].key, pair[i].value);
    }
 
    /*打印所有键 */
    printf("----------------------\n");
    int* result =keySet(hashMap); 
    printf("result:%p\n", result);
    printf("size:%d\n",totalValid(hashMap));   
    for (int i = 0; i < totalValid(hashMap); i++)
    {
        printf("%d\n", result[i]);
    }
    
    /*打印所有值 */
    printf("----------------------\n");
    char** strArray =valueSet(hashMap); 
    printf("strArry:%p\n", strArray);
    printf("size:%d\n",totalValid(hashMap));   
    for (int i = 0; i < totalValid(hashMap); i++)
    {
        printf("%s\n", strArray[i]);
    }

    /*打印哈希表 */
    printf("----------------------\n");
    printHashMap(hashMap);

    system("pause");
    return 0;
}