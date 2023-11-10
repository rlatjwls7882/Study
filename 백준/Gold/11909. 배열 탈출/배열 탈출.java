import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] moveX = {1, 0};
	static int[] moveY = {0, 1};
	static int INF = 1_000_000_000, N;
	static int[][] routeVal, map;
	static boolean[][] visited;
	
	public static void main(String[] args) throws IOException {

		// 배열의 크기 N
		N = Integer.valueOf(br.readLine());
		
		// 초기화
		routeVal = new int[N][N];
		for(int i=0;i<N;i++) {
			Arrays.fill(routeVal[i], INF);
		}
		routeVal[0][0]=0;
		visited = new boolean[N][N];
		
		// 배열 입력
		map = new int[N][N];
		
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				map[i][j] = Integer.valueOf(st.nextToken());
			}
		}
		
		// 상수가 배열을 탈출하기 위해 들여야 할 최소비용 계산
		dijkstra();
		bw.write(Integer.toString(routeVal[N-1][N-1]));
		
		bw.close();
	} // end of main()
	
	static void dijkstra() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(0, 0, 0));
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			int x = curNode.x;
			int y = curNode.y;
			
			// 한번 간 장소 체크
			if(visited[x][y]) {
				continue;
			} else {
				visited[x][y]=true;
			}

			// 탈출
			if(x==N-1&&y==N-1) {
				return;
			}

			// 이동
			for(int i=0;i<2;i++) {

				int nextX = x+moveX[i];
				int nextY = y+moveY[i];

				if(x==N-1&&i==0||y==N-1&&i==1||visited[nextX][nextY]) {
					continue;
				}

				int nextRouteVal=routeVal[x][y];
				if(map[x][y]<=map[nextX][nextY]) {
					nextRouteVal+=map[nextX][nextY]-map[x][y]+1;
				}

				if(routeVal[nextX][nextY]>nextRouteVal) {
					routeVal[nextX][nextY]=nextRouteVal;
					pq.add(new Node(nextX, nextY, nextRouteVal));
				}
			}
		}

	} // end of dijkstra()
} // end of Main class

class Node implements Comparable<Node> {
	int x, y, cost;
	
	public Node(int x, int y, int cost) {
		this.x=x;
		this.y=y;
		this.cost=cost;
	}
	
	@Override
	public int compareTo(Node node) {
		return this.cost-node.cost;
	}
} // end of Node class