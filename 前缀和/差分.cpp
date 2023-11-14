
/*
差分与前缀和互为逆运算 a[i] = b[i] + b[i-1]   b[i] = a[i+1]-a[i]
a[5] =  b[1]+b[2]+b[3]+b[4]+b[5]
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], b[N]; // b数组初始化 0

//  同时加 c  两端操作
void insert(int l, int r, int c)
{

    b[l] += c;
    b[r + 1] -= c;
}
/*
b[i] = 0
b[i+1] = -a[i]
b[i+1] = a[i+1]
b[i+1] = a[i+1] - a[i]
*/

int main()
{
    int n;
    cin >> n;

    // 输入原数组
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // a 是原数组，b 是差分数组
    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1]; // 还原差分数组

    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    return 0;
}
