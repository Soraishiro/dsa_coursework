/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
//###INSERT CODE HERE -
#include <algorithm>
#include <math.h>
using namespace std;

struct PhanSo{
    int tu;
    int mau;
};

void Nhap(PhanSo *&a, int &n){
    cin >> n;
    a = new PhanSo[n];
    for (int i = 0; i < n; ++i) cin >> a[i].tu >> a[i].mau;
}

bool cmp(PhanSo a, PhanSo b){
    return (((a.tu * b.mau - b.tu * a.mau) * a.mau * b.mau ) > 0);
}

void SapXepGiamDan(PhanSo*a, int n){
    sort(a, a + n, cmp);
}

int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x % y);
}

void Xuat(PhanSo *a, int n){
    for (int i = 0; i < n; i++)
        {
            if (a[i].tu == 0) cout << 0 << endl;
            else {
                int tmp = gcd(abs(a[i].tu), abs(a[i].mau));
                if (a[i].tu % a[i].mau == 0) cout << a[i].tu / a[i].mau << endl;
                else 
                {
                    if (a[i].tu * a[i].mau < 0) cout << "-";
                    cout << abs(a[i].tu) / tmp  << "/" << abs(a[i].mau) / tmp << endl;
                }
            }
        }
} 

int main() {
    PhanSo *a;
    int n;
    Nhap(a, n);
    SapXepGiamDan(a, n);
    Xuat(a, n);
    return 0;
}
