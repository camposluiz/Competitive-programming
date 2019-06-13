#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

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

bool inLine(int a, int l, int c, int m[9][9]) {
	int b; int cont = 0;
	for (int j = 0; j < 9; j++) {
		if (c != j) {
			if (m[l][j] == a) { return true; }
		}
	}
	return false;
}

bool inColuna(int a, int c, int l, int m[9][9]) {
	int b;
	for (int i = 0; i < 9; i++) {
		if (l != i) {
			if (m[i][c] == a) { return true; } 
		}
	}
	return false;
}

bool verifyBlocos(int m[9][9]) {

	set<int> my_set; 
	int a;
	int i, j;
	int ci = 0; int di = 3;
	int cj = 0; int dj = 3;
	for (int k = 1; k <= 9; k++) {
		for (i = ci; i < di; i++) {
			for (j = cj; j < dj; j++) {
				a = m[i][j];
				if (!inLine(a, i, j, m)) {
					if (!inColuna(a, j, i, m)) {
						my_set.insert(a);		
					}
					else return false;
				}
				else return false;
			}
		}
		if (my_set.size() != 9) { return false; }
		my_set.clear();
		cj += 3; dj += 3;
		if (k % 3 == 0) { ci += 3; di += 3; cj = 0; dj = 3; j = cj; }
	}
	return true;
}

bool solve(int m[9][9]) {
}

int main() {
#ifdef DEBUG
  	assert(freopen("input.txt", "r", stdin));
  	assert(freopen("output.txt", "w", stdout));
#endif  	
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(1);
	
	int m[9][9]; 
	int n, a;
	cin >> n;
	for (int k = 0; k < n; k++) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> a;
				m[i][j] = a;
			}
		
		}

		cout << "Instancia " << k+1 << "\n";
		if (verifyBlocos(m)) { cout << "SIM" << "\n"; }
		else { cout << "NAO" << "\n"; }
		cout << "\n";

	}
	
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  	return 0;
}