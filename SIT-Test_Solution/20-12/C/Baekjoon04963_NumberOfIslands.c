// Baekjoon04963_NumberOfIslands.c
// https://www.acmicpc.net/problem/4963
#include <stdio.h>
#include <stdbool.h>

typedef struct Position {
	int row, col;
} Position;

int w, h, map[50][50];
bool visited[50][50];

void dfs( Position curr );

int main(void) {
	scanf( "%d %d", &w, &h );

	while ( w && h ) {
		for ( int i = 0; i < h; i++ ) {
			for ( int j = 0; j < w; j++ ) {
				visited[i][j] = false;
				scanf( "%d", &map[i][j] );
			}
		}

		int count = 0;
		for ( int i = 0; i < h; i++ ) {
			for ( int j = 0; j < w; j++ ) {
				if ( !visited[i][j] ) {
					visited[i][j] = true;
					if ( map[i][j] == 1 ) {
						Position start = { i, j };
						dfs( start );

						count++;
					}
				}
			}
		}

		printf( "%d\n", count );

		scanf( "%d %d", &w, &h );
	}

	return 0;
}

void dfs( Position curr ) {
	visited[curr.row][curr.col] = true;

	Position nexts[8] = {
		{ curr.row - 1, curr.col - 1 },
		{ curr.row - 1, curr.col },
		{ curr.row - 1, curr.col + 1 },
		{ curr.row, curr.col - 1 },
		{ curr.row, curr.col + 1 },
		{ curr.row + 1, curr.col - 1 },
		{ curr.row + 1, curr.col },
		{ curr.row + 1, curr.col + 1}
	};

	for ( int i = 0; i < 8; i++ ) {
		Position next = nexts[i];
		if ( ( 0 <= next.row && next.row < h ) && ( 0 <= next.col && next.col < w ) )
			if ( !visited[next.row][next.col] && map[next.row][next.col] == 1 )
				dfs( next );
	}
}