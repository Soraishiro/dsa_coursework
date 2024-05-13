#include <iostream>
using namespace std;

int main(){
	int N, Q; cin >> N >> Q;
	int A[N];
	for (int i = 0; i < N; ++i) cin >> A[i];
	int F[N];
	F[0] = A[0];
	for (int i = 1; i < N; ++i) F[i] = F[i-1] + A[i];

	while (Q--){
		int L, R;
		cin >> L >> R;
		cout << F[R] - F[L] + A[L] << endl;
	}
}