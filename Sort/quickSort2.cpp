#include<iostream>
using namespace std;
/*
˫��ѭ����
1.ѡ�����Ҳ�Ԫ����Ϊ��׼��
2.j�һ�׼��С�ģ�i�һ�׼��С�ģ�һ���ҵ������߽��н���
    j��������i��������
3.����׼����i����,i����������

*/

//ͳ�����鳤��
int Length(int *a);
//��ӡ����Ԫ��
void Display(int *a);
//���������±�Ԫ��
void Swap(int *a, int i ,int j);
//������[low,high]�������򣬷��ر��λ��
int Partition(int *arr,int low,int high);
//������������[low,high]���п�������
void QSort(int *arr,int low,int high);
//��������п�������
void QuickSort(int *arr);

int main()
{

    int arr[]={49,38,65,97,76,13,27,49};
    QuickSort(arr);
    Display(arr);

    system("pause");
    return 0;
}

//ͳ���������鳤��
int Length(int *a)
{
    int len = 0;
    for(int i = 0;a[i] != '\0';i++)
    { 
        len++;
    }
    return len;
}

//��ӡ����Ԫ��
void Display(int *a)
{
    for(int i = 0;i < Length(a)-1;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}
//���������±�Ԫ��
void Swap(int *a, int i ,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] =temp;
}

//������[low,high]�������򣬷��ر��λ��
int Partition(int *arr,int low,int high)
{
     int key = arr[low];
    int i = low+1;      //��׼��+1
    int j = high;
    while (i <= j)
    {
        //i���������ұȻ�׼���Ļ�����ȵ�
        while(i <= j && arr[i] <= key) i++;
        //j���������ұȻ�׼��С�Ļ�����ȵ�
        while(i <= j && arr[j] >= key) j--;

       //i��j������������ǰ��һ����λ
       if(i<= j)
       {
            Swap(arr,i,j);
            i++;
            j--;
       }
    }
    //��׼����j����
    Swap(arr,j,low);
    return j;
}

//������������[low,high]���п�������
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
//��������п�������
void QuickSort(int *arr)
{
    QSort(arr,0,Length(arr)-1);
}