# Baekjoon15624_Fibonacci7.py
# https://www.acmicpc.net/problem/15624
import sys; input = sys.stdin.readline

MOD = 1_000_000_007

n = int( input() )

dp = [ 0, 1 ]
for i in range( 2, n + 1 ):
	dp.append( (dp[i - 1] + dp[i - 2]) % MOD )

print( dp[n] )
