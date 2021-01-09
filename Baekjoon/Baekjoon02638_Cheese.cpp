// Baekjoon02638_Cheese.cpp
// https://www.acmicpc.net/problem/2638
#include <iostream>
#include <queue>

#define INSIDE -2

using namespace std;

typedef pair<int, int> pii;

const int rowChanges[4] = { -1, 0, 1, 0 }, colChanges[4] = { 0, 1, 0, -1 };

int n, m;
int cheeses[100][100];
bool visited[100][100];

int GetEmpty( int row, int col );
void DivisionInAndOut( int value ); // value보다 작거나 같은 값들을 value로 할당

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int restCheese = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			cin >> cheeses[i][j];
			if ( cheeses[i][j] )
				restCheese++;
			else
				cheeses[i][j] = INSIDE;
		}
	}

	int currTime = 1, nextTime = 2;
	while ( restCheese > 0 ) {
		// BFS로 외부 내부 분리
		DivisionInAndOut( currTime - 1 );

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				if ( cheeses[i][j] == currTime ) {
					int empty = GetEmpty( i, j );
					
					if ( empty >= 2 )
						restCheese--;
					else
						cheeses[i][j] = nextTime;
				}
			}
		}

		currTime = nextTime;
		nextTime++;
	}

	cout << currTime - 1 << '\n';

	return 0;
}

int GetEmpty( int row, int col ) {
	int count = 0;
	for ( int i = 0; i < 4; i++ ) {
		int newRow = row + rowChanges[i], newCol = col + colChanges[i];
		if ( ( 0 <= newRow && newRow < n ) && ( 0 <= newCol && newCol < m ) ) {
			if ( cheeses[newRow][newCol] != INSIDE && cheeses[newRow][newCol] < cheeses[row][col] )
				count++;
		}
	}

	return count;
}

void DivisionInAndOut( int value ) {
	queue<pii > q;
	bool visited[100][100] = { true, };

	cheeses[0][0] = value;
	q.push( { 0, 0 } );
	while ( !q.empty() ) {
		pii curr = q.front(); q.pop();

		for ( int i = 0; i < 4; i++ ) {
			int newRow = curr.first + rowChanges[i], newCol = curr.second + colChanges[i];
			if ( ( 0 <= newRow && newRow < n ) && ( 0 <= newCol && newCol < m ) ) {
				if ( !visited[newRow][newCol] ) {
					visited[newRow][newCol] = true;
					if ( cheeses[newRow][newCol] <= value ) {
						cheeses[newRow][newCol] = value;
						q.push( { newRow, newCol } );
					}
				}
			}
		}
	}
}