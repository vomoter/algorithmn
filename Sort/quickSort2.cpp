#include<iostream>
using namespace std;
/*
双边循环：
1.选择最右侧元素作为基准点
2.j找基准点小的，i找基准点小的，一旦找到，二者进行交换
    j从右向左，i从左向右
3.最后基准点与i交换,i即最终索引

*/

//统计数组长度
int Length(int *a);
//打印数组元素
void Display(int *a);
//交换数组下标元素
void Swap(int *a, int i ,int j);
//对数组[low,high]进行排序，返回标记位置
int Partition(int *arr,int low,int high);
//对数组子数列[low,high]进行快速排序
void QSort(int *arr,int low,int high);
//对数组进行快速排序
void QuickSort(int *arr);

int main()
{

    int arr[]={49,38,65,97,76,13,27,49};
    QuickSort(arr);
    Display(arr);

    system("pause");
    return 0;
}

//统计数组数组长度
int Length(int *a)
{
    int len = 0;
    for(int i = 0;a[i] != '\0';i++)
    { 
        len++;
    }
    return len;
}

//打印数组元素
void Display(int *a)
{
    for(int i = 0;i < Length(a)-1;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}
//交换数组下标元素
void Swap(int *a, int i ,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] =temp;
}

//对数组[low,high]进行排序，返回标记位置
int Partition(int *arr,int low,int high)
{
     int key = arr[low];
    int i = low+1;      //基准点+1
    int j = high;
    while (i <= j)
    {
        //i从左向右找比基准点大的或者相等的
        while(i <= j && arr[i] <= key) i++;
        //j从右向左找比基准点小的或者相等的
        while(i <= j && arr[j] >= key) j--;

       //i与j交换，并各自前进一个单位
       if(i<= j)
       {
            Swap(arr,i,j);
            i++;
            j--;
       }
    }
    //基准点与j交换
    Swap(arr,j,low);
    return j;
}

//对数组子数列[low,high]进行快速排序
void QSort(int *arr,int low,int high)
{
    if(high<low) return;
    if(low<high)
    {
    int p = Partition(arr,low,high);
    QSort(arr,low,p-1);
    QSort(arr,p+1,high);
    }
}
//对数组进行快速排序
void QuickSort(int *arr)
{
    QSort(arr,0,Length(arr)-1);
}