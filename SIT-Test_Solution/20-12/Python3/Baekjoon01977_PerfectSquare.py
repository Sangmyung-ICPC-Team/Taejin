# Baekjoon01977_PerfectSquare.py
m = int( input() )
n = int( input() )

sumSquare, count, minVal = 0, 0, 10001

for i in range( 1, 101 ):
	square = i * i
	if ( square > n ):
		run = False
	else:
		if ( m <= square ):
			count += 1
			sumSquare += square
			minVal = min( minVal, square )

if ( count ):
	print( sumSquare )
	print( minVal )
else:
	print( -1 )
