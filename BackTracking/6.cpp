#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Soultion
{
private:
    vector<vector<string>> result; //��Ž�����ĵĽ������
    vector<string> path;           //�����Ѿ����ĵ��Ӵ�

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
    
    //��ӡ���vector<vector<string>>����Ԫ��
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

    //���ݷ����
    vector<vector<string>> partition(string s)
    {
        //�������
        result.clear();
        path.clear();
        //���û��ݷ�
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