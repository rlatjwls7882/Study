import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int N;
	static int[] price;
	
	public static void main(String[] args) throws IOException {
		
		N = Integer.valueOf(br.readLine())-1;
		
		// 도로와 주유소의 기름의 가격 입력
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] road = new int[N];
		for(int i=0;i<N;i++) {
			road[i] = Integer.valueOf(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		price = new int[N];
		for(int i=0;i<N;i++) {
			price[i] = Integer.valueOf(st.nextToken());
		}
		
		// 제일 오른쪽 도시로 가는 최소 비용 계산
		int cost=0;
		for(int i=0;i<N;i++) {
			if(isLowest(i)) {
				for(int j=i;j<N;j++) {
					cost += price[i]*road[j];
				}
				break;
			} else {
				cost += price[i]*road[i];
			}
		}
		
		bw.write(Integer.toString(cost));
		
		bw.close();
	} // end of main()
	
	static boolean isLowest(int pos) {
		int val = price[pos];
		
		while(pos<N) {
			if(val>price[pos++]) {
				return false;
			}
		}

		return true;
	} // end of isLowest()
} // end of Main class