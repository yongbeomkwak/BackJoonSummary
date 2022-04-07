#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        string in;
        getline(cin, in);
        if (in == "")
            break;

        int *arr;

        arr = (int *)calloc(4, sizeof(int));
        for (const char &c : in)
        {
            if (islower(c))
            {
                arr[0]++;
                continue;
            }
            if (isupper(c))
            {
                arr[1]++;
                continue;
            }
            if (isdigit(c))
            {
                arr[2]++;
                continue;
            }
            if (isspace(c))
            {
                arr[3]++;
            }
        }

        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
        free(arr);
    }
}
