// Baekjoon06064_KainCalendar.cpp
// https://www.acmicpc.net/problem/6064
#include <iostream>

#define SWAP( a, b ) { ll temp = a; a = b; b = temp; }

using namespace std;

typedef long long ll;

ll GCD( ll a, ll b ) {
	return ( b ? GCD( b, a % b ) : a );
}

ll LCM( ll a, ll b ) {
	return ( a * b ) / GCD( a, b );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		ll boundary = ( m < n ) ? LCM( n, m ) : LCM( m, n );

		int diff = x - y;
		if ( diff > 0 ) {
			SWAP( m, n );
			SWAP( x, y );
			diff *= -1;
		}

		bool isFind = false;
		int a = 1, b = 1, ans;
		for ( ll year = 1LL; year <= boundary; year += m ) {
			if ( a - b == diff ) {
				ans = year + x - a;
				isFind = true;
				break;
			}

			b = ( b + m ) % n;
		}

		if ( isFind )
			cout << ans;
		else
			cout << -1;
		cout << '\n';
	}

	return 0;
}
