import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		int N = Integer.valueOf(br.readLine());
		String string = br.readLine();
		
		// R O Y G B I V가 있는지 확인
		boolean[][] chars = new boolean[7][2];
		
		for(int i=0;i<N;i++) {
			if(string.charAt(i)=='r') {
				chars[0][0]=true;
			} else if(string.charAt(i)=='R') {
				chars[0][1]=true;
			} else if(string.charAt(i)=='o') {
				chars[1][0]=true;
			} else if(string.charAt(i)=='O') {
				chars[1][1]=true;
			} else if(string.charAt(i)=='y') {
				chars[2][0]=true;
			} else if(string.charAt(i)=='Y') {
				chars[2][1]=true;
			} else if(string.charAt(i)=='g') {
				chars[3][0]=true;
			} else if(string.charAt(i)=='G') {
				chars[3][1]=true;
			} else if(string.charAt(i)=='b') {
				chars[4][0]=true;
			} else if(string.charAt(i)=='B') {
				chars[4][1]=true;
			} else if(string.charAt(i)=='i') {
				chars[5][0]=true;
			} else if(string.charAt(i)=='I') {
				chars[5][1]=true;
			} else if(string.charAt(i)=='v') {
				chars[6][0]=true;
			} else if(string.charAt(i)=='V') {
				chars[6][1]=true;
			}
		}
		
		// 무지개를 만들 수 있는지 확인
		if(chars[0][0]&&chars[1][0]&&chars[2][0]&&chars[3][0]&&chars[4][0]&&chars[5][0]&&chars[6][0]&&chars[0][1]&&chars[1][1]&&chars[2][1]&&chars[3][1]&&chars[4][1]&&chars[5][1]&&chars[6][1]) {
			bw.write("YeS");
		} else if(chars[0][0]&&chars[1][0]&&chars[2][0]&&chars[3][0]&&chars[4][0]&&chars[5][0]&&chars[6][0]) {
			bw.write("yes");
		} else if(chars[0][1]&&chars[1][1]&&chars[2][1]&&chars[3][1]&&chars[4][1]&&chars[5][1]&&chars[6][1]) {
			bw.write("YES");
		} else {
			bw.write("NO!");
		}
		
		bw.close();
	} // end of main()
} // end of Main class