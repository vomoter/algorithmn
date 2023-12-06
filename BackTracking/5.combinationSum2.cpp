#include<iostream>
#include<algorithm>
#include<vector>
using namespace  std;
/*
    40.����ܺ�2
    ����һ������array��һ��Ŀ����target���ҳ�array��
    ���п���ʹ���ֺ�Ϊtarget�����
    array�е�ÿ��������ÿ�����ֻ��ʹ��һ��

    ���ӣ�
    ���� array= [10,1,2,7,6,1,5];
         target = 8;
    �⼯Ϊ��[[1,7], [1,2,5], [2,6], [1,1,6] ]

*/

class Soultion
{
private:
    vector<vector<int>> result; //�����ϼ���
    vector<int> path;           //��ŷ������������

    //���ݷ����
    void backTrack(vector<int> &v, int target, int sum, int index, vector<bool> &used)
    {
        //������ֵ����Ŀ��ֵ��ֹ
        if (sum > target)
            return;
        //������ֵ����Ŀ��ֵ�ѱ�����ϼ�������
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = index; i < v.size(); i++)
        {
            if(i>0 && v[i] == v[i-1] && used[i-1] == false)   continue;
            sum += v[i];                  //�ѵ�ǰ�ڵ��ۼ�sum
            used[i] = true;
            path.push_back(v[i]);         //�ѵ�ǰ�ڵ������ϼ�
            
            backTrack(v, target, sum, i+1,used); //�ݹ����,����i+1 ,��ʾ���ֿ����ظ�ʹ��
            sum -= v[i];                  //�Ѳ����������Ľڵ�ֵ��ȥ
            used[i] = false;
            path.pop_back();              //����������������
            
        }
    }

public:
    //��������ӡ��Ϊ����
    void dispalyElemnt(vector<vector<int>> &v)
    {
        for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
        {
            for (vector<int>::iterator item = (*it).begin(); item != (*it).end(); item++)
            {
                cout << *item << " ";
            }
            cout << endl;
        }
    }

    //���û��ݷ�,���ؽ����
    vector<vector<int>> combinationSum(vector<int> v, int target)
    {
        //�������
        result.clear();
        path.clear();
        //arrayԪ����������ͬ��Ԫ�ذ���һ��
        sort(v.begin(), v.end());
        
        vector<bool> used;  //ʹ�õ�Ԫ�������ʼ��
        for (int i = 0; i < v.size(); i++)
        {
            used.push_back(false);
        }
        
        backTrack(v, target, 0, 0,used);
        return result; //���ؽ����
    }

};
int main()
{
    vector<int> array = {10, 1, 2, 7, 6, 1, 5};
    int target;
    cout<<"������Ŀ��ֵ��";
    cin>>target;

    Soultion s;
    vector<vector<int>> result = s.combinationSum(array, target);
    s.dispalyElemnt(result);


   
    system("pause");
    return 0;
}