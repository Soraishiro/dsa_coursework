#include <iostream>
#include <set>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n]; set<int> se;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        se.insert(a[i]);
    }
    cout << se.size();
}