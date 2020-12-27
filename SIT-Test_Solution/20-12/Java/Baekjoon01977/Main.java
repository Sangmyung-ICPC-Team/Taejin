// Main.java
// Baekjoon01977_PerfectSquare
// https://www.acmicpc.net/problem/1977
import java.util.Scanner;

public class Main {
	public static int min( int a, int b ) {
		return ( a < b ) ? a : b;
	}

	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );

		int m ,n;
		m = sc.nextInt();
		n = sc.nextInt();

		int sum = 0, minVal = 10001;
		for ( int i = 1; i * i <= n; i++ ) {
			if ( i * i >= m ) {
				sum += i * i;
				minVal = min( minVal, i * i );
			}
		}

		if ( minVal != 10001 ) {
			System.out.println( sum );
			System.out.println( minVal );
		} else
			System.out.println( -1 );
	}
};