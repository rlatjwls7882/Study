import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	
    	// 연산의 개수 N
    	int N = Integer.valueOf(br.readLine());
    	
    	// N개의 연산 수행
    	PriorityQueue<Long> absMin = new PriorityQueue<>(new Comparator<Long>() {

    		@Override
    		public int compare(Long o1, Long o2) {

    			if(Math.abs(o1)>Math.abs(o2))
    				return 1;
    			else if(Math.abs(o1)==Math.abs(o2)&&o1>o2)
    				return 1;
    			else
    				return -1;
    		}
    	});
    	
    	while(N-->0) {
    		
    		long x = Long.valueOf(br.readLine());
    		
    		// x가 0이 아닌 경우
    		if(x!=0)
    			absMin.add(x);
    		
    		// x가 0인 경우
    		else if(!absMin.isEmpty())
    			bw.write(absMin.poll()+"\n");
    		else
    			bw.write("0\n");
    	}
    	
    	bw.close();
    } // end of main
} // end of Main class