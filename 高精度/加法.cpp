#include <iostream>
#include <string>
using namespace std;


vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    if (A.size() < B.size()) return add(B, A); // 保证A是长的
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
            t += A[i];
        if (i < B.size())
            t += B[i];  //t = A[i]+B[i]+t t是进位
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    return C;
}



int main()
{
    string a, b;  //字符串存取
    vector<int> A, B; // 创建了两个可以存储整数的动态数组A和B
    cin >> a >> b;    //"12345"
    for (int i = a.size() - 1; i >= 0; i--) 
        A.push_back(a[i] - '0'); // 54321 a[i] - '0' 字符————整数。
    for (int i = b.size() - 1; i >= 0; i--)  
        B.push_back(b[i] - '0');

    auto C = add(A, B); // auto 自动推导类型
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}
