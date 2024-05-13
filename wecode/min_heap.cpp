/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

//###INSERT CODE HERE -

void Heapify(int A[], int N, int pos){
    int l = pos*2 + 1, r = pos*2 + 2;
    int min = pos;
    if (l < N && A[min] > A[l]) min = l;
    if (r < N && A[min] > A[r]) min = r;
    if (min != pos){
        swap(A[min], A[pos]);    
        Heapify(A, N, min);
    }
}

void BuildHeap(int A[], int N){
    for (int i = N/2 - 1; i >= 0; --i){
        Heapify(A, N, i);
    }
}

int SoNhoNhat(int a[], int n){
    int min = a[0];
    
}

void XuatMang(int a[], int n){
    if (n==0) std::cout << "Empty Array.";
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    if (n!=0) std::cout << "Minimum number: " << SoNhoNhat(a, n) << std::endl;

    XuatMang(a, n);

    return 0;
}
