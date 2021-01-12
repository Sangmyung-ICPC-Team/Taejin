// Baekjoon10942_Palindrome?.cpp
// https://www.acmicpc.net/problem/10942
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[2'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	bool dp[2'000][2'000] = { false, };
	for ( int i = 0; i < n; i++ ) {
		dp[i][i] = true;
		if ( i + 1 < n && arr[i] == arr[i + 1] )
			dp[i][i + 1] = true;
	}

	for ( int interval = 2; interval < n; interval++ ) {
		for ( int i = 0; i < n - interval; i++ ) {
			int j = i + interval;
			if ( arr[i] == arr[j] ) {
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}

	int q;
	cin >> q;

	while ( q-- ) {
		int s, e;
		cin >> s >> e;

		cout << dp[--s][--e] << '\n';
	}

	return 0;
}