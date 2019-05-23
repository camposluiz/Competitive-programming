import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		Task1244 solver = new Task1244();
		
		int numbers = Integer.parseInt(b.readLine());
		
		solver.solve(numbers, b);
		
	}
	
	static class Task1244 {
		
		String linha;
		int t;
		int k;
		
		public void solve(int testNumbers, BufferedReader in) throws IOException {
					
			for (int i = 0; i < testNumbers; i++) {
				
				linha = in.readLine();
				String[] words = new String[2500];
				
				words = linha.split("\\s+");
				Arrays.sort(words, (x, y) -> Integer.compare(y.length(), x.length()));
				
				int t = words.length;
				for (int k = 0; k < t; k++) {
					
					if (k < t - 1)
						System.out.printf("%s ", words[k]);
					else
						System.out.printf("%s", words[k]);

				}
				
				System.out.println();
				
			}
			
		}
		
	}
	
	
}
