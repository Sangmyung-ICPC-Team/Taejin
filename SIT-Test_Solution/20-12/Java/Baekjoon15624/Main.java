// Main.java
// Baekjoon15624_Fibonacci7
// https://www.acmicpc.net/problem/15624
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner( System.in );

		int n = scan.nextInt();

		int[] dp = new int[n + 10];
		dp[0] = 0;
		dp[1] = 1;

		for ( int i = 2; i <= n; i++ )
			dp[i] = ( dp[i - 1] + dp[i - 2] ) % 1_000_000_007;

		System.out.println( dp[n] );
	}
};