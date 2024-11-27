/*
 * @Author: YiFu
 * @Date: 2024-06-06 18:39:27
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-06 18:39:36
 * @FilePath: \DymicProgram\1.temp.cpp
 */
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int* p = (int*)malloc(10*sizeof(int)); //开辟10个整型大小空间
    if (p == NULL) //如果开辟失败,则打印错误原因
    {
        //打印错误原因的一个方式
        printf("%s\n", strerror(errno));
    }
    else
    {
        int i = 0;
        for (i = 0; i < 10; i++) //遍历并初始化打印这10个整型空间
        {
            *(p + i) = i;
            printf("%d ", *(p + i));
        }
        //可以正常使用p指针来操作这片空间了
    }
    printf("\n");
    int* p2 = (int*)realloc(p, 15 * sizeof(int));//将这块空间扩容到15个整型
    if (p2 == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        int i = 0;
        for (i = 0; i < 10; i++) //遍历并打印这15个整型空间
        {
            
            printf("%d ", *(p2 + i));
        }
        for(i = 10; i < 15 ; i++)
        {
            *(p2 + i)=i;
            printf("%d ", *(p2 + i));
        }
       
    }

    free(p); //释放p的内存空间
    p = NULL; //将指针p置为NULL,防止其变成野指针

    system("pause");
    return 0;
}