#include <iostream>

using namespace std;

const int N = 1e6 + 10; // 限制

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[l], i = l - 1, j = r + 1; // 先移动再判断
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}
/*
l 和 r 是传递给 quick_sort 函数的参数，它们表示要排序的数组部分的开始和结束位置。在最初的调用中，l 是 0（数组的开始），r 是 n - 1（数组的结束）。

在 quick_sort 函数中，i 和 j 是用来遍历数组的指针。i 从 l - 1 开始，j 从 r + 1 开始。这是因为在进入循环之前，i 和 j 都会先增加或减少，所以实际上，i 从 l 开始，j 从 r 开始。

在循环中，i 和 j 会向对方移动，直到找到一个需要交换的元素。当 i 不再小于 j 时，循环结束。

在循环结束后，j 是新的分界点，所有在 j 左边的元素都小于 x，所有在 j 右边的元素都大于 x。然后，quick_sort 递归地对 j 左边和右边的元素进行排序。

q[i]与q[j]进行交换 不是i,j

*/