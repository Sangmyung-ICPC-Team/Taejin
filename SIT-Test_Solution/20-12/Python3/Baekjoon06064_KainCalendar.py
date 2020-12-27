# Baekjoon06064_KainCalendar.py
# https://www.acmicpc.net/problem/6064
import sys; input = sys.stdin.readline

def GCD( a, b ):
	return ( GCD( b, a % b ) if b else a )

def LCM( a, b ):
	return a * b // GCD( a, b )

for _ in range( int( input() ) ):
	m, n, x, y = map( int, input().split() )

	boundary = LCM( n, m ) if ( n > m ) else LCM( m, n )

	diff = x - y
	if ( diff > 0 ):
		m, n = n, m
		x, y = y, x
		diff *= -1

	a, b, isFind = 1, 1, False
	for year in range( 1, boundary + 1, m ):
		if ( a - b == diff ):
			ans = year + x - a
			isFind = True
			break

		b = ( b + m ) % n

	if isFind:
		print( ans )
	else:
		print( -1 )
