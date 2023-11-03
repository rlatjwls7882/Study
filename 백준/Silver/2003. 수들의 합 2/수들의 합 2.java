import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 수열의 원소의 수 N, 만들 합 M
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		
		// 수열의 누적합 계산
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[N+1];
		for(int i=1;i<=N;i++) {
			arr[i] = arr[i-1]+Integer.valueOf(st.nextToken());
		}
		
		// 합이 M이 되는 경우의 수 계산
		int left=0, right=1, cnt=0;
		while(right<=N) {
			if(arr[right]-arr[left]==M) {
				cnt++;
				left++;
			} else if(arr[right]-arr[left]>M) {
				left++;
			} else {
				right++;
			}
		}

		bw.write(Integer.toString(cnt));

		bw.close();
	} // end of main()
} // end of Main class