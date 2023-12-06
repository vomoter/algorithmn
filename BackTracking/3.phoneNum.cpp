#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    ��������������2-9���ַ������������ܰ������ַ������

*/

class Soultion
{
private:
    vector<string> result; //������ܰ��������н����
    string path;            //���Ҷ�ӽڵ�

    //����ӳ����ַ���
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

    //���ݷ�������Ҫ����ַ���
    void trackBack(const string &digits, int index)
    {
        

        if(index == digits.size())
        {
            result.push_back(path);
            return;
        }

        int digitIndex = digits[index] - '0' ;    //�������ַ�ת��Ϊ����
        string temp = letterMap[digitIndex]; //����ӳ����ַ���
        for (int i = 0; i < temp.size(); i++)
        {
            path.push_back(temp[i]);
            trackBack(digits, index+1);
            path.pop_back();
        }
    }

public:
    //��ӡ�������Ԫ��
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
        //�������
        result.clear();
        path.clear();

        if (digits.size() == 0)     //����ַ���Ϊ�գ�ֱ�ӷ��ؽ��
            return result;
        trackBack(digits, 0);

        return result;
    }
};

int main()
{
    string numString;
    cout << "������ֻ����2-9���ַ���:";
    cin >> numString;
    Soultion s;
   //���û��ݷ�
    vector<string> result= s.letterCombintion(numString);

    s.displayElement(result);

    system("pause");
    return 0;
}