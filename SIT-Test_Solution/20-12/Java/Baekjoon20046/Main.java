// Main.java
// Baekjoon20046_RoadReconstruction
// https://www.acmicpc.net/problem/20046
import java.io.*;
import java.util.*;

class Node {
	int row, col, weight;
	Node( int row, int col, int weight ) {
		this.row = row;
		this.col = col;
		this.weight = weight;
	}
};

public class Main {
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		StringTokenizer st = new StringTokenizer( br.readLine() );
		int row = Integer.parseInt( st.nextToken() ),
			col = Integer.parseInt( st.nextToken() );

		int[][] roads = new int[row][col];
		for ( int i = 0; i < row; i++ ) {
			st = new StringTokenizer( br.readLine() );
			for ( int j = 0; j < col; j++ )
				roads[i][j] = Integer.parseInt( st.nextToken() );
		}

		if ( roads[0][0] == -1 || roads[row - 1][col - 1] == -1 )
			bw.append( -1 + "\n" );
		else {
			PriorityQueue<Node> pq = new PriorityQueue<Node> ( ( a, b ) -> {
				return a.weight - b.weight;
			} );

			pq.add( new Node( 0, 0, roads[0][0] ) );

			int ans = -1;
			boolean[][] visited = new boolean[row][col];
			while ( !pq.isEmpty() ) {
				Node curr = pq.poll();

				if ( curr.row == row - 1 && curr.col == col - 1 ) {
					ans = curr.weight;
					break;
				}

				if ( !visited[curr.row][curr.col] ) {
					visited[curr.row][curr.col] = true;

					Node[] nextPosition = new Node[] {
						new Node( curr.row - 1, curr.col, 0 ),
						new Node( curr.row, curr.col + 1, 0 ),
						new Node( curr.row + 1, curr.col, 0 ),
						new Node( curr.row, curr.col - 1, 0 )
					};

					for ( Node next : nextPosition ) {
						if ( ( 0 <= next.row && next.row < row ) && ( 0 <= next.col && next.col < col ) ) {
							if ( !visited[next.row][next.col] && roads[next.row][next.col] != -1 ) {
								next.weight = curr.weight + roads[next.row][next.col];
								pq.add( next );
							}
						}
					}
				}
			}

			bw.append( ans + "\n" );
		}

		bw.flush();

		br.close();
		bw.close();
	}
};