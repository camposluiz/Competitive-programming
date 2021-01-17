/* Forma eficiente de ler os dados em java: http://codeforces.com/submissions/Petr */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter cout = new PrintWriter(outputStream);
		Task task = new Task();
		task.solve(1, in, cout);
		cout.close();
	}
	
	static class Task {
		
		int h;
		int maior;
		
		public void solve(int testNumber, InputReader in, PrintWriter cout) {
			
			while (true) {
				h = in.nextInt();
				
				if (h == 0) break;
				
				maior = h;
				while (h != 1) {
					
					if (h % 2 == 0) h /= 2;
					else h = 3 * h + 1;
					
					if (h > maior) maior = h;	
				}	
				cout.printf("%d\n", maior);
			}
			
			
		}
		
	}
	
	static class InputReader {
		public BufferedReader bufferedReader;
		public StringTokenizer stringTokenizer;
		
		public InputReader(InputStream inputStream) {
			bufferedReader = new BufferedReader(new InputStreamReader(inputStream), 32678);
			stringTokenizer = null;
		}
		
		public String next() {
			try {
				stringTokenizer = new StringTokenizer(bufferedReader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return stringTokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}	
	}	
}