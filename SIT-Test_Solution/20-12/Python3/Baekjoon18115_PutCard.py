# Baekjoon18115_PutCard.py
import sys; input = sys.stdin.readline
from collections import deque

n = int( input() )
operations = list( map( int, input().split() ) )

operations.reverse()

num = 1

dq = deque()
for oper in operations:
	if ( oper == 1 ):
		dq.appendleft( num )
	elif ( oper == 2 ):
		temp = dq.popleft( )
		dq.appendleft( num )
		dq.appendleft( temp )
	else:
		dq.append( num )
	num += 1

for value in dq:
	print( value, end = ' ' )
print( )
