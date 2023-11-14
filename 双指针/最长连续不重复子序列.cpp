#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], s[N]; // s统计个数

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;//序列长
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++; // i,j共同维护一个具备check性质的区间
        while (s[a[i]] > 1)
        {
            s[a[j++]]--;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
