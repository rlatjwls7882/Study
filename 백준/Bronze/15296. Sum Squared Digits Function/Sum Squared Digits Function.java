import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		
		int P = Integer.valueOf(br.readLine());
		while(P-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int K = Integer.valueOf(st.nextToken());
			int b = Integer.valueOf(st.nextToken());
			int n = Integer.valueOf(st.nextToken());
			
			String string = Integer.toString(n, b);
			int sum=0;
			for(int i=0;i<string.length();i++) {
				if(string.charAt(i)>='a') {
					sum += Math.pow(string.charAt(i)-87, 2);
				} else {
					sum += Math.pow(string.charAt(i)-'0', 2);
				}
			}
			bw.write(K+" "+sum+"\n");
		}
		
		bw.close();
	} // end of main()
} // end of Main class