import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 아홉 난쟁이의 키 입력
        int[] h = new int[9];
        
        for(int i=0;i<9;i++)
        	h[i] = Integer.valueOf(br.readLine());
        
        Arrays.sort(h);
        
        // 아홉 난쟁이의 키의 합 계산
        int sum=0;
        
        for(int i=0;i<9;i++)
        	sum += h[i];
        
        // 일곱 난쟁이에 포함되지 않는 난쟁이 계산
        int except1=0, except2=0;
        
        for(int i=0;i<9;i++)
        	for(int j=i+1;j<9;j++)
        		if(sum-h[i]-h[j]==100) {
        			except1=i;
        			except2=j;
        			break;
        		}
        
        // 일곱 난쟁이의 키 출력
        for(int i=0;i<9;i++)
        	if(i!=except1&&i!=except2)
        		bw.write(h[i]+"\n");
        
        bw.close();
    } // end of main
} // end of Main class