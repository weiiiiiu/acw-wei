#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int q[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1; // 二分起始坐标
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x) // 右边界都>=x   从起始位置往右都满足
                r = mid;     // 缩小满足性质的区间
            else
                l = mid + 1; //  mid进入满足性质的区间
        }
        if (q[l] != x) // 没有找到 x或者>x
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' '; // l=r
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << r << endl;
        }
    }
    return 0;
}