// Baekjoon01977_PerfectSquare.c
// https://www.acmicpc.net/problem/1977
#include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int sum = 0, minVal = 0, num = 0;
	for ( int i = 1; i <= 100; i++ ) {
		int square = i * i;
		if ( square > m )
			break;
		else if ( square >= n ) {
			if ( !minVal )
				minVal = square;
			sum += square;
			num++;
		}
	}

	if ( num )
		printf("%d\n%d\n", sum, minVal);
	else
		printf("%d\n", -1);

	return 0;
}