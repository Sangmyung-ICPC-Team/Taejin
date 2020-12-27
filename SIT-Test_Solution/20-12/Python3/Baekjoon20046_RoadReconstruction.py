# Baekjoon20046_RoadReconstruction.py
# https://www.acmicpc.net/problem/20046
import sys; input = sys.stdin.readline
import heapq

m, n = map( int, input().split() )

city = [ ]
for _ in range( m ):
	city.append( list( map( int, input().split() ) ) )

if ( city[0][0] == -1 or city[m - 1][n - 1] == -1 ):
	print( -1 )
else:
	# ( weight, row, col )
	pq = [ ]
	visited = [ [ False for _ in range( n ) ] for _ in range( m ) ]

	heapq.heappush( pq, ( city[0][0], 0, 0 ) )

	ans = -1
	while ( len( pq ) ):
		curr = heapq.heappop( pq )

		if ( not visited[curr[1]][curr[2]] ):
			visited[curr[1]][curr[2]] = True
			if ( curr[1] == m - 1 and curr[2] == n - 1 ):
				ans = curr[0]
				break

			nextPositions = [
				( curr[1] - 1, curr[2] ),
				( curr[1], curr[2] + 1 ),
				( curr[1] + 1, curr[2] ),
				( curr[1], curr[2] - 1 )
			]

			for nextPos in nextPositions:
				if ( ( 0 <= nextPos[0] < m ) and ( 0 <= nextPos[1] < n ) ):
					if ( not visited[nextPos[0]][nextPos[1]] and city[nextPos[0]][nextPos[1]] != -1 ):
						heapq.heappush( pq, ( curr[0] + city[nextPos[0]][nextPos[1]], nextPos[0], nextPos[1] ) )

	print( ans )
