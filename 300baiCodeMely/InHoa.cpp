#include <iostream>
using namespace std;

int main(){
	freopen("CodeMeLy_Input.txt","r",stdin);
	freopen("CodeMeLy_Output.txt","w",stdout);

	int n, m; cin >> n >> m;
	char a[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}  

	int b[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '#')
			{
				b[i][j]++;
			}
			else b[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (b[i][j])
			{
				if (i != n - 1)
				{
					if (a[i+1][j] == '.')
					{
						a[i+1][j] = '#';
						b[i+1][j] = 0;
					}
					if (a[i+1][j+1] == '.')
					{
						a[i+1][j+1] = '#';
						b[i+1][j+1] = 0;
					}
				}
				if (j != m - 1)
				{
					if (a[i][j+1] == '.')
					{
						a[i][j+1] = '#';
						b[i][j+1] = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}