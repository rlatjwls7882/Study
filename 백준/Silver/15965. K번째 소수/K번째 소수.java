import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int K = Integer.valueOf(br.readLine());
        
        // K번째 소수 계산
        int sosu=2;
        while(K>1)
        	for(int i=3;;i++) {
        		
        		boolean isSosu=true;
        		for(int j=2;j*j<=i;j++)
        			if(i%j==0) {
        				isSosu=false;
        				break;
        			}
        		
        		if(isSosu) {
        			sosu=i;
        			K--;
        		}
        		if(K==1) break;
        	}
        
        bw.write(sosu+"");
        
        bw.close();
    } // end of main
} // end of Main class