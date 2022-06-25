#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1500001
#define P pair<int, int>

string common_t;

vector<string> split(string s)
{
    vector<string> ret;

    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' '))
    {
        ret.push_back(tmp);
    }

    return ret;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string in;
    getline(cin, in);

    in.pop_back(); //';' 를제거 

    vector<string> after_split = split(in); //띄우쓰기로 띄운 후

    common_t = after_split[0]; //첫번 째는 공통된 타입 
    vector<string> variables(after_split.size() - 1, ""); //변수 모음 ,공통된 타입 뺏으니 -1개
    vector<string> opers(after_split.size() - 1, ""); //개별 타입 모음 

    for (int i = 1; i < after_split.size(); i++)
    {
        string curr_s = after_split[i];

        string oper;
        string variable;
        for (int j = 0; j < curr_s.size(); j++)
        {
            if (curr_s[j] == ',')
                continue;

            if (isalpha(curr_s[j])) //알파벳이면 변수 
                variable += curr_s[j];
            else //아니면 개별 타입
                oper += curr_s[j];
        }

        variables[i - 1] = variable; //변수 저장 
        string rev_oper;
        while (!oper.empty())
        {
            int curr_oper = oper.back();
            if (curr_oper == '[')
                curr_oper = ']';
            else if (curr_oper == ']')
                curr_oper = '[';
            
            //배열은 뒤집으면 이상해지니 해당 괄호의 반대로 
            rev_oper += curr_oper; //더하고 
            oper.pop_back(); //빼고 
        }
        if (!rev_oper.empty()) //비어있지않으면 해당 타입을 지정 
            opers[i - 1] = rev_oper;
    }

    for (int i = 0; i < variables.size(); i++)
    {
        if (opers[i].empty()) //개별 타입이 비어있으면 여기서
            cout << common_t << tab << variables[i] << ";" << endl;
        else //개별 타입 있으면 여기서
            cout << common_t << opers[i] << tab << variables[i] << ";" << endl;
    }
}
