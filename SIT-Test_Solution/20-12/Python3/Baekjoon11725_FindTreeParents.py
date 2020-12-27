# Baekjoon11725_FindTreeParents.py
# https://www.acmicpc.net/problem/11725
import sys; input = sys.stdin.readline
sys.setrecursionlimit( 1000000 )

n = int( input() )

adjList = [ [ ] for _ in range( n + 1 ) ]
for _ in range( n - 1 ):
	a, b = map( int, input().split() )
	adjList[a].append( b )
	adjList[b].append( a )

parents = [ 0 for _ in range( n + 1 ) ]
def dfs( me, mom ):
	parents[me] = mom
	for son in adjList[me]:
		if ( son != mom ):
			dfs( son, me )

dfs( 1, 0 )

for i in range( 2, n + 1 ):
	print( parents[i] )
