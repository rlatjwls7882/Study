import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		int T = Integer.valueOf(br.readLine());
		
		while(T-->0) {
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int A = Integer.valueOf(st.nextToken());
			int B = Integer.valueOf(st.nextToken());
			
			// A와 B의 최소 공통조상 찾기
			HashSet<Integer> parentList = new HashSet<Integer>();
			
			// A의 조상
			while(A!=0) {
				parentList.add(A);
				A/=2;
			}
			
			// B의 조상
			while(B!=0) {
				if(!parentList.add(B)) {
					break;
				}
				B/=2;
			}
			
			// 출력
			bw.write(Integer.toString(B*10));
			bw.newLine();
		}
		
		bw.close();
	} // end of main()
} // end of Main class