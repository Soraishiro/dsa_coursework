
#include <iostream>
using namespace std;

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

void mergesort(char s[]){
    int a[100], count = 0;
    for (int i = 0; s[i] != NULL; ++i){
        a[i] = (int) s[i];
        count++;
    }
    Merge_Sort(a, 0, count - 1);
    for (int i = 0; i < count; ++i)
    {
        s[i] = (char) a[i];
    }
}

int main(){

      char s[100];

      cin >> s;

      mergesort(s);

      cout << s;

}