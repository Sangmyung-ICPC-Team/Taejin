// Main.java
// Baekjoon18115_PutCard
// https://www.acmicpc.net/problem/18115
import java.io.*;
import java.util.*;

public class Main {
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		int n = Integer.parseInt( br.readLine() );

		int[] opr = new int[n];
		StringTokenizer st = new StringTokenizer( br.readLine() );
		for ( int i = 0; i < n; i++ )
			opr[i] = Integer.parseInt( st.nextToken() );

		int num = 1;
		Deque<Integer> dq = new ArrayDeque<Integer> ();
		for ( int i = n - 1; i >= 0; i-- ) {
			if ( opr[i] == 1 )
				dq.addFirst( num );
			else if ( opr[i] == 2 ) {
				int temp = dq.pollFirst();
				dq.addFirst( num );
				dq.addFirst( temp );
			} else
				dq.addLast( num );

			num++;
		}

		Iterator<Integer> iter = dq.iterator();
		while ( iter.hasNext() )
			bw.append( iter.next() + " " );
		bw.append( "\n" );

		bw.flush();

		br.close();
		bw.close();
	}
};