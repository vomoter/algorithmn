#include<iostream>
using namespace std;
/*  
    计数排序：
        1.找到最大值，创建一个大小为+1的count数组
        2.count数组的索引对应原始数组的元素，用来统计该元素的出现次数
        3.遍历count数组，根据count数组的索引（即原始数组的元素）以及出现次数，
        生成排序后count数组的索引是：已经排序好的

*/

//计算数组的长度
int arrayLen(int *arr)
{
    int len=0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        len++;
    }
    
    return len;

}

//找数组元素的最大值
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
//计数排序
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