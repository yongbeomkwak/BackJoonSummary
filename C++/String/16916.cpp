/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

vector<int> getFail(const string &pattern)
{
    int m = pattern.size();
    int j = 0;
    vector<int> fail(m, 0);
    //fail[i]= 길이가 i+1일 때 maximum overlap 길이를 나타냄

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            //i는 1부터 j는 0부터
            //pattern[i]는 suffix, pattern[j]가 prefix
            // j는 길 j-1일 때 length of maximum overlap
            //계속 슬라이딩
            j = fail[j - 1];
        }
        if (pattern[i] == pattern[j]) //같으면 overlap 증가
        {
            fail[i] = ++j; //증가후 j를 삽입
        }
        else
        {
            fail[i] = j; //아니면 j 그대로 삽입
        }
    }
    return fail;
}

vector<int> kmp(const string &text, const string &pattern)
{
    vector<int> ans;
    int n = text.size();
    int m = pattern.size();
    vector<int> fail = getFail(pattern);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            //fail[j]=길이가 j+1인 패턴 위치 참조 시 틀릴경우 돌아가야할 위치를 기억
            j = fail[j - 1]; //j 번째 일때 j-1일 참조
        }
        if (text[i] == pattern[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - j);
                j = fail[j];
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

int main)(
{
    string text, pattern;

    cin >> text;
    cin >> pattern;

    vector<int> ans = kmp(text, pattern);

    if (ans.size() > 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
