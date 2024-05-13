#include <iostream>
#include <algorithm>
#define MAXN 200001
int main()
{
    int n, x; std::cin >> n >> x;
    int a[MAXN];
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::sort(a, a+n);
    int start = 0, end = n - 1, count = 0;
    while(start < end){
        if (a[start] + a[end] <= x){
            start++;
            end--;
        }
        else end--;
        count++;
    }
    count = (start == end) ? count+1 : count;
    std::cout << count;
    return 0;
}