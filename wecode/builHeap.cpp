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

void Heapify(int A[], int N, int pos){
    int l = pos*2 + 1, r = pos*2 + 2;
    int max = pos;
    if (l < N && A[max] < A[l]) max = l;
    if (r < N && A[max] < A[r]) max = r;
    if (max != pos){
        swap(A[max], A[pos]);    
        Heapify(A, N, max);
    }
}

void BuildHeap(int A[], int N){
    for (int i = N/2 - 1; i >= 0; --i){
        Heapify(A, N, i);
    }
}

void XuatMang(int A[], int N){
    if (!N) std::cout << 0 << std::endl;
    else std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    BuildHeap(a, n);

    XuatMang(a, n);

    return 0;
}
