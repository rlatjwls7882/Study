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
	static int INF = 1_000_000_000;
	
	public static void main(String[] args) throws IOException {
		
		// 마을의 수 N, 도로의 수 M, 모이는 장소 X
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		int X = Integer.valueOf(st.nextToken());
		
		// 초기화
		int[][] cost = new int[N+1][N+1];
		for(int i=1;i<=N;i++) {
			Arrays.fill(cost[i], INF);
			cost[i][i]=0;
		}
		
		// 도로 입력
		while(M-->0) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.valueOf(st.nextToken());
			int B = Integer.valueOf(st.nextToken());
			int C = Integer.valueOf(st.nextToken());
			cost[A][B]=C;
		}
		
		// N명의 학생들이 오고 가는 가장 짧은 시간 계산
		for(int mid=1;mid<=N;mid++) {
			for(int i=1;i<=N;i++) {
				for(int j=1;j<=N;j++) {
					if(cost[i][j]>cost[i][mid]+cost[mid][j]) {
						cost[i][j]=cost[i][mid]+cost[mid][j];
					}
				}
			}
		}
		
		// 왕복하는데 가장 오래 걸리는 학생의 소요시간 계산
		int max=0;
		for(int i=1;i<=N;i++) {
			if(i!=X) {
				max = Math.max(max, cost[i][X]+cost[X][i]);
			}
		}
		
		bw.write(Integer.toString(max));
		
		bw.close();
	} // end of main()
} // end of Main class