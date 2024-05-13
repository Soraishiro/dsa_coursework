/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void ChenTang(int x, int *a, const int &n)
{
    a = new int[n + 1];
    int i = 0; 
    while (a[i] < x)
    {
        if (i < n) i++;
    } 
    for (int j = i + 1; i < n + 1; ++i)
    {
        a[j] = a[j - 1];
    }
    a[i] = x;
}

void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

