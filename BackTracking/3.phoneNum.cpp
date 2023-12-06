#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    给定仅包含数字2-9的字符串，返回它能包含的字符串组合

*/

class Soultion
{
private:
    vector<string> result; //存放所能包含的所有结果集
    string path;            //存放叶子节点

    //数字映射的字符串
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9

    };

    //回溯法求满足要求的字符串
    void trackBack(const string &digits, int index)
    {
        

        if(index == digits.size())
        {
            result.push_back(path);
            return;
        }

        int digitIndex = digits[index] - '0' ;    //把数字字符转换为数字
        string temp = letterMap[digitIndex]; //数字映射的字符串
        for (int i = 0; i < temp.size(); i++)
        {
            path.push_back(temp[i]);
            trackBack(digits, index+1);
            path.pop_back();
        }
    }

public:
    //打印结果数组元素
    void displayElement(vector<string> &str)
    {
        for (string temp : str)
        {
            cout << temp << " ";
        }
        cout << endl;
    }
    vector<string> letterCombintion(string digits)
    {
        //清空数据
        result.clear();
        path.clear();

        if (digits.size() == 0)     //如果字符串为空，直接返回结果
            return result;
        trackBack(digits, 0);

        return result;
    }
};

int main()
{
    string numString;
    cout << "请输入只含有2-9的字符数:";
    cin >> numString;
    Soultion s;
   //调用回溯法
    vector<string> result= s.letterCombintion(numString);

    s.displayElement(result);

    system("pause");
    return 0;
}