// Baekjoon01965_PutBox.c
// https://www.acmicpc.net/problem/1965
#include <stdio.h>

int max( int a, int b ) {
	return ( a > b ) ? a : b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int arr[1000];
	for ( int i = 0; i < n; i++ )
		scanf("%d", &arr[i]);

	int dp[1000], ans = 1;
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[i] = 1;
		for ( int j = i; j < n; j++ ) {
			if ( arr[i] < arr[j] )
				dp[i] = max( dp[i], dp[j] + 1 );
		}

		ans = max( ans, dp[i] );
	}

	printf("%d\n", ans);

	return 0;
}
