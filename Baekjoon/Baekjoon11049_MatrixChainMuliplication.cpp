// Baekjoon11049_MatrixChainMuliplication.cpp
// https://www.acmicpc.net/problem/11049
#include <iostream>
#include <climits>

using namespace std;

struct Matrix {
	int row, col;
};

int main(void) {
	int n;
	cin >> n;

	Matrix matrix[500];
	for ( int i = 0; i < n; i++ )
		cin >> matrix[i].row >> matrix[i].col;

	int dp[500][500] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		fill( dp[i], dp[i] + n, INT_MAX );
		dp[i][i] = 0;
	}

	for ( int interval = 1; interval < n; interval++ ) {
		for ( int i = 0; i < n - interval; i++ ) {
			int j = i + interval;
			for ( int k = i; k < j; k++ )
				dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].row * matrix[k].col * matrix[j].col );
		}
	}

	cout << dp[0][n - 1] << '\n';

	return 0;
}
