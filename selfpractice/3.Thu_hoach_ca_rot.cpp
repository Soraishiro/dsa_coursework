#include <iostream>
using namespace std;

int main()
{
	freopen("input.inp","r",stdin);
	freopen("output.out","w",stdout);
	int N, M; cin >> N >> M;
	int A[N][M];
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			cin >> A[i][j];
		}
	}
	// Xay dung mang cong don
	int pre[N][M];
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + A[i][j];
		}
	}

	int Q; cin >> Q;
	while (Q--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		cout << pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1] << endl;
	}
	return 0;
}