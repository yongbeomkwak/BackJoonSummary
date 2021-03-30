#include <iostream>
#include <string>

using namespace std;
int dialog(const string &str)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] <= 'O')
        // O 전까지는
        //65~67,A~C -> 3  (0,1,2) 0 -> 3
        //68~70,D~F -> 4  (3,4,5) 1 -> 4
        //71~73,G~I -> 5  (6,7,8) 2 -> 5
        //74~76,J~L -> 6  (9,10,11) 3 -> 6
        {
            cnt += ((int(str[i]) - 65) / 3) + 3;
        }
        else if ('P' <= str[i] && str[i] <= 'S')
        {
            cnt += 8;
        }
        else if (str[i] <= 'V')
        {
            cnt += 9;
        }
        else
        {
            cnt += 10;
        }
    }

    return cnt;
}
int main()
{
    // A: 65 W:87 V:86
    string str;

    cin >> str;
    printf("%d", dialog(str));
}