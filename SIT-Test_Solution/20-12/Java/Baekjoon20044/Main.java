// Main.java
// Baekjoon20044_ProjectTeams
// https://www.acmicpc.net/problem/20044
import java.util.*;
import java.io.*;

public class Main {
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		int n = Integer.parseInt( br.readLine() );
		n *= 2;

		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer( br.readLine() );
		for ( int i = 0; i < n; i++ )
			arr[i] = Integer.parseInt( st.nextToken() );

		Arrays.sort( arr );

		int minVal = 200_001;
		for ( int i = 0; i < n / 2; i++ )
			minVal = min( minVal, arr[i] + arr[n - i - 1] );

		bw.append( minVal + "\n" );
		bw.flush();

		br.close();
		bw.close();
	}

	public static int min( int a, int b ) {
		return ( a < b ) ? a : b;
	}
};