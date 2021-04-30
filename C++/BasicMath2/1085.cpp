#include <cstdio>
using namespace std;
int main()
{
    int x, y, w, h = 0;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int esc_h = 0;
    int esc_v = 0;
    esc_h = x < w - x ? x : w - x;
    esc_v = y < h - y ? y : h - y;
    int final_esc = esc_h < esc_v ? esc_h : esc_v;
    printf("%d", final_esc);
}