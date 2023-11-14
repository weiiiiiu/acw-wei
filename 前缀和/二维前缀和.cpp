/*
s[i - 1][j] 是上方位置的前缀和，即从 (1, 1) 到 (i - 1, j) 的所有元素之和。
s[i][j - 1] 是左方位置的前缀和，即从 (1, 1) 到 (i, j - 1) 的所有元素之和。
s[i - 1][j - 1] 是左上方位置的前缀和，即从 (1, 1) 到 (i - 1, j - 1) 的所有元素之和。在计算上方和左方的前缀和时，这个区域被重复计算了两次，所以需要减去一次。
a[i][j] 是当前位置的值。

*/


#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

int a[N][N], s[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i ++ )   
        for (int j = 1; j <= m; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];//前缀和

    while (q -- ) //q 表示要进行的查询次数
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;//子二维矩阵的和
    }

    return 0;
}
