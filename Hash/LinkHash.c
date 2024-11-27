/*
 * @Author: YiFu
 * @Date: 2024-07-13 20:21:55
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-14 22:15:54
 * @FilePath: \Hash\LinkHash.c
 */
#include "chain_hash_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    LinkHashMap *hashMap = newHashMapLink();
    put(hashMap, 2, "hello");
    put(hashMap, 4, "world");
    put(hashMap, 8, "mortality");
    put(hashMap, 12, "rob");
    printHash(hashMap);
    printf("4 ->value: %s\n", getValue(hashMap, 4));
    printf("capatity: %d\n", hashMap->capacity);
    printf("size: %d\n", hashMap->capacity);
    printf("ratio: %.3f\n", hashMap->loadThres);

    printf("Pair------------------\n");
    Pair *pair = pairSet(hashMap);

    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%d -> %s\n", pair[i].key, pair[i].value);
    }

    printf("\nkeySet------------------\n");
    int *key = keySet(hashMap);
    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%d\n", pair[i].key);
    }
    printf("\nValueSet----------------\n\n");
    char **str = valueSet(hashMap);
    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%s\n", pair[i].value);
    }
    deleteLinkHashMap(hashMap);

    system("pause");
    return 0;
}
