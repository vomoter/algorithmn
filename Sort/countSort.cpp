#include<iostream>
using namespace std;
/*  
    ��������
        1.�ҵ����ֵ������һ����СΪ+1��count����
        2.count�����������Ӧԭʼ�����Ԫ�أ�����ͳ�Ƹ�Ԫ�صĳ��ִ���
        3.����count���飬����count�������������ԭʼ�����Ԫ�أ��Լ����ִ�����
        ���������count����������ǣ��Ѿ�����õ�

*/

//��������ĳ���
int arrayLen(int *arr)
{
    int len=0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        len++;
    }
    
    return len;

}

//������Ԫ�ص����ֵ
int findMax(int *arr)
{
    int max = 0;
    for (int i = 1; i < arrayLen(arr); i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;

}

void Display(int *arr)
{
    for (int i = 0; i < arrayLen(arr)-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;




}
//��������
void countSort(int *arr)
{
    int size =arrayLen(arr);
    int *countArray = new int [size+1];
   
    for(int i = 0; i< arrayLen(countArray);i++)
    {
        countArray[i] = 0;
        cout<<countArray[i]<<" ";
    }
    cout<<"\n------------"<<endl;
    for (int i = 0; i < arrayLen(countArray); i++)
    {
       for(int j=0;j < arrayLen(countArray);j++)
       {
        if(arr[i]=j) countArray[j]++;
         cout<<countArray[j]<<" ";
       }
    }


    
    int k=0;
    for (int i = 1; i < size+1 ; i++)
    {
       while(countArray[i]>0)
       {
            arr[k++] = i;
            countArray[i]--;

       }
    }
   
}

int main()
{
    int arr[] ={1,5,3,4,2,3,6,7,8,5,5};
    int max = findMax(arr);
    cout<<max<<endl;
    cout<<arrayLen(arr)<<endl;
    countSort(arr);
    //Display(arr);

    system("pause");
    return 0;
}