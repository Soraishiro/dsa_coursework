#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, count = 0;
    long long X;
    cin >> N >> X;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            if ((long long) (pow(a[i], 2) + a[j] == X))
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}