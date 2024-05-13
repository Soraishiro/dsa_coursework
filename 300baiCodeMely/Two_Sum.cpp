#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CodeMeLy_Input.txt","r",stdin);
    freopen("CodeMeLy_Output.txt","w",stdout);
    int n, k; cin >> n >> k;
    long long a[n]; for (auto &it : a) cin >> it;
    bool flag = false;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j){
            if (a[i] + a[j] == k)
            {
                cout << i+1 << " " << j+1 << endl;
                flag = true;
            } 
        }
    }
    if (!flag) cout << "NO" << endl;
    return 0;
}