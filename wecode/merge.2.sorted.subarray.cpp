/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
//###INSERT CODE HERE -
void merge_2_Sorted_subArray(int *a, int l, int middle, int r)
{
    for (int i = 0; i <= r; ++i) a[i] = 0;
    int p1 = l, p2 = middle + 1, count = l;
    while (p1 <= middle && p2 <= r)
    {
        if (a[p1] <= a[p2]) a[count++] = a[p1++];
        else a[count++] = a[p2++];
    }
    while (p1 <= middle) a[count++] = a[p1++];
    while (p2 <= r) a[count++] = a[p2++];
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

	int l=0, r=n-1, middle =(l+r)/2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
