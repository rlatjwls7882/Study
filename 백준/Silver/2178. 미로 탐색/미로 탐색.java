import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// 미로의 열 수 N, 행 수 M
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		
		// 미로 입력
		boolean[][] maze = new boolean[N][M];
		
		for(int i=0;i<N;i++) {
			String string = br.readLine();
			for(int j=0;j<M;j++)
				if(string.charAt(j)=='1')
					maze[i][j]=true;
		}
		
		// 도착지점까지 움직이는 최소 횟수 계산
		LinkedList<Pos> queue = new LinkedList<>();
		queue.add(new Pos(0, 0, 1));
		maze[0][0]=false;
		int moveCnt=0;
		
		while(!queue.isEmpty()) {
			
			Pos tmp = queue.poll();
			
			// 위
			if(tmp.y-1>=0&&maze[tmp.y-1][tmp.x]) {
				queue.add(new Pos(tmp.x, tmp.y-1, tmp.move+1));
				maze[tmp.y-1][tmp.x]=false;
			}
			
			// 아래
			if(tmp.y+1<N&&maze[tmp.y+1][tmp.x]) {
				queue.add(new Pos(tmp.x, tmp.y+1, tmp.move+1));
				maze[tmp.y+1][tmp.x]=false;
			}
			
			// 왼쪽
			if(tmp.x-1>=0&&maze[tmp.y][tmp.x-1]) {
				queue.add(new Pos(tmp.x-1, tmp.y, tmp.move+1));
				maze[tmp.y][tmp.x-1]=false;
			}
			
			// 오른쪽
			if(tmp.x+1<M&&maze[tmp.y][tmp.x+1]) {
				queue.add(new Pos(tmp.x+1, tmp.y, tmp.move+1));
				maze[tmp.y][tmp.x+1]=false;
			}
			
			// 도착지점 도달
			if(tmp.x==M-1&&tmp.y==N-1) {
				moveCnt=tmp.move;
				break;
			}
		}
		
		bw.write(moveCnt+"");
		bw.close();
	} // end of main()
} // end of Main class

class Pos {
	int x;
	int y;
	int move;
	
	public Pos(int x, int y, int move) {
		this.x=x;
		this.y=y;
		this.move=move;
	}
} // end of Pos class