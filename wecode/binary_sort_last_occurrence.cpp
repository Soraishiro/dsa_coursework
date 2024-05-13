/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int binary_search_last_occurrence(int *a, const int n, const int x)
{
    int l = 0, r = n - 1, res = -1;
    while (l <= r)
    {
        int m = l + (r - l)/2;
        if (a[m] == x)
        {
            res = m;
            l = m + 1;
        } 
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


