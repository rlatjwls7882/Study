import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		String string = br.readLine();
		int length = string.length();
		
		// 사전순으로 최대 부분 수열 확인
		PriorityQueue<String> subStrings = new PriorityQueue<>(Collections.reverseOrder());
		for(int i=0;i<length;i++) {
			for(int j=i+1;j<=length;j++) {
				subStrings.add(string.substring(i, j));
			}
		}
		
		bw.write(subStrings.poll());
		
		bw.close();
	} // end of main()
} // end of Main class