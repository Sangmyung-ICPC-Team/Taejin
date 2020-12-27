// Main.java
// Baekjoon02225_SumDecomposition
// https://www.acmicpc.net/problem/2225
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );

		final int MOD = 1_000_000_000;
		int N = sc.nextInt(), K = sc.nextInt();

		long[][] dp = new long[N + 1][K + 1];
		for ( int i = 1; i <= K; i++ )
			dp[0][i] = 1;

		for ( int i = 1; i <= N; i++ ) {
			dp[i][1] = 1;
			for ( int j = 2; j <= K; j++ )
				for ( int k = 0; k <= i; k++ )
					dp[i][j] = (dp[i][j] + dp[k][j - 1]) % MOD;
		}

		System.out.println( dp[N][K] );

		sc.close();
	}
};