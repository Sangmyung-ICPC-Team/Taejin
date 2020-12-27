// Baekjoon06064_KainCalendar.c
// https://www.acmicpc.net/problem/6064
#include <stdio.h>

#define SWAP( a, b ) { ll temp = a; a = b; b = temp; }

typedef long long ll;

ll GCD( ll a, ll b ) {
	return ( b ? GCD( b, a % b ) : a );
}

ll LCM( ll a, ll b ) {
	return ( a * b ) / GCD( a, b );
}

int main(void) {
	int t;
	scanf("%d", &t);
	while ( t-- ) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		ll boundary = ( m < n ) ? LCM( n, m ) : LCM( m, n );

		int diff = x - y;
		if ( diff > 0 ) {
			SWAP( m, n );
			SWAP( x, y );
			diff *= -1;
		}

		int isFind = 0;
		int a = 1, b = 1, ans;
		for ( ll year = 1LL; year <= boundary; year += m ) {
			if ( a - b == diff ) {
				ans = year + x - a;
				isFind = 1;
				break;
			}

			b = ( b + m ) % n;
		}

		if ( isFind )
			printf("%d", ans );
		else
			printf("-1");
		printf("\n");
	}

	return 0;
}
