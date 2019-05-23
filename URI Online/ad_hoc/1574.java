/* Forma eficiente de ler os dados em java:http://codeforces.com/submissions/Petr */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
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
		
		int T;
		int n;
		int p;
		int sameValor;
		String instrucao;
		Map<Integer, String> baseDados;
		
		public void solve(int testNumber, InputReader in, PrintWriter cout) {
			
			T = in.nextInt();
			for (int i = 0; i < T; i++) {
				
				n = in.nextInt();
				p = 0;  
				baseDados = new HashMap<>();
				
				for (int j = 0; j < n; j++) {
					instrucao = in.nextLine();
					
					if (instrucao.equals("LEFT")) {
						p--;
						baseDados.put(j+1, "LEFT");
					}
					
					else if (instrucao.equals("RIGHT")) {
						p++;
						baseDados.put(j+1, "RIGHT");
					}
					
					else {
						
						sameValor = Integer.parseInt(instrucao.replace("SAME AS ", ""));
						
						if (baseDados.get(sameValor).equals("RIGHT")) {
							p++;
							baseDados.put(j+1, "RIGHT");
						}
						else {
							p--;
							baseDados.put(j+1, "LEFT");
						}
						
					}
					
				}
				
				cout.printf("%d\n", p);
				
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
		
		public String nextLine() {
			String str = "";
			try {
				str = bufferedReader.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
			
	}
	
}