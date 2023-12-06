#include <stdio.h>
#include <stdlib.h>
#define Size 20
#define BLOCK 3

int find(int item, int block[]) //�����ؽ��Ϊ-1�����ite����block��
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
   printf("��ǰ�ڴ�������");
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
   { //ÿ��block[i]��Ӧһ��ҳ�棬����Ҫ��array�д�currentλ�������ң��뵱ǰλ�õľ���
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
   { //ÿ��block[i]��Ӧһ��ҳ�棬����Ҫ��array�д�currentλ�������ң��뵱ǰλ�õľ���
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
      block[i] = -1; //��ʼ���ڴ��
   for (i = 0; i < BLOCK; i++)
      address[i] = -1; //��ʼ���ڴ��
}
float LRU(int array[], int block[], int address[]) // LRU�㷨�����ظ��㷨��ȱҳ�ʣ�arrayΪҪ���ʵ�ҳ�洮��Ҫ��ʾ������̭��ҳ��
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //����һ��ҳ��ֱ�ӵ����ڴ�
   while (count < BLOCK) //��ǰBLOCK����ͬ��ҳ������ڴ���
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count += 1;
      }
      i++;
   }
   /* printf("��ǰ�ڴ�������\n");
    for(j=0;j<BLOCK;j++)
    {printf("%d  ",block[j]);}*/
   current = i - 1;
   // printf("������̭��ҳ��Ϊ:\n");

   while (current < Size)
   {
      if (find(array[current], block) == -1) //֤��û�ҵ�array[current]
      {

         PreDistance(array, current, block, address);
         //��ӡ��ǰÿ��ҳ���뵱ǰλ��

         temp = 0;

         for (j = 0; j < BLOCK; j++) //�����뵱ǰλ����Զ��ģ��
         {
            if (temp < address[j])
            {
               temp = address[j];
               k = j;
            }
         }
         printf("��̭ҳ��%d,", block[k]);
         block[k] = array[current]; //����ǰ��ģ���滻block[k]

         page = page + 1;

         printf("\n");
      }
      DisplayBlock(block);
      current++;
   }
   return (float)(page + BLOCK) / Size;
}

float OPT(int array[], int block[], int address[]) // OPT�㷨�����ظ��㷨��ȱҳ�ʣ�arrayΪҪ���ʵ�ҳ�洮��Ҫ��ʾ������̭��ҳ��
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //����һ��ҳ��ֱ�ӵ����ڴ�
   while (count < BLOCK) //��ǰBLOCK����ͬ��ҳ������ڴ���
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count = count + 1;
      }
      i++;
   }

   current = i - 1;
   // printf("������̭��ҳ��Ϊ:\n");

   while (current < Size)
   {
      if (find(array[current], block) == -1) //֤��û�ҵ�array[current]
      {
         Distance(array, current, block, address);
         //��ӡ��ǰÿ��ҳ���뵱ǰλ��

         temp = 0;

         for (j = 0; j < BLOCK; j++) //�����뵱ǰλ����Զ��ģ��
         {
            if (temp < address[j])
            {
               temp = address[j];
               k = j;
            }
         }
         printf("��̭ҳ��%d,", block[k]);
         printf("\n");
         block[k] = array[current]; //����ǰ��ģ���滻block[k]

         page = page + 1;
      }
      DisplayBlock(block);
      current++;
   }
   return (float)(page + BLOCK) / Size;
}
float FCFS(int array[], int block[], int address[]) // OPT�㷨�����ظ��㷨��ȱҳ�ʣ�arrayΪҪ���ʵ�ҳ�洮��Ҫ��ʾ������̭��ҳ��
{
   Init(block, address);
   int i = 0, count = 0, current, temp, j, k, page = 0;
   // block[0] = array[0]; //����һ��ҳ��ֱ�ӵ����ڴ�
   while (count < BLOCK) //��ǰBLOCK����ͬ��ҳ������ڴ���
   {
      if (find(array[i], block) == -1)
      {
         block[count] = array[i];
         count = count + 1;
      }
      i++;
   }

   current = i - 1;
   // printf("������̭��ҳ��Ϊ:\n");
   k = 0;
   while (current < Size)
   {
      if (find(array[current], block) == -1) //֤��û�ҵ�array[current]
      {

         printf("��̭ҳ��%d,", block[k]);
         printf("\n");
         block[k] = array[current]; //����ǰ��ģ���滻block[k]

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
   int block[BLOCK];   //�洢�ڴ�ҳ�����
   int address[BLOCK]; //�洢��ǰҳ�����ҳ��ľ���
   int type;

   float page;
   while (1)
   {
      printf("input the type: 1.FCFS  2.LRU   3.OPT:\n");
      scanf("%d", &type);
      switch (type)
      {
      case 0:
         printf("�˳�\n");
         break;
      case 1:
         page = FCFS(array, block, address);
         printf("FCFS:ȱҳ��Ϊ%f\n", page);
         break;
      case 2:
         page = LRU(array, block, address);
         printf("LRU:ȱҳ��Ϊ%f\n", page);
         break;
      case 3:
         page = OPT(array, block, address);
         printf("OPT:ȱҳ��Ϊ%f\n", page);
         break;
      default:
         printf("�����������");
         break;
      }
   }
   system("pause");
   return 0;
}