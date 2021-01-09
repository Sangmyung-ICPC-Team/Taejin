// Baekjoon07579_App.cpp
// https://www.acmicpc.net/problem/7579
#include <iostream>

#define MAX 10'001

using namespace std;

struct App {
	int cost, byte;
	App( ): cost( 0 ), byte( 0 ) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	App apps[100];
	for ( int i = 0; i < n; i++ )
		cin >> apps[i].byte;

	for ( int i = 0; i < n; i++ )
		cin >> apps[i].cost;

	int ans = 0;
	int dp[MAX][100] = { 0, };
	for ( int i = 1; i < MAX; i++ ) {
		int maxMemory = 0;
		if ( apps[0].cost <= i ) {
			dp[currCost][0] = apps[0].byte;
			maxMemory = apps[0].byte;
		}

		for ( int j = 1; j < n; j++ ) {
			if ( apps[j].cost <= currCost )
				dp[currCost][j] = max( dp[currCost][j - 1], dp[currCost - apps[j].cost][j - 1] + apps[j].byte );
			else
				dp[currCost][j] = dp[currCost][j - 1];

			maxMemory = max( maxMemory, dp[currCost][i] );
		}

		if ( maxMemory >= m ) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}