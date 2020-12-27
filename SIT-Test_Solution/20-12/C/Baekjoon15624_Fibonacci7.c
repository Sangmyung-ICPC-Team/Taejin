// Baekjoon15624_Fibonacci7.c
// https://www.acmicpc.net/problem/15624
#include <stdio.h>

#define MOD 1000000007

int main(void) {
	int n;
	scanf("%d", &n);

	int dp[1000001] = { 0, 1, 1, };
	for ( int i = 3; i <= n; i++ )
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	printf( "%d", dp[n] );

	return 0;
}
