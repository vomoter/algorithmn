/*
 * @Author: YiFu
 * @Date: 2024-09-21 21:54:06
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-21 22:03:17
 * @FilePath: \Graph\2.temp.c
 */
#include<stdio.h>

void text(int a)
{
    a = 5;
    printf("a = %d\n",a);
}



int main(int argc, char *argv[])
{
    int (*f)(int, char*[]) = main;
    printf("f = %p\n",f);
    printf("&f = %p\n",&f);
    printf("*f = %d\n",*f);

    void (* p)(int) = text;
    printf("text = %p\n",p);
    printf("&text = %p\n",&p);
    printf("*text = %d\n",*p);

    getchar();
    return 0;
}