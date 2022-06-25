#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1500001
#define P pair<int, int>

string common_t;
unordered_map<string, string> um;

void init()
{
    um["ADD"] = "00000";
    um["ADDC"] = "00001";
    um["SUB"] = "00010";
    um["SUBC"] = "00011";
    um["MOV"] = "00100";
    um["MOVC"] = "00101";
    um["AND"] = "00110";
    um["ANDC"] = "00111";
    um["OR"] = "01000";
    um["ORC"] = "01001";
    um["NOT"] = "01010";
    um["MULT"] = "01100";
    um["MULTC"] = "01101";
    um["LSFTL"] = "01110";
    um["LSFTLC"] = "01111";
    um["LSFTR"] = "10000";
    um["LSFTRC"] = "10001";
    um["ASFTR"] = "10010";
    um["ASFTRC"] = "10011";
    um["RL"] = "10100";
    um["RLC"] = "10101";
    um["RR"] = "10110";
    um["RRC"] = "10111";
}
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
vector<vector<string>> commands;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    init();
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string in;
        getline(cin, in);
        commands.push_back(split(in));
    }

    for (int i = 0; i < commands.size(); i++)
    {
        string ret;
        for (int j = 0; j < commands[i].size(); j++)
        {
            if (j == 0)
            {
                ret += um[commands[i][j]] + '0';
            }
            else if (j == 3)
            {
                if (ret[4] == '0')
                {
                    ret += (bitset<3>(stoi(commands[i][j])).to_string() + '0');
                }
                else
                {
                    ret += bitset<4>(stoi(commands[i][j])).to_string();
                }
            }
            else
            {
                ret += bitset<3>(stoi(commands[i][j])).to_string();
            }
        }
        cout << ret << endl;
    }
    /*
    001010 001 000 0101
    001010 010 000 1010
    000000 011 001 0100
    000100 100 001 0100

    001010 001 000 0101
    001010 010 000 1010
    000000 011 001 0100
    000100 100 001 0100
    */
}
