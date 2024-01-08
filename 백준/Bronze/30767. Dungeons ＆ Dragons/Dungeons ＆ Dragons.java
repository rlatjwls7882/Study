import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		long n = Long.valueOf(br.readLine());
		long a = Long.valueOf(br.readLine());
		long b = Long.valueOf(br.readLine());
		long c = Long.valueOf(br.readLine());
		long d = Long.valueOf(br.readLine());
		
		// n을 만드는 경우의 수 계산
		n -= a+c;
		b -= a;
		d -= c;
		
		if(0<=n&&n<=b+d) {
			if(n<=b||n<=d) {
				bw.write(Long.toString(Math.min(Math.min(b, d), n)+1));
			} else {
				a = Math.min(b, n);
				n -= a;
				c = Math.min(d, n);
				n -= c;
				
				bw.write(Long.toString(d-c+1));
			}
		} else {
			bw.write("0");
		}
		
		bw.close();
	} // end of main()
} // end of Main class