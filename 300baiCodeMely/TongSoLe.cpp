#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N; cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += ((a[i] % 2 != 0) ? a[i] : 0 );
    }
    cout << sum;
    return 0;
}