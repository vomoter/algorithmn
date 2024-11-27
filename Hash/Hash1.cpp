/*
 * @Author: YiFu
 * @Date: 2024-07-07 17:47:20
 * @LastEditors: YiFu
 * @LastEditTime: 2024-07-07 17:57:35
 * @FilePath: \Hash\Hash1.cpp
 */
#include"arrayHashMap.h"
#include<iostream>
using namespace std;

int main()  
{
    ArrayHashMap *hash = new ArrayHashMap();
    hash->put(1, "one");
    hash->put(2, "two");
    hash->put(3, "three");
    hash->print();
    cout<<endl;
    hash->remove(2);
    vector<string> valueSet = hash->valueSet();
    for(int i = 0; i < valueSet.size(); i++)
    {
        cout<<valueSet[i]<<" ";
    }
    cout<<endl;


    system("pause");
    return 0;
}

