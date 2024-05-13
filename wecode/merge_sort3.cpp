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
void merge_2_Sorted_subArray(int a[], int l, int m, int r)
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
