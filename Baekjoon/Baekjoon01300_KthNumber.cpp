// Baekjoon01300_KthNumber.cpp
// https://www.acmicpc.net/problem/1300
#include <iostream>

using namespace std;

int n, k;

long smallerNumberThan( int a ) {
	long sum = 0l;
	for ( int i = 1; i <= n; i++ )
		sum += min( a / i, n );

	return sum;
}

int main(void) {
	cin >> n >> k;

	int left = 1, right = k;
	while ( left < right ) {
		int mid = ( left + right ) / 2;
		if ( k <= smallerNumberThan( mid ) )
			right = mid;
		else
			left = mid + 1;
	}

	cout << left << '\n';

	return 0;
}