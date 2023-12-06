#include<iostream>
#include<algorithm>
#include<vector>
using namespace  std;
/*
    40.组合总和2
    给出一个数组array和一个目标数target，找出array中
    所有可以使数字和为target的组合
    array中的每个数字在每个组合只能使用一次

    例子：
    输入 array= [10,1,2,7,6,1,5];
         target = 8;
    解集为：[[1,7], [1,2,5], [2,6], [1,1,6] ]

*/

class Soultion
{
private:
    vector<vector<int>> result; //存放组合集合
    vector<int> path;           //存放符合条件的组合

    //回溯法求解
    void backTrack(vector<int> &v, int target, int sum, int index, vector<bool> &used)
    {
        //如果求解值大于目标值终止
        if (sum > target)
            return;
        //如果求解值等于目标值把本次组合加入结果集
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = index; i < v.size(); i++)
        {
            if(i>0 && v[i] == v[i-1] && used[i-1] == false)   continue;
            sum += v[i];                  //把当前节点累加sum
            used[i] = true;
            path.push_back(v[i]);         //把当前节点加入组合集
            
            backTrack(v, target, sum, i+1,used); //递归求解,不用i+1 ,表示数字可以重复使用
            sum -= v[i];                  //把不满足条件的节点值减去
            used[i] = false;
            path.pop_back();              //不满足条件，回退
            
        }
    }

public:
    //迭代器打印而为数组
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

    //调用回溯法,返回结果解
    vector<vector<int>> combinationSum(vector<int> v, int target)
    {
        //清除数组
        result.clear();
        path.clear();
        //array元素排序，让相同的元素挨在一起
        sort(v.begin(), v.end());
        
        vector<bool> used;  //使用的元素数组初始化
        for (int i = 0; i < v.size(); i++)
        {
            used.push_back(false);
        }
        
        backTrack(v, target, 0, 0,used);
        return result; //返回结果集
    }

};
int main()
{
    vector<int> array = {10, 1, 2, 7, 6, 1, 5};
    int target;
    cout<<"请输入目标值：";
    cin>>target;

    Soultion s;
    vector<vector<int>> result = s.combinationSum(array, target);
    s.dispalyElemnt(result);


   
    system("pause");
    return 0;
}