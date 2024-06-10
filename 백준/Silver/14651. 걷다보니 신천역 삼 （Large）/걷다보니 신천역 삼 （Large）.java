import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static long MOD = 1_000_000_009;
	public static void main(String[] args) throws IOException {
		
		int N = Integer.valueOf(br.readLine());
		long[] dp = {0, 0, 0};
        
		if(N>=2) {
			dp = new long[] {0, 1, 1};
		}
		for(int i=0;i<N-2;i++) {
			long tmp = (dp[0]+dp[1]+dp[2])%MOD;
			dp = new long[] {tmp, tmp, tmp};
		}
		bw.write(Long.toString((dp[0]+dp[1]+dp[2])%MOD));
		
		bw.close();
	} // end of main
} // end of Main class