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
		
		// 집의 수 N
		int N = Integer.valueOf(br.readLine());
		
		int[] cost = new int[3];
		while(N-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			// 다음 집을 칠하는 최소 비용 계산
			int[] next = new int[3];
			next[0] = Integer.valueOf(st.nextToken())+Math.min(cost[1], cost[2]);
			next[1] = Integer.valueOf(st.nextToken())+Math.min(cost[0], cost[2]);
			next[2] = Integer.valueOf(st.nextToken())+Math.min(cost[0], cost[1]);
			
			cost = next.clone();
		}
		
		// 모든 집을 칠하는 최소 비용 출력
		bw.write(Integer.toString(Math.min(Math.min(cost[0], cost[1]), cost[2])));
		
		bw.close();
	} // end of main()
} // end of Main class