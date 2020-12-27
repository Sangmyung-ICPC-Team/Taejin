# Baekjoon01965_PutBox.py
# https://www.acmicpc.net/problem/1965
import sys; input = sys.stdin.readline

n = int( input() )
boxes = list( map( int, input().split() ) )

ans = 1
dp = [ 0 for _ in range( n ) ]
for currBox in range( n - 1, -1, -1 ):
	dp[currBox] = 1
	for afterBox in range( currBox + 1, n ):
		if ( boxes[currBox] < boxes[afterBox] ):
			dp[currBox] = max( dp[currBox], dp[afterBox] + 1 )

	ans = max( ans, dp[currBox] )

print( ans )
