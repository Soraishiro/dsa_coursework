/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}


void ChenTang(int x, int *a, int &n)
{
    int pos = 0;
    while (x >= a[pos] && pos < n) pos++;
    n++;
    for (int i = n - 1; i >= pos; --i)
    {
        a[i + 1] = a[i];
    }
    a[pos] = x;
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

