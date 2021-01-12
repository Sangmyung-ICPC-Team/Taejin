// Baekjoon12100_2048(Easy).cpp
// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>

using namespace std;

int n, ans;

void MoveAll( vector<vector<int>> board, int time );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<vector<int>> board ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> board[i][j];

	MoveAll( board, 0 );

	cout << ans << '\n';

	return 0;
}

vector<vector<int>> MoveUp( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( board[j][i] != 0 )
				newBoard[zeroIdx++][i] = board[j][i];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n - 1; j++ ) {
			if ( newBoard[j][i] != 0 && newBoard[j][i] == newBoard[j + 1][i] ) {
				newBoard[j][i] *= 2;
				newBoard[j + 1][i] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( newBoard[j][i] != 0 ) {
				int temp = newBoard[j][i];
				newBoard[j][i] = 0;
				newBoard[zeroIdx++][i] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveDown( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) { // column
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) { // row
			if ( board[j][i] != 0 )
				newBoard[zeroIdx--][i] = board[j][i];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j > 0; j-- ) {
			if ( newBoard[j][i] != 0 && newBoard[j][i] == newBoard[j - 1][i] ) {
				newBoard[j][i] *= 2;
				newBoard[j - 1][i] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( newBoard[j][i] != 0 ) {
				int temp = newBoard[j][i];
				newBoard[j][i] = 0;
				newBoard[zeroIdx--][i] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveLeft( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( board[i][j] != 0 )
				newBoard[i][zeroIdx++] = board[i][j];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n - 1; j++ ) {
			if ( newBoard[i][j] != 0 && newBoard[i][j] == newBoard[i][j + 1] ) {
				newBoard[i][j] *= 2;
				newBoard[i][j + 1] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( newBoard[i][j] != 0 ) {
				int temp = newBoard[i][j];
				newBoard[i][j] = 0;
				newBoard[i][zeroIdx++] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveRight( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( board[i][j] != 0 )
				newBoard[i][zeroIdx--] = board[i][j];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j > 0; j-- ) {
			if ( newBoard[i][j] != 0 && newBoard[i][j] == newBoard[i][j - 1] ) {
				newBoard[i][j] *= 2;
				newBoard[i][j - 1] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( newBoard[i][j] != 0 ) {
				int temp = newBoard[i][j];
				newBoard[i][j] = 0;
				newBoard[i][zeroIdx--] = temp;
			}
		}
	}

	return newBoard;
}


void MoveAll( vector<vector<int>> board, int time ) {
	if ( time == 5 ) {
		int maxScore = 0;
		for ( vector<int>& row : board )
			for ( int& value : row )
				maxScore = max( maxScore, value );

		ans = max( ans, maxScore );
	} else {
		int nextTime = time + 1;
		MoveAll( MoveUp( board ), nextTime );
		MoveAll( MoveDown( board ), nextTime );
		MoveAll( MoveLeft( board ), nextTime );
		MoveAll( MoveRight( board ), nextTime );
	}
}
