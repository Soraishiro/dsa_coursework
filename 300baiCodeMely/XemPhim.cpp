#include <iostream>
#include <algorithm>
#define MAXN 200001
using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b){ 
     return (a.second < b.second);
}

int main()
{
    int n; cin >> n;
    pair<int, int> a[MAXN];
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort (a, a+n, cmp);
    for (int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << endl;
    int count = 1;
    for (int i = 1; i < n; ++i){
        int tmp = a[0].second;
        if (tmp <= a[i].first)
        {
            tmp = a[i].second;
            count++;
        }
    }
    cout << count;
    return 0;
}