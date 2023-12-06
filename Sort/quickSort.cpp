#include<iostream>
using namespace std;
//对数组[low,high]进行排序，返回标记位置
int Partition(int *arr,int low,int high);
//对数组子数列[low,high]进行快速排序
void QSort(int *arr,int low,int high);
//对数组进行快速排序
void QuickSort(int *arr);
//统计数组数组长度
int Lenght(int *a);
//打印数组元素
void Display(int *a);
//交换数组下标元素
void Swap(int *a, int i ,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] =temp;
}
int main()
{

    int arr[]={49,38,65,97,76,13,27,49};
    int len=Lenght(arr);
    QuickSort(arr);
    Display(arr);

    system("pause");
    return 0;
}

//统计数组数组长度
int Lenght(int *a)
{
    int len = 0;
    for(int i = 0;a[i] != '\0';i++)
    { 
        len++;
    }
    return len;
}
//对数组[low,high]进行排序，返回标记位置
int Partition(int *arr,int low,int high)
{
    int temp = arr[low];
    int key = arr[low];
    while(low<high)
    {
        while(low < high && arr[high] >= key) --high;
        arr[low] = arr[high];
        while(low < high && arr[low] <= key) ++low;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;

}
//对数组子数列[low,high]进行快速排序
void QSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid = Partition(arr,low,high);
        QSort(arr,low,mid-1);
        QSort(arr,mid+1,high);
    }

}
//对数组进行快速排序
void QuickSort(int *arr)
{
    QSort(arr,0,Lenght(arr)-1);
}
//打印数组元素
void Display(int *a)
{
    for(int i = 0;i < Lenght(a)-1;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}