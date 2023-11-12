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
		
		// 주가 입력, 특정 시점 전의 최솟값 계산
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] a = new int[N];
		int[] min = new int[N];
		
		for(int i=0;i<N;i++) {
			a[i] = Integer.valueOf(st.nextToken());
			
			if(i>0) {
				min[i] = Math.min(min[i-1], a[i]);
			} else {
				min[i] = a[i];
			}
		}
		
		// 각각의 날에 얻을 수 있는 최대 금액 계산
		int[] max = new int[N];
		
		for(int i=1;i<N;i++) {
			max[i] = Math.max(max[i-1], a[i]-min[i]);
		}
		
		bw.write(Integer.toString(max[N-1]));
		
		bw.close();
	} // end of main()
} // end of Main class