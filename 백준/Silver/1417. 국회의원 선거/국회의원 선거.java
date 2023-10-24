import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 후보자 N명의 득표수 입력
		int N = Integer.valueOf(br.readLine());
		int candidate1 = Integer.valueOf(br.readLine());
		
		PriorityQueue<Integer> candidate = new PriorityQueue<>(Collections.reverseOrder());
		while(N-->1)
			candidate.add(Integer.valueOf(br.readLine()));
		
		// 매수해야 하는 사람의 최솟값 계산
		int cnt=0;
		if(!candidate.isEmpty())
			while(candidate.peek()>=candidate1) {
				candidate.add(candidate.poll()-1);
				candidate1++;
				cnt++;
			}
		
		bw.write(cnt+"");
		
		bw.close();
	} // end of main
} // end of Main class