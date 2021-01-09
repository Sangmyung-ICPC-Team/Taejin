// Baekjoon18119_WordMemorization.cpp
// https://www.acmicpc.net/problem/18119
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int words[10'000] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		string str;
		cin >> str;

		for ( char& c : str )
			words[i] |= 1 << (c - 'a');
	}

	int memo = (1 << 26) - 1;
	while ( m-- ) {
		int o; char x;
		cin >> o >> x;

		memo ^= 1 << (x - 'a');

		int count = 0;
		for ( int i = 0; i < n; i++ )
			if ( (memo & words[i]) == words[i] )
				count++;

		cout << count << '\n';
	}

	return 0;
}
