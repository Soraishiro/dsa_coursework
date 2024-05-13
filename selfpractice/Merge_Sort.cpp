#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; ++i){a1[i] = a[i + l];}
    for (int i = 0; i < n2; ++i){a2[i] = a[i + m + 1];}
    int i = 0, j = 0, count = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] >= a2[j]) a[count++] = a2[j++];
        else a[count++] = a1[i++];
    }
    while (i < n1){a[count++] = a1[i++];}
    while (j < n2){a[count++] = a2[j++];}
}

void Merge_Sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l)/2;
        Merge_Sort(a, l, m);
        Merge_Sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    
    int n; cin >> n;
    int a[n];
    for (auto &i : a) cin >> i;
    Merge_Sort(a, 0, n - 1);
    for (auto &i : a) cout << i << " ";
    return 0;
}