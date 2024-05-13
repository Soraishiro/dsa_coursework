#include <iostream>
#include <set>
using namespace std;

int main(){
	freopen("CodeMeLy_Input.txt","r",stdin);
	freopen("CodeMeLy_Output.txt","w",stdout);
	int N;
	cin >> N;
	multiset<int> se;
	while (N > 1)
	{
		for (int i = 2; i <= N; ++i)
		{
			if (N % i == 0)
			{
				se.insert(i);
				N /= i;
				break;
			}
		}
	}
	for (auto it = se.begin(); it != se.end(); it++)
	{
		cout << *it;
		if (next(it) != se.end()) cout << "*";
	}
	return 0;
}