// Main.java
// Baekjoon01965_PutBox
// https://www.acmicpc.net/problem/1965
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		int n = Integer.parseInt( br.readLine() );

		int[] boxes = new int[n];

		StringTokenizer st = new StringTokenizer( br.readLine() );
		for ( int i = 0; i < n; i++ )
			boxes[i] = Integer.parseInt(st.nextToken());

		int[] dp = new int[n];

		int ans = 0;
		for ( int i = n - 1; i >= 0; i-- ) {
			dp[i] = 1;
			for ( int j = i + 1; j < n; j++ )
				if ( boxes[i] < boxes[j] )
					dp[i] = max( dp[i], dp[j] + 1 );

			ans = max( ans, dp[i] );
		}

		bw.append( ans + "\n" );
		bw.flush();

		br.close();
		bw.close();
	}

	public static int max( int a, int b ) {
		return ( a > b ) ? a : b;
	}
};