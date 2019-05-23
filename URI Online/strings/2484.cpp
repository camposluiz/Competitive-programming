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
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

	int len, k, r;	
	string str;
	while (cin >> str) {
		len = str.size(); k = 1; r = len;	

		for (int i = 0; i < len; i++) {
			cout << setw(k) << str[0]; if (i < len - 1) cout << " ";
			for (int j = 1; j < r; j++) {
				cout << str[j]; if (j < r - 1) cout << " ";
			}
			r--; k++;
			cout << "\n";
		}

		cout << "\n";
	}

#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif

  	return 0;
}