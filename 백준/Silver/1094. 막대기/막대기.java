import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 막대는 2^0~2^6의 중복되지 않은 합으로 이루어짐(=이진수)
		String X = Integer.toBinaryString(Integer.valueOf(br.readLine()));
		
		// 이진수로 나타냈을 때 1의 개수(막대를 풀로 붙이는 횟수) 계산
		int sumOfOne=0;
		for(int i=0;i<X.length();i++)
			if(X.charAt(i)=='1')
				sumOfOne++;
		
		bw.write(sumOfOne+"");
		
		bw.close();
	} // end of main
} // end of Main class