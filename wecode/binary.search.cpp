#include <iostream>
using namespace std;
#define MAXN 150000

void NhapMang(int A[], int n){
    for (int i = 0; i < n; ++i) cin >> A[i];
}

int binary_search(int A[], int n, int x){
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        if (A[mid] == x) return 1;
        else if (A[mid] > x) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i= binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}