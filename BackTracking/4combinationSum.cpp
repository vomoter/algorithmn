#include <iostream>
#include <vector>
using namespace std;
/*
    ����һ�����ظ�Ԫ��������array��һ��Ŀ����target,
    �ҳ�array�����п���ʹ���ֺ�Ϊtarget�����
        �������ֶ���������
        �⼯���ܺ����ظ������
        1 <= array[i] <=200
    ���ӣ�
        ���� array = [2,3,6,7],target = 7
        �⼯Ϊ�� [[7],[2,2,3]]
*/

class Soultion
{
private:
    vector<vector<int>> result; //��Ž����
    vector<int> path;           //���Ҷ�ӽڵ�

    //���ݷ����
    void backTrack(vector<int> &v, int target, int sum, int index)
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
            sum += v[i];                  //�ѵ�ǰ�ڵ��ۼ�sum
            path.push_back(v[i]);         //�ѵ�ǰ�ڵ������ϼ�
            backTrack(v, target, sum, i); //�ݹ����,����i+1 ,��ʾ���ֿ����ظ�ʹ��
            sum -= v[i];                  //�Ѳ����������Ľڵ�ֵ��ȥ
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

        backTrack(v, target, 0, 0);
        return result; //���ؽ����
    }
};

int main()
{
    vector<int> array = {1, 2, 3, 6, 7};
    int target;
    Soultion s;
    
    cout<<"������Ŀ��ֵ:";
    cin>>target;
    vector<vector<int>> result = s.combinationSum(array, target);
    s.dispalyElemnt(result);    //��ӡ�����

    system("pause");
    return 0;
}