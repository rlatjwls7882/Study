import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 카드 생성
		int N = Integer.valueOf(br.readLine());
		Queue<Integer> cards = new LinkedList<Integer>();
		for(int i=1;i<=N;i++)
			cards.add(i);
		
		// 카드 뽑기
		while(cards.size()!=1) {
			bw.write(cards.poll()+" ");
			if(cards.size()==1) break;
			
			cards.add(cards.poll());
		}
		
		bw.write(cards.poll()+"");

		bw.close();
	} // end of main
} // end of Main class