/* Forma de verificar o tempo do código feita pelo: aid, no codeforces
http://codeforces.com/submissions/aid */

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned llu;


#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
	return mrand() % x;
}

int main() {
#ifdef DEBUG
  	assert(freopen("input.txt", "r", stdin));
  	assert(freopen("output.txt", "w", stdout));
#endif  	
  	
	int N, M, x = 4;
	llu a, multLargest;

	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		
		scanf("%d", &M); llu matrix[M][M]; llu colunas[M];

		llu largestNumber = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%lld", &a); matrix[i][j] = a * a;
				
				if (i == 0) colunas[j] = matrix[i][j];
				
				else {
					if (matrix[i][j] > colunas[j]) {
						colunas[j] = matrix[i][j];
					}
				}

			}
		}
		
		string colunasStr[M], str;		
		for (int c = 0; c < M; c++) {
			multLargest = colunas[c];
			str = to_string(multLargest);
			colunasStr[c] = str;			 
		}

		printf("Quadrado da matriz #%d:\n", x); x++;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				cout << setw(colunasStr[j].size()) << matrix[i][j];
				if (j < M - 1) cout << " ";
			}
			printf("\n");
		}

		if (k < N - 1){
			printf("\n");
		}

	}

#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif

  	return 0;
}