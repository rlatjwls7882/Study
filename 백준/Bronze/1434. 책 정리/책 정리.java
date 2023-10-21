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

		// 박스의 개수 N, 책의 개수 M
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		
		// 박스의 용량 A
		int[] box = new int[N];
		st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<N;i++)
			box[i] = Integer.valueOf(st.nextToken());
		
		// 모든 책 집어넣기
		st = new StringTokenizer(br.readLine());
		int idx=0;
		
		while(M-->0) {
			int book = Integer.valueOf(st.nextToken());
			
			if(box[idx]<book) idx++;
			box[idx]-=book;
		}
		
		// 낭비되는 용량 계산
		int space=0;
		for(int i=0;i<N;i++)
			space += box[i];

		bw.write(space+"");
		
		bw.close();
	} // end of main
} // end of Main class