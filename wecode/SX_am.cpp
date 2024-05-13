/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <set>
#define MAXN 100

using namespace std;

void NhapMang(int A[], int &N)
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
}

void SapXepSoAmTangDan(int a[], const int n)
{
    multiset<int> se;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0) se.insert(a[i]);
    }
    multiset<int>::iterator it = se.begin();
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            a[i] = *it;
            ++it;
        } 
    }
}
//###INSERT CODE HERE -
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << ' ';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
