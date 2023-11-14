//高精度减法
#include <iostream>
#include <vector>

using namespace std;

//if A >= B A,B 都是非负整数
bool cmp(vector<int> &A, vector<int> &B){
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--){
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}


//C = A - B
vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;

    //t表示借位
    for (int i = 0, t = 0; i < A.size(); i++){
        t = A[i] - t;
        if (i < B.size()) t -= B[i];// t = A[i]-B[i]-t
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    //A.size = C.size 0003
    while (C.size() > 1 && C.back() == 0) C.pop_back(); //back最后一位
    return C;
}



int main(){
    string a, b;  
    vector<int> A, B; 
    cin >> a >> b;    

    for (int i = a.size() - 1; i >= 0; i--) 
        A.push_back(a[i] - '0'); 
    for (int i = b.size() - 1; i >= 0; i--)  
        B.push_back(b[i] - '0');

    if (cmp(A,B)){
        auto C = sub(A, B); 
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else {
        auto C = sub(B, A); 
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
 

    return 0;

}

