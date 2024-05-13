#include <bits/stdc++.h>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(int a[][MAXC], int &r, int &c){
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void SapXepCotGiamDan(int a[][MAXC], const int r, const int c){
    for (int i = 0; i < c; ++i)
    {
        for (int j = 1; j < r; ++j){
            int pos = j - 1, key = a[j][i];
            while (pos >= 0 && a[pos][i] < key)
            {
                a[pos+1][i] = a[pos][i];
                --pos; 
            }
            a[pos + 1][i] =  key;
        }
    }
}

void XuatMaTran(int a[][MAXC], const int r, const int c){
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("wecode.inp","r",stdin);
    freopen("wecode.out","w",stdout);

    int a[MAXR][MAXC], r, c;
    NhapMaTran(a, r, c);
    SapXepCotGiamDan(a, r, c);
    XuatMaTran(a, r, c);
    return 0;
}
