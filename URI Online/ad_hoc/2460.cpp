/* Forma de verificar o tempo do código feita pelo: aid, no codeforces
http://codeforces.com/submissions/aid */

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

int main() {
#ifdef DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif  	
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
		
	int N, M, ix; 
	string id;
	deque<string> fila; deque<string>::iterator it1;
	map<string, int> aux; map<string, int>::iterator it2;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> id;
		fila.push_back(id);
		aux[id] = i;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> id;
		it2 = aux.find(id);
		if (it2 != aux.end()) {
			ix = it2->second;
			fila[ix] = "-1";			
		}
	}
	
	int len = fila.size(); string output = "";
	for (int i = 0; i < len; i++) {
		if (fila[i] != "-1") {
			output += fila[i] + " ";
		}
	}
	output.pop_back();
	cout << output << endl;


#ifdef DEBUG
	eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif

	return 0;
}