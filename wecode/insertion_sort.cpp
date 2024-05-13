/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int Tim_Vi_Tri_Chen_X(const int x, int *a, const int l, int r)
{
    while (r >= l && x < a[r])
    {
        r--;
    }
    return r;
}

void Dich_Phai(int *a, const int l, const int r, const int pos)
{
    for (int i = r; i >= pos; --i)
    {
        a[i+1] = a[i];
    }
}

void insertionSort_TangDan(int *a, int n){
    for(int i=1; i<n; i++){
        int x=a[i];
        int k=Tim_Vi_Tri_Chen_X(x, a, 0, i-1); // Tìm x trong mảng a[0..i-1]
        Dich_Phai(a, 0, i-1, k);  // Dịch các giá trị mảng a[0..i-1] qua phải 1 đơn vị, bắt đầu từ vị trí k (0<=k<=i-1)
        a[k]=x;
    }
}

void XuatMang(int A[], const int &N) {
    if(N==0) {std::cout << "Empty List."; return;}
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertionSort_TangDan(a, n);

    XuatMang(a, n);

    return 0;
}
