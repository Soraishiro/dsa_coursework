#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("CodeMeLy_Input.txt","r",stdin);
	freopen("CodeMeLy_Output.txt","w",stdout);

	int n, m; cin >> n >> m;
	int a[n], b[m];
	for (auto &i : a){cin >> i;}
	for (auto &i : b){cin >> i;}
	sort(a, a + n);
	sort(b, b + m);
	int res = 0;
	res = a[0] > b[0] ? b[0]*10 + a[0] : a[0]*10 + b[0];
	cout << res;
}
