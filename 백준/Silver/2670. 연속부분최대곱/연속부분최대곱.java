import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		int N = Integer.valueOf(br.readLine());
		
		// 연속된 곱의 최댓값 계산
		double[] dp = new double[N];
		dp[0]=Double.valueOf(br.readLine());
		double max=dp[0];
		
		for(int i=1;i<N;i++) {
			double curVal = Double.valueOf(br.readLine());
			dp[i] = Math.max(dp[i-1]*curVal, curVal);
			max = Math.max(max, dp[i]);
		}
		
		bw.write(String.format("%.03f", max));
		
		bw.close();
	} // end of main()
} // end of Main class