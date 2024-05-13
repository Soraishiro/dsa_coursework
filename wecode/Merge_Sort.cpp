/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#define MAXN 200000
using namespace std;

void NhapMang(int *a, int &n){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int &N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int *x = new int [n1], *y = new int [n2];
    for (int i = l; i <= m; ++i){
        x[i - l] = a[i];
    }
    for (int i = m + 1; i <= r; ++i){
        y[i - m - 1] = a[i];
    }
    int i = 0, j = 0, count = l;
    while (i < n1 && j < n2){
        if (x[i] <= y[j]) a[count++] = x[i++];
        else a[count++] = y[j++];
    }
    while (i < n1) a[count++] = x[i++];
    while (j < n2) a[count++] = y[j++];
}

void Merge_Sort(int a[], int l, int r){
    if (l < r){
        int m = (l + r)/2;
        Merge_Sort(a, l, m);
        Merge_Sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int MergeSort(int a[], int n){
    Merge_Sort(a, 0, n - 1);
    return 0;
}

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
