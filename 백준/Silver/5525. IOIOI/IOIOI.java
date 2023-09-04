import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 정수 N, 문자열의 길이 M, 문자열 S 입력
        int N = Integer.valueOf(br.readLine());
        int M = Integer.valueOf(br.readLine());
        String S = br.readLine();
        
        // PN 생성
        StringBuilder PN = new StringBuilder("I");
        
        while(N--!=0)
        	PN.append("OI");
        
        // S에 들어있는 PN의 개수 num 계산
        int index=0, num=0;
        String stringPN = PN.toString();
        
        while(true) {
        	index = S.indexOf(stringPN,index)+1;
        	
        	if(index==0) break;
        	
        	num++;
        }
        
        // num 출력
        bw.write(num+"");
        bw.close();
    } // end of main
} // end of Main class