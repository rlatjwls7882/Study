import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		int T = Integer.valueOf(br.readLine());
		
		while(T-->0) {
			String string = br.readLine();
			
			// 3-동전수열이 몇 번 나타났는지 계산
			int[] arr = new int[8];
			for(int i=0;i<38;i++) {
				if(string.substring(i, i+3).equals("TTT")) {
					arr[0]++;
				} else if(string.substring(i, i+3).equals("TTH")) {
					arr[1]++;
				} else if(string.substring(i, i+3).equals("THT")) {
					arr[2]++;
				} else if(string.substring(i, i+3).equals("THH")) {
					arr[3]++;
				} else if(string.substring(i, i+3).equals("HTT")) {
					arr[4]++;
				} else if(string.substring(i, i+3).equals("HTH")) {
					arr[5]++;
				} else if(string.substring(i, i+3).equals("HHT")) {
					arr[6]++;
				} else {
					arr[7]++;
				}
			}
			
			// 출력
			for(int i=0;i<8;i++) {
				bw.write(Integer.toString(arr[i]));
				bw.write(' ');
			}
			bw.newLine();
		}
		
		bw.close();
	} // end of main()
} // end of Main class