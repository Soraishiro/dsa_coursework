#include <iostream>
using namespace std;

bool Palindrome(const int n)
{
	int copy = n, reverse = 0;
	while (copy)
	{
		reverse = reverse*10 + copy%10;
		copy /= 10;
	}
	return (n == reverse);
}

int main(){
	freopen("CodeMeLy_Input.txt","r",stdin);
	freopen("CodeMeLy_Output.txt","w",stdout);
	int x; cin >> x;
	while (x % 10 == 0)
	{
		x /= 10;
	}
	if (Palindrome(x)) cout << "YES";
	else cout << "NO";
	return 0;
}