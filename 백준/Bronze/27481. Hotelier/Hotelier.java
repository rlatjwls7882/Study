import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 방 생성
        ArrayList<Integer> room = new ArrayList<Integer>();
        
        for(int i=0;i<10;i++)
        	room.add(0);
        
        // n 길이의 이벤트 입력
        int n = Integer.valueOf(br.readLine());
        String event = br.readLine();
        
        for(int i=0;i<n;i++) {
        	
        	// 왼쪽으로 들어온 손님
        	if(event.charAt(i)=='L')
        		room.set(room.indexOf(0), 1);
        	
        	// 오른쪽으로 들어온 손님
        	else if(event.charAt(i)=='R')
        		room.set(room.lastIndexOf(0), 1);
        	
        	// 손님이 방을 떠나는 경우
        	else
        		room.set(event.charAt(i)-'0', 0);
        }
        
        // 현재 방이 차있는 상태 출력
        for(int i=0;i<10;i++)
        	bw.write(room.get(i)+"");
        
        bw.close();
    } // end of main
} // end of Main class