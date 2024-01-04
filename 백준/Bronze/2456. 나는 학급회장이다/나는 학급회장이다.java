import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		
		int N = Integer.valueOf(br.readLine());
		
		// 투표 결과 확인
		int[] totalScore = new int[3];
		int[] score3 = new int[3];
		int[] score2 = new int[3];
		
		while(N-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int i=0;i<3;i++) {
				int num = Integer.valueOf(st.nextToken());
				totalScore[i] += num;
				if(num==3) {
					score3[i]++;
				} else if(num==2) {
					score2[i]++;
				}
			}
		}
		
		// 누가 회장으로 당선되었는지 확인
		int winner = chkWinner(totalScore, score3, score2);
		
		if(winner==0) {
			bw.write(String.format("0 %d", Math.max(Math.max(totalScore[0], totalScore[1]), totalScore[2])));
		} else {
			bw.write(String.format("%d %d", winner, totalScore[winner-1]));
		}
		
		bw.close();
	} // end of main()
	
	static int chkWinner(int[] totalScore, int[] score3, int[] score2) {
		if(totalScore[0]>totalScore[1]&&totalScore[0]>totalScore[2]) {
			return 1;
		} else if(totalScore[1]>totalScore[0]&&totalScore[1]>totalScore[2]) {
			return 2;
		} else if(totalScore[2]>totalScore[0]&&totalScore[2]>totalScore[1]) {
			return 3;
		} else if(totalScore[0]==totalScore[1]&&totalScore[0]!=totalScore[2]) {
			if(score3[0]>score3[1]) {
				return 1;
			} else if(score3[1]>score3[0]) {
				return 2;
			} else {
				if(score2[0]>score2[1]) {
					return 1;
				} else if(score2[1]>score2[0]) {
					return 2;
				}
			}
		} else if(totalScore[0]==totalScore[2]&&totalScore[0]!=totalScore[1]) {
			if(score3[0]>score3[2]) {
				return 1;
			} else if(score3[2]>score3[0]) {
				return 3;
			} else {
				if(score2[0]>score2[2]) {
					return 1;
				} else if(score2[2]>score2[0]) {
					return 3;
				}
			}
		} else if(totalScore[1]==totalScore[2]&&totalScore[0]!=totalScore[1]) {
			if(score3[1]>score3[2]) {
				return 2;
			} else if(score3[2]>score3[1]) {
				return 3;
			} else {
				if(score2[1]>score2[2]) {
					return 2;
				} else if(score2[2]>score2[1]) {
					return 3;
				}
			}
		} else {
			if(score3[0]>score3[1]&&score3[0]>score3[2]) {
				return 1;
			} else if(score3[1]>score3[0]&&score3[1]>score3[2]) {
				return 2;
			} else if(score3[2]>score3[0]&&score3[2]>score3[1]) {
				return 3;
			} else {
				if(score2[0]>score2[1]&&score2[0]>score2[2]) {
					return 1;
				} else if(score2[1]>score2[0]&&score2[1]>score2[2]) {
					return 2;
				} else if(score2[2]>score2[0]&&score2[2]>score2[1]) {
					return 3;
				}
			}
		}
		return 0;
	} // end of chkWinner()
} // end of Main class