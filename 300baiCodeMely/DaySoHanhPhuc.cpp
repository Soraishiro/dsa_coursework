#include <iostream>

using namespace std;

int main(){
	freopen("CodeMeLy_Input.txt","r",stdin);
	freopen("CodeMeLy_Output.txt","w",stdout);
	long long n; cin >> n;
	while (n != 1){
		cout << n << " ";
		n % 2 ? n = n*3 + 1 : n /= 2;
	}
	cout << 1;
	return 0;
}