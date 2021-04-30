#include <cstdio>
using namespace std;
int main()
{
    int h1, h2, h3, v1, v2, v3 = 0;
    scanf("%d %d %d %d %d %d", &h1, &v1, &h2, &v2, &h3, &v3);
    int h = 0;
    int v = 0;
    if (h1 == h2)
        h = h3;
    else if (h1 == h3)
        h = h2;
    else if (h2 == h3)
        h = h1;

    if (v1 == v2)
        v = v3;
    else if (v1 == v3)
        v = v2;
    else if (v2 == v3)
        v = v1;

    printf("%d %d", h, v);
}