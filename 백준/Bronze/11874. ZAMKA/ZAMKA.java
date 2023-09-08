import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 정수 L, D, X 입력
        int L = Integer.valueOf(br.readLine());
        int D = Integer.valueOf(br.readLine());
        int X = Integer.valueOf(br.readLine());
        
        int min = 10000, max=1;
        
        for(int i=L;i<=D;i++) {
        	
        	// 자리 수의 합 계산
        	int sum=0, tmp=i;
        	
        	while(tmp!=0) {
        		sum += tmp%10;
        		tmp/=10;
        	}
        	
        	// 자리 수의 합이 X인 최소정수, 최대정수 계산
        	if(sum==X) {
        		
        		if(i<min) min=i;
        		if(i>max) max=i;
        	}
        }
        
        // 자리 수의 합이 X인 최소정수, 최대정수 출력
        bw.write(min+"\n"+max);
        bw.close();
    } // end of main
} // end of Main class