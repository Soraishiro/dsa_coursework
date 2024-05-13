#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n; cin >> n;
    int a[n]; 
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int start = 0, end = n - 1, s = 0, d = 0;
    bool sereja_turn = true;
    while (start <= end)
    {
        if (a[start] >= a[end])
        {
            if (sereja_turn)
            {
                b.push_back(a[start++]);
                sereja_turn = false;
            } 
            else 
            {
                c.push_back(a[start++]);
                sereja_turn = true;
            }
        }
        else if (a[start] <= a[end])
        {
            if (sereja_turn)
            {
                b.push_back(a[end--]);
                sereja_turn = false;
            } 
            else 
            {
                c.push_back(a[end--]);
                sereja_turn = true;
            }
        }
    } 
    for (auto it : b) s += it;
    for (auto it : c) d += it;
    cout << s << " " << d;
}