import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// N개의 원소로 2048 진행
		int N = Integer.valueOf(br.readLine());
		
		PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		while(N-->0) {
			long a = Long.valueOf(st.nextToken());
			
			if(a!=0) {
				while(pq.contains(a)) {
					pq.remove(a);
					a*=2;
				}
				pq.add(a);
			}
		}
		
		// 만들 수 있는 가장 큰 값 출력
		bw.write(Long.toString(pq.poll()));

		bw.close();
	} // end of main()
} // end of Main class