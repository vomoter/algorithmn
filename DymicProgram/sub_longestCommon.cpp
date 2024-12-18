/*
 * @Author: YiFu
 * @Date: 2024-11-27 18:08:35
 * @LastEditTime: 2024-11-27 19:28:29
 * @FilePath: \DymicProgram\str_longestCommon.cpp
 * @Copyright: Copyright (c) 2024 by LiYiFu , All Rights Reserved.
 * @encoding: UTF-8
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:

输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
提示:

1 <= text1.length <= 1000
1 <= text2.length <= 1000 输入的字符串只含有小写英文字符。
 * 
 */
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for(int i = 1; i <= text1.length(); i++)
        {
            for(int j = 1; j <= text2.length(); j++)
            {
                if(text1[i-1] = text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};

int main()
{
    char text1[] = "abcde";
    char text2[] = "ace";
    Solution s;
    int result = s.longestCommonSubsequence(text1, text2);
    cout << result << endl;


    system("pause");
    return 0;
}