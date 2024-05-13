#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_leastGreater_firstOccurrence(int *a, const int N, const int X)
{
    int lo = 0, hi = N - 1, res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if (a[mid] <= X) lo = mid + 1;
        else
        {
            res = mid;
            hi = mid - 1;
        }
    }
    return res;
}


/*int binary_search_leastGreater_firstOccurrence(int a[], int n, int x)
{
    int l = 0, r = n - 1, res = -1;
    while (l <= r) 
    {
        int m = (r + l) / 2;
        if (a[m] == x) 
            l = m + 1;
        else if (a[m] > x) 
        {
            r = m - 1;
            res = m;
        }
        else if (a[m] < x) l = m + 1;
    }
    return res;
}
*/

int main() {
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_leastGreater_firstOccurrence(a, n, x);

    return 0;
}


