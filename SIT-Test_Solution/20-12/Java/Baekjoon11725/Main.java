// Main.java
// Baekjoon11725_FindParentOfTree
// https://www.acmicpc.net/problem/11725
import java.io.*;
import java.util.*;

public class Main {
	static int[] parents;
	static LinkedList<Integer>[] adjList;

	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		int n = Integer.parseInt( br.readLine() );

		parents = new int[n + 1];
		adjList = new LinkedList[n + 1];
		for ( int i = 1; i <= n; i++ )
			adjList[i] = new LinkedList<Integer> ();

		for ( int i = 0; i < n - 1; i++ ) {
			StringTokenizer st = new StringTokenizer( br.readLine() );

			int a = Integer.parseInt( st.nextToken() ),
				b = Integer.parseInt( st.nextToken() );

			adjList[a].add( b );
			adjList[b].add( a );
		}

		dfs( 1, 0 );

		for ( int i = 2; i <= n; i++ )
			bw.append( parents[i] + "\n" );
		bw.flush();

		br.close();
		bw.close();
	}

	public static void dfs( int me, int mom ) {
		parents[me] = mom;

		Iterator<Integer> iter = adjList[me].iterator();
		while ( iter.hasNext() ) {
			int son = iter.next();
			if ( son != mom )
				dfs( son, me );
		}
	}
};