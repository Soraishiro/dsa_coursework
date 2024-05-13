#include <iostream>
#define MAXN 400000

void NhapMang(int *a, int &n){
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
}

int sentinelSearch(int *a, int n, int x)
{
    int tmp = a[n - 1];
    a[n - 1] = x;
    int i = 0;
    while (a[i] != x) i++;
    a[n - 1] = tmp;
    if ((i < n - 1) || (a[n - 1] == x)) return 1;
    else return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i= sentinelSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}

