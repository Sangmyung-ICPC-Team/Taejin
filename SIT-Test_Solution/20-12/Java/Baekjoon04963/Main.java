// Main.java
// Baekjoon04963_NumberOfIslands
// https://www.acmicpc.net/problem/4963
import java.io.*;
import java.util.*;

class Position {
	int row, col;

	Position( int row, int col ) {
		this.row = row;
		this.col = col;
	}
};

public class Main {
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		StringTokenizer st = new StringTokenizer( br.readLine() );

		int w = Integer.parseInt( st.nextToken() ),
			h = Integer.parseInt( st.nextToken() );

		while ( w != 0 && h != 0 ) {
			int[][] map = new int[h][w];
			boolean[][] visited = new boolean[h][w];

			for ( int i = 0; i < h; i++ ) {
				st = new StringTokenizer( br.readLine() );
				for ( int j = 0; j < w; j++ )
					map[i][j] = Integer.parseInt( st.nextToken() );
			}

			int count = 0;
			for ( int i = 0; i < h; i++ ) {
				for ( int j = 0; j < w; j++ ) {
					if ( visited[i][j] == false ) {
						visited[i][j] = true;
						if ( map[i][j] == 1 ) {
							bfs( new Position( i, j ), map, visited, h, w );

							count++;
						}
					}
				}
			}

			bw.append( count + "\n" );

			st = new StringTokenizer( br.readLine() );
			w = Integer.parseInt( st.nextToken() );
			h = Integer.parseInt( st.nextToken() );
		}

		bw.flush();

		br.close();
		bw.close();
	}

	public static void bfs( Position start, int[][] map, boolean[][] visited, int h, int w ) {
		Queue<Position> q = new LinkedList<> ();
		q.add( start );

		while ( !q.isEmpty() ) {
			Position curr = q.poll();

			Position[] nextPositions = new Position[] {
				new Position( curr.row - 1, curr.col - 1 ),
				new Position( curr.row - 1, curr.col ),
				new Position( curr.row - 1, curr.col + 1 ),
				new Position( curr.row, curr.col - 1 ),
				new Position( curr.row, curr.col + 1 ),
				new Position( curr.row + 1, curr.col - 1 ),
				new Position( curr.row + 1, curr.col ),
				new Position( curr.row + 1, curr.col + 1 )
			};

			for ( Position next : nextPositions ) {
				if ( ( 0 <= next.row && next.row < h ) && ( 0 <= next.col && next.col < w ) ) {
					if ( !visited[next.row][next.col] && map[next.row][next.col] == 1 ) {
						visited[next.row][next.col] = true;
						q.add( next );
					}
				}
			}
		}
	}
};