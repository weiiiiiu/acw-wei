#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    for (int i = 3; i >= 0; i--)
    {
        cout << (n >> i & 1);
    }

    return 0;
}