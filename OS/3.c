#include <stdio.h>
#include <stdlib.h>
#define Size 20
#define BLOCK 3

int find(int item, int block[]) //若返回结果为-1则表明ite不在block中
{
   int i;
   int flag = -1;
   for (i = 0; i < BLOCK; i++)
      if (item == block[i])
      {
         flag = i;
         break;
      }
   return flag;
}
void DisplayBlock(int block[]) //
{
   int j;
   printf("当前内存块情况：");
   for (j = 0; j < BLOCK; j++)
   {
      printf("%d  ", block[j]);
   }
   printf("\n");
}

void PreDistance(int array[], int current, int block[], int address[]) //
{
   int i, j;
   int length;

   for (i = 0; i < BLOCK; i++)
   { //每个block[i]对应一个页面，现在要在array中从current位置向后查找，离当前位置的距离
      int flag = 0;
      for (j = current - 1; j > 0; j--)
         if (block[i] == array[j])
         {
            length = current - j;
            flag = 1;
            break;
         }
         else
            continue;
      if (flag == 1)
         address[i] = length;
      else
         address[i] = 100;
   }
}

void Distance(int array[], int current, int block[], int address[]) //
{
   int i, j;
   int length;

   for (i = 0; i < BLOCK; i++)
   { //每个block[i]对应一个页面，现在要在array中从current位置向后查找，离当前位置的距离
      int flag = 0;
      for (j = current + 1; j < Size; j++)
         if (block[i] == array[j])
         {
            length = j - current;
            flag = 1;
            break;
         }
         else
            continue;
      if (flag == 1)
         address[i] = length;
      else
         address[i] = 100;
   }
}
void Init(int block[], int address[])
{
   int i;
   for (i = 0; i < BLOCK; i++)
      block[i] = -1; //初始化内存块
   for (i = 0; i < BLOCK; i++)
      address[i] = -1; //初始化内存块
}
float LRU(int array[], int block[], int address[]) // LRU算法，返回该算法的缺页率，array为要访问的页面串，要显示依次淘汰的页面
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //将第一个页面直接调入内存
   while (count < BLOCK) //将前BLOCK个不同的页面调入内存中
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count += 1;
      }
      i++;
   }
   /* printf("当前内存块情况：\n");
    for(j=0;j<BLOCK;j++)
    {printf("%d  ",block[j]);}*/
   current = i - 1;
   // printf("依次淘汰的页面为:\n");

   while (current < Size)
   {
      if (find(array[current], block) == -1) //证明没找到array[current]
      {

         PreDistance(array, current, block, address);
         //打印当前每个页面离当前位置

         temp = 0;

         for (j = 0; j < BLOCK; j++) //查找离当前位置最远的模块
         {
            if (temp < address[j])
            {
               temp = address[j];
               k = j;
            }
         }
         printf("淘汰页面%d,", block[k]);
         block[k] = array[current]; //将当前的模块替换block[k]

         page = page + 1;

         printf("\n");
      }
      DisplayBlock(block);
      current++;
   }
   return (float)(page + BLOCK) / Size;
}

float OPT(int array[], int block[], int address[]) // OPT算法，返回该算法的缺页率，array为要访问的页面串，要显示依次淘汰的页面
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //将第一个页面直接调入内存
   while (count < BLOCK) //将前BLOCK个不同的页面调入内存中
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count = count + 1;
      }
      i++;
   }

   current = i - 1;
   // printf("依次淘汰的页面为:\n");

   while (current < Size)
   {
      if (find(array[current], block) == -1) //证明没找到array[current]
      {
         Distance(array, current, block, address);
         //打印当前每个页面离当前位置

         temp = 0;

         for (j = 0; j < BLOCK; j++) //查找离当前位置最远的模块
         {
            if (temp < address[j])
            {
               temp = address[j];
               k = j;
            }
         }
         printf("淘汰页面%d,", block[k]);
         printf("\n");
         block[k] = array[current]; //将当前的模块替换block[k]

         page = page + 1;
      }
      DisplayBlock(block);
      current++;
   }
   return (float)(page + BLOCK) / Size;
}
float FCFS(int array[], int block[], int address[]) // OPT算法，返回该算法的缺页率，array为要访问的页面串，要显示依次淘汰的页面
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //将第一个页面直接调入内存
   while (count < BLOCK) //将前BLOCK个不同的页面调入内存中
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count = count + 1;
      }
      i++;
   }

   current = i - 1;
   // printf("依次淘汰的页面为:\n");
   k = 0;
   while (current < Size)
   {
      if (find(array[current], block) == -1) //证明没找到array[current]
      {

         printf("淘汰页面%d,", block[k]);
         printf("\n");
         block[k] = array[current]; //将当前的模块替换block[k]

         page = page + 1;
         k = (k + 1) % BLOCK;
      }
      DisplayBlock(block);
      current++;
   }
   return (float)(page + BLOCK) / Size;
}

int main()
{
   int array[Size] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
   int block[BLOCK];   //存储内存页面情况
   int address[BLOCK]; //存储当前页面离各页面的距离
   int type;

   float page;
   while (1)
   {
      printf("input the type: 1.FCFS  2.LRU   3.OPT:\n");
      scanf("%d", &type);
      switch (type)
      {
      case 0:
         printf("退出\n");
         break;
      case 1:
         page = FCFS(array, block, address);
         printf("FCFS:缺页率为%f\n", page);
         break;
      case 2:
         page = LRU(array, block, address);
         printf("LRU:缺页率为%f\n", page);
         break;
      case 3:
         page = OPT(array, block, address);
         printf("OPT:缺页率为%f\n", page);
         break;
      default:
         printf("你的输入有误！");
         break;
      }
   }
   system("pause");
   return 0;
}