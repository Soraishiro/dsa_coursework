#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    map<int,int> mp;
    for (int i = 0; i < n; ++i){
        int key, value;
        cin >> key >> value;
        mp[key] = value;
    }
    int window[a+b];
    
    return 0;
}