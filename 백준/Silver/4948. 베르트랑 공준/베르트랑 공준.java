import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	
    	while(true) {
    		
    		// n 입력
    		int n = Integer.valueOf(br.readLine());
    		if(n==0) break;
    		
    		// n<i<=2n 사이의 소수 i의 개수 계산
    		int sosu=0;
    		
    		for(int i=n+1;i<=2*n;i++) {
    			boolean isSosu=true;
    			
    			for(int j=2;j*j<=i;j++)
    				if(i%j==0) {
    					isSosu=false;
    					break;
    				}
    			
    			if(isSosu) sosu++;
    		}
    		
    		bw.write(sosu+"\n");
    	}
    	
    	bw.close();
    } // end of main
} // end of Main class