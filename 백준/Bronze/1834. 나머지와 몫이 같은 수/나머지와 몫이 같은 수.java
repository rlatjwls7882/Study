import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // N 입력
        long N = Long.valueOf(br.readLine());
        
        // N으로 나눴을 때 몫과 나머지가 같은 수의 합 계산
        long sum=0;
        
        for(int i=1;i<N;i++)
        	sum += N*i+i;
        
        // N으로 나눴을 때 몫과 나머지가 같은 수의 합 출력
        bw.write(sum+"");
        
        bw.close();
    } // end of main
} // end of Main class