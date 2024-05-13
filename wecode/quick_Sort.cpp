/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

int partition(int a[], int l, int r)
{
    int pivot = a[(l + r)/2];
      int i = l - 1, j = r + 1;
      while (true){
        do{
            ++i;
        }
        while (a[i] < pivot);
        do{
            --j;
        }
        while (a[j] > pivot);
        if (i >= j) return j;
        hoanvi(a[i], a[j]);
      }
}

void quick_sort(int a[], int l, int r){
    if (l < r){
        int p = partition(a, l, r);
        quick_sort(a, l, p);
        quick_sort(a, p + 1, r);
    }
}

void quick_sort_ascending(int a[], int n){
    quick_sort(a, 0, n - 1);
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
