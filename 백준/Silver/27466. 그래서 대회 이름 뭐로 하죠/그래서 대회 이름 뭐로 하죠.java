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
		
		// 알파벳의 길이 N, 만들고 싶은 이름의 길이 M
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		
		// 알파벳 종류 확인
		String S = br.readLine();
		
		int[] chars = new int[26];
		char consonant = ' ';
		for(int i=0;i<N;i++) {
			if(consonant==' '&&!(S.charAt(i)=='A'||S.charAt(i)=='E'||S.charAt(i)=='I'||S.charAt(i)=='O'||S.charAt(i)=='U')) {
				consonant = S.charAt(i);
			} else {
				chars[S.charAt(i)-'A']++;
			}
		}
		
		// 운영진이 좋아하는 이름을 만들 수 있는지 확인
		if(chars[0]>=2&&consonant!=' '&&M>=3) {
			bw.write("YES\n");
			chars[0]-=2;
			
			int idx=0;
			for(int i=3;i<M;i++) {
				while(chars[idx]==0) {
					idx++;
				}
				bw.write(idx+'A');
				chars[idx]--;
			}
			bw.write("AA"+consonant);
			
		} else {
			bw.write("NO");
		}
		
		bw.close();
	} // end of main()
} // end of Main class