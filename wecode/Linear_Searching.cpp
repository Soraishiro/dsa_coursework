/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 400000

//###INSERT CODE HERE -
using namespace std;
void NhapMang(int *a, int &n)
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int LinearSearch(int *a, const int n, const int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (x == a[i]) return 1;
    }
    return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i= LinearSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
