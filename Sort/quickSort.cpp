#include<iostream>
using namespace std;
//������[low,high]�������򣬷��ر��λ��
int Partition(int *arr,int low,int high);
//������������[low,high]���п�������
void QSort(int *arr,int low,int high);
//��������п�������
void QuickSort(int *arr);
//ͳ���������鳤��
int Lenght(int *a);
//��ӡ����Ԫ��
void Display(int *a);
//���������±�Ԫ��
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

//ͳ���������鳤��
int Lenght(int *a)
{
    int len = 0;
    for(int i = 0;a[i] != '\0';i++)
    { 
        len++;
    }
    return len;
}
//������[low,high]�������򣬷��ر��λ��
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
//������������[low,high]���п�������
void QSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid = Partition(arr,low,high);
        QSort(arr,low,mid-1);
        QSort(arr,mid+1,high);
    }

}
//��������п�������
void QuickSort(int *arr)
{
    QSort(arr,0,Lenght(arr)-1);
}
//��ӡ����Ԫ��
void Display(int *a)
{
    for(int i = 0;i < Lenght(a)-1;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}