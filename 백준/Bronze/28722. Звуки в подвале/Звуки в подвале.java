import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 문자열 s
        String s = br.readLine();
        
        // 자를 수 있는 횟수 계산
        int cut=0;
        char before = s.charAt(0);
        
        for(int i=1;i<s.length();i++) {
        	
        	if(before!=s.charAt(i))
        		cut++;
        	
        	before = s.charAt(i);
        }
        
        // 빌이 이길 수 있는지 확인
        bw.write(cut%2==1?"Win":"Lose");
        
        bw.close();
    } // end of main
} // end of Main class