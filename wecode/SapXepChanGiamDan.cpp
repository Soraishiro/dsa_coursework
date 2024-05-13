/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <set>
#define MAXN 100

using namespace std;
int Input()
{
    int N;
    cin >> N;
    return N;
}

void NhapMang(int A[], int N)
{
    for (int i = 0; i < N; ++i) cin >> A[i];
}

void SapXepSoChanGiamDan(int a[], const int n)
{
    multiset<int> se;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0) se.insert(a[i]);
    } 
    int b[se.size()], l = se.size() - 1;
    for (auto it : se)
    {
        b[l--] = it;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            a[i] = b[count++];
        }
    }
}

void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << ' ';
}
int main() {
    int a[MAXN], n;
    n=Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
