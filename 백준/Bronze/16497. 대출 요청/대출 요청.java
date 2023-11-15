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
		
		int N = Integer.valueOf(br.readLine());
		
		// 각 날마다 책이 빌려지는 횟수 계산
		int[] borrow = new int[32];
		while(N-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.valueOf(st.nextToken());
			int end = Integer.valueOf(st.nextToken());
			
			while(start<end) {
				borrow[start++]++;
			}
		}
		
		// 도서 대출이 모두 가능한지 확인
		int K = Integer.valueOf(br.readLine());
		boolean isOK=true;
		
		for(int i=0;i<32;i++) {
			if(borrow[i]>K) {
				isOK=false;
				break;
			}
		}
		
		if(isOK) {
			bw.write("1");
		} else {
			bw.write("0");
		}
		
		bw.close();
	} // end of main()
} // end of Main class