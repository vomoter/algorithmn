/*
 * @Author: YiFu
 * @Date: 2024-06-29 11:38:53
 * @LastEditors: YiFu
 * @LastEditTime: 2024-06-29 11:56:15
 * @FilePath: \Tree\temp.c
 */
#include <stdio.h>
#include <stdlib.h>
void why_me();

int main()
{


    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);


    printf("The version is %ld.\n", __STDC_VERSION__);
#line 100
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);
    why_me();

    system("pause");
    return 0;
}

void why_me()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}
