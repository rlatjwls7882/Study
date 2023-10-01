import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 자연수 a에 대하여, n ≡ a-1 (mod a)인 정수 n 출력
        bw.write("-1");
        bw.close();
    } // end of main
} // end of Main class