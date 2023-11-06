import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static long MOD = 1_000_000_007;
	
	public static void main(String[] args) throws IOException {
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		long N = Long.valueOf(st.nextToken());
		long K = Long.valueOf(st.nextToken());
		
		// NCK = N!/(N-K)!K! % MOD 계산
		bw.write(Long.toString(fact(N)*pow(fact(N-K)*fact(K)%MOD, MOD-2)%MOD));
		
		bw.close();
	} // end of main()
	
	static long fact(long N) {
		long fact=1L;
		
		while(N>1) {
			fact=fact*N%MOD;
			N--;
		}
		
		return fact;
	} // end of fact()
	
	static long pow(long N, long K) {
		long pow=1;
		
		while(K>0) {
			if(K%2==1) {
				pow = pow*N%MOD;
				K--;
			}
			
			N=N*N%MOD;
			K>>=1;
		}
		
		return pow;
	} // end of pow()
} // end of Main class