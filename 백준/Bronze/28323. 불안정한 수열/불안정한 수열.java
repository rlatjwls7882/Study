import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		
		// 수열의 길이 N
		int N = Integer.valueOf(br.readLine());
		
		// 수열 입력
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] A = new int[N];
		
		for(int i=0;i<N;i++) {
			A[i] = Integer.valueOf(st.nextToken());
		}
		
		// 불안정한 수열의 최대 크기 계산
		int[] size = new int[N];
		Arrays.fill(size, 1);
		int max_size=1;
		
		for(int i=1;i<N;i++) {
			for(int j=0;j<i;j++) {
				if(A[i]%2==0&&A[j]%2==1||A[i]%2==1&&A[j]%2==0) {
					size[i] = Math.max(size[i], size[j]+1);
				}
			}
			max_size = Math.max(max_size, size[i]);
		}
		
		bw.write(Integer.toString(max_size));
		
		bw.close();
	} // end of main()
} // end of Main class