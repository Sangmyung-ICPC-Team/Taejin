// Main.java
// Java fast I/O Example
// Author: Taejin
import java.io.*; // BufferedReader, BufferedWriter, InputStreamReader, OutputStreamWriter
import java.util.StringTokenizer;

public class Main {
	// Exception 반드시 throws 해주기
	public static void main( String[] args ) throws Exception {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );

		// br.readLine()은 \n(LineFeed)까지 입력 받아서 String으로 반환(Python input과 같음)

		// 한 값 입력 받기
		int n = Integer.parseInt( br.readLine() );

		// 여러 값 입력 받아서 배열에 넣기
		int[] arr = new int[n];

		// "1 2 3 4 5" 이런 식으로 String 객체가 반환되므로 StringTokenizer를 이용하여 공백 기준으로 잘라줌
		StringTokenizer st = new StringTokenizer( br.readLine() );
		for ( int i = 0; i < n; i++ )
			arr[i] = Integer.parseInt( st.nextToken() );

		// 한줄 출력
		bw.append( n + "\n" );

		// 여러 값 한 줄에 출력
		for ( int i = 0; i < n; i++)
			bw.append( arr[i] + " " );
		bw.newLine(); // 다음 줄로 넘어감

		// 여러 값 한 줄씩 출력
		for ( int i = 0; i < n; i++ )
			bw.append( arr[i] + "\n" );

		// 반드시 flush()를 해줘야 출력이 됨
		bw.flush();

		// 사용후 반드시 닫아주
		br.close();
		bw.close();
	}
};