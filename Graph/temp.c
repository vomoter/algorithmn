/*
 * @Author: YiFu
 * @Date: 2024-08-03 19:04:02
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-15 21:14:14
 * @FilePath: \Graph\temp.c
 */
#include <stdio.h>
#include <stdlib.h>

int temp()
{
    int a = 1;
    return a;
}

void test()
{
    printf("This is a test function.\n");
}
void p(int (*fuc)(void) ,void* message)
{
    printf("%d\n", fuc());
    printf("%s\n", message);
}

void p2(void (*fuc)(void))
{
    fuc();
    printf("This is a call test function.\n");
}

int main()
{
    printf("Hello World!\n");
    int a = 10;
    void *rr = (void*)&a;
    printf("%d\n", *(int*)rr);
    p(temp, (char*)"This is a message.");
    

    p2(test);
    system("pause"); 
    return 0;
}
