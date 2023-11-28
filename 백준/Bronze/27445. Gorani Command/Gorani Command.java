import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		
		// 맵의 크기 N*M
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		
		// 고라니가 있을 수 있는 모든 좌표 생성
		Deque<Pos> map = new ArrayDeque<>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				map.offer(new Pos(i, j));
			}
		}
		
		// 고라니가 숨어있는 칸의 좌표 계산
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0;st.hasMoreTokens();j++) {
				int dist = Integer.valueOf(st.nextToken());
				int size = map.size();

				while(size-->0) {
					Pos pos = map.poll();
					if(dist==Math.abs(pos.x-i)+Math.abs(pos.y-j)) {
						map.offer(pos);
					}
				}
				
				if(map.size()==1) {
					break;
				}
			}
			
			if(map.size()==1) {
				break;
			}
		}
		
		// 고라니가 숨어있는 칸의 좌표 출력
		Pos pos = map.poll();
		bw.write(String.format("%d %d", pos.x+1, pos.y+1));
		
		bw.close();
	} // end of main()
} // end of Main class

class Pos {
	int x, y;
	
	public Pos(int x, int y) {
		this.x=x;
		this.y=y;
	}
} // end of Pos class