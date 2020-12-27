// Main.java
// Baekjoon06064_KainCalendar
// https://www.acmicpc.net/problem/6064
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static long GCD( long a, long b ) {
		return ( b != 0 ? GCD( b, a % b ) : a );
	}

	public static long LCM( long a, long b ) {
		return ( a * b / GCD( a, b ) );
	}

	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		int t;
		t = Integer.parseInt( br.readLine() );
		while ( t-- > 0 ) {
			StringTokenizer st = new StringTokenizer( br.readLine() );

			int m = Integer.parseInt( st.nextToken() );
			int n = Integer.parseInt( st.nextToken() );
			int x = Integer.parseInt( st.nextToken() );
			int y = Integer.parseInt( st.nextToken() );

			long boundary = ( m < n ) ? LCM( n, m ) : LCM( m, n );

			int diff = x - y;
			if ( diff > 0 ) {
				int temp = x;
				x = y;
				y = temp;

				temp = m;
				m = n;
				n = temp;

				diff *= -1;
			}

			int a = 1, b = 1;
			int ans = -1;
			for ( long year = 1l; year <= boundary; year += m ) {
				if ( a - b == diff ) {
					ans = (int)year + x - a;
					break;
				}

				b = ( b + m ) % n;
			}

			bw.write( ans + "\n" );
		}

		bw.flush();

		br.close();
		bw.close();
	}
};