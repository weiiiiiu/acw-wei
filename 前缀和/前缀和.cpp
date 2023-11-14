/*
假设我们有一个数组 a，我们可以计算出一个新的数组 p，
其中 p[i] 是 a[0] 到 a[i] 的和。这个 p 就是前缀和数组。

一旦计算出前缀和数组，我们就可以在常数时间内计算出任何一段连续子序列的和。
例如，如果我们想要计算 a[i] 到 a[j] 的和（其中 i <= j），
我们只需要计算 p[j] - p[i-1]（当 i > 0 时）或 p[j]（当 i = 0 时）
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10; // 限制

int n,m;
int a[N],s[N];

int main(){
    scanf ("%d%d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];//前缀和  
    while (m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);//子序列  l---r
    }

    return 0;
}