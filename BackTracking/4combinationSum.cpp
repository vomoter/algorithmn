#include <iostream>
#include <vector>
using namespace std;
/*
    给定一个无重复元素是数组array和一个目标数target,
    找出array重所有可以使数字和为target的组合
        所有数字都是正整数
        解集不能含有重复的组合
        1 <= array[i] <=200
    例子：
        输入 array = [2,3,6,7],target = 7
        解集为： [[7],[2,2,3]]
*/

class Soultion
{
private:
    vector<vector<int>> result; //存放结果集
    vector<int> path;           //存放叶子节点

    //回溯法求解
    void backTrack(vector<int> &v, int target, int sum, int index)
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
            sum += v[i];                  //把当前节点累加sum
            path.push_back(v[i]);         //把当前节点加入组合集
            backTrack(v, target, sum, i); //递归求解,不用i+1 ,表示数字可以重复使用
            sum -= v[i];                  //把不满足条件的节点值减去
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

        backTrack(v, target, 0, 0);
        return result; //返回结果集
    }
};

int main()
{
    vector<int> array = {1, 2, 3, 6, 7};
    int target;
    Soultion s;
    
    cout<<"请输入目标值:";
    cin>>target;
    vector<vector<int>> result = s.combinationSum(array, target);
    s.dispalyElemnt(result);    //打印结果集

    system("pause");
    return 0;
}