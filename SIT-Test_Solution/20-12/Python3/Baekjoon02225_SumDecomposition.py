# Baekjoon02225_SumDecomposition.py
# https://www.acmicpc.net/problem/2225
MOD = 1_000_000_000

N, K = map( int, input().split() )

dp = [ [ 0 for _ in range( K + 1 ) ] for _ in range( N + 1 ) ]
for i in range( 1, K + 1 ):
	dp[0][i] = 1

for i in range( 1, N + 1 ):
	dp[i][1] = 1
	for j in range( 2, K + 1 ):
		for k in range( i + 1 ):
			dp[i][j] += dp[k][j - 1]
		dp[i][j] %= MOD

print( dp[N][K] )
