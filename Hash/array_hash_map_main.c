/*
 * @Author: YiFu
 * @Date: 2024-06-30 18:36:28
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-30 19:19:39
 * @FilePath: \Hash\array_hash_map_main.c
 */
#include<stdio.h>
#include<stdlib.h>
/*键值对 int->string */
typedef struct
{
    int key;    //键
    char *val;  //值
}Pair;

typedef struct
{
    void* set;
    int tatal;
}MapSet;

int main()
{
    MapSet *map;
    char **str;
    str = (char **)malloc(100 * sizeof (char*));
    str[0] = "fff";
    
    
  //  printf("%s\n",str[0]);

    map = (MapSet *)malloc(sizeof(MapSet));
    printf("%p\n",&str);
    map->set = &str;
    map->tatal = 100;
    printf("%p\n",map->set);
    printf("%d\n",map->tatal);

    system("pause");
    return 0;
    
}
