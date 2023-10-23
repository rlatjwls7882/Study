import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 자료구조의 종류
		int N = Integer.valueOf(br.readLine());
		
		int[] A = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++)
			A[i] = Integer.valueOf(st.nextToken());
		
		// 들어있는 원소
		int[] B = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++)
			B[i] = Integer.valueOf(st.nextToken());
		
		// 삽입할 원소
		int M = Integer.valueOf(br.readLine());
		
		int[] C = new int[M];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<M;i++)
			C[i] = Integer.valueOf(st.nextToken());
		
		// deque 생성(stack일때는 변화가 없으니 queue일때만 원소 받아오기)
		Deque<Integer> deque = new ArrayDeque<Integer>();
		for(int i=0;i<N;i++)
			if(A[i]==0)
				deque.add(B[i]);
		
		// 원소 삽입(queue에 들어있는 원소만 한칸씩 밀림)
		for(int i=0;i<M;i++) {
			deque.addFirst(C[i]);
			bw.write(deque.pollLast()+" ");
		}
		
		bw.close();
	} // end of main
} // end of Main class