import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static ArrayList<ArrayList<Integer>> connect = new ArrayList<>();
	static int INF=1_000_000_000;
	static boolean[] visited;
	static int[] routeVal;
	
	public static void main(String[] args) throws IOException {

		// 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시 X
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.valueOf(st.nextToken());
		int M = Integer.valueOf(st.nextToken());
		int K = Integer.valueOf(st.nextToken());
		int X = Integer.valueOf(st.nextToken())-1;
		
		// 초기화
		routeVal = new int[N];
		Arrays.fill(routeVal, INF);
		visited = new boolean[N];
		for(int i=0;i<N;i++) {
			connect.add(new ArrayList<>());
		}
		
		// 도로입력
		while(M-->0) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.valueOf(st.nextToken())-1;
			int B = Integer.valueOf(st.nextToken())-1;
			connect.get(A).add(B);
		}
		
		// 최단거리가 K인 도시 확인
		dijkstra(X);
		
		int cnt=0;
		for(int i=0;i<N;i++) {
			if(routeVal[i]==K) {
				bw.write(Integer.toString(i+1));
				bw.newLine();
				cnt++;
			}
		}
		
		if(cnt==0) {
			bw.write("-1");
		}
		
		bw.close();
	} // end of main()
	
	static void dijkstra(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		routeVal[start]=0;
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			start=curNode.pos;
			
			if(visited[start]) {
				continue;
			}
			visited[start]=true;
			
			for(int nextPos:connect.get(start)) {
				if(routeVal[nextPos]>routeVal[start]+1) {
					routeVal[nextPos]=routeVal[start]+1;
					pq.add(new Node(nextPos, routeVal[nextPos]));
				}
			}
		}
		
	} // end of dijkstra()
} // end of Main class

class Node implements Comparable<Node> {
	int pos, cost;
	
	public Node(int pos, int cost) {
		this.pos=pos;
		this.cost=cost;
	}
	
	@Override
	public int compareTo(Node node) {
		return this.cost-node.cost;
	}
} // end of Node class