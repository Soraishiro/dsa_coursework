#include <iostream>
#include <set>
#include <math.h>
#define MAXN 100000
using namespace std;

int main(){
	//freopen("CodeMeLy_Input.txt","r",stdin);
	//freopen("CodeMeLy_Output.txt","w",stdout);

	int n, m, k; cin >> n >> m >> k;
	int a[MAXN];
	for (auto &i : a){
		cin >> i;
	}
	set<int> b;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0 && a[i] <= k)
		{
			b.insert(abs(m - 1 - i));
		}
	}
	if (!b.size()) cout << "-1";
	else cout << *b.begin()*10;
	return 0;
}