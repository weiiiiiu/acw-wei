#include <iostream>
using namespace std;

const int N = 1000010;
int n, q[N], tmp[N]; // temp合并后的数组

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1; // 第一组第一个 与 第二组第一个比较
    while (i <= mid && j <= r)     // 分界点取整 ，确保在各自组进行比较归并
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    // 最终分解之后的组有序的 从小到大排 [2]  [5,9]  进行合并时，2 合并之后 5，9 直接排1
    while (i <= mid)
        tmp[k++] = q[i++]; // 处理[5,9]
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j]; // 辅助数组返回至原数组 i跟随q[],j跟随tmp[]
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}