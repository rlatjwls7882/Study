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
    	
    	// A와 B의 점수를 2진수로 변환하여 입력
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	String scoreA = Integer.toBinaryString(Integer.valueOf(st.nextToken()));
    	String scoreB = Integer.toBinaryString(Integer.valueOf(st.nextToken()));
    	
    	// C의 점수 계산
    	int scoreC=0;
    	
    	for(int i=1;i<=10;i++) {
    		try {
    			// 표적을 한명만 맞춘 경우
				if(scoreA.charAt(scoreA.length()-i)!=scoreB.charAt(scoreB.length()-i))
					scoreC+=Math.pow(2, i-1);
			} catch (Exception e) {
				
				// scoreA ==  110111
				// scoreB == 1001001 인경우
				if(scoreA.length()-i>=0)
					scoreC+=Math.pow(2, i-1)*(scoreA.charAt(scoreA.length()-i)-'0');
				
				if(scoreB.length()-i>=0)
					scoreC+=Math.pow(2, i-1)*(scoreB.charAt(scoreB.length()-i)-'0');
			}
    	}
    	
    	// C의 점수 출력
    	bw.write(scoreC+"");
    	bw.close();
    } // end of main
} // end of Main class