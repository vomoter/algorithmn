#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Soultion
{
private:
    vector<vector<string>> result; //存放结果回文的结果集合
    vector<string> path;           //放入已经回文的子串

    bool isPalindrome(string &str, int start, int end)
    {
        int i, j;
        for (i = start, j = end; i < j; i++, j--)
        {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }
    
    void backTrack(string &str, int startIndex)
    {
        if (startIndex >= str.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < str.size(); i++)
        {
            if (isPalindrome(str, startIndex, i))
            {
                string temp = str.substr(startIndex, i - startIndex + 1);
                path.push_back(temp);
            }
            else
            {
                continue;
            }
            backTrack(str, i + 1);
            path.pop_back();
        }
    }


public:
    
    //打印结果vector<vector<string>>数组元素
    void displayElement(vector<vector<string>> &str)
    {
        for (vector<vector<string>>::iterator it = str.begin(); it != str.end(); it++)
        {
            for(vector<string>::iterator item =(*it).begin(); item != (*it).end(); item++)
            {
                cout<<*item<<"  ";
            }
            cout<<endl;
            
        }
        
        cout << endl;
    }

    //回溯法求解
    vector<vector<string>> partition(string s)
    {
        //清空容器
        result.clear();
        path.clear();
        //调用回溯法
        backTrack(s,0);
        
        return result;
    }
    
    
};

int main()
{
    string str = {"aab"};
    Soultion s;
    vector<vector<string>> result = s.partition(str);
    s.displayElement(result);

    system("pause");
    return 0;
}