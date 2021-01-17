#include <bits/stdc++.h>

using namespace std;


int main() {

	
	int N, Q, x;
	int case_ = 1;
		
	while (true) {

		vector<int> marbles;
		vector<int>::iterator it;
		
		cin >> N >> Q;

		if (N == 0 && Q == 0) break;

        for (int i = 0; i < N; i++) {  // Colocandos os marbles
        	cin >> x;
        	marbles.push_back(x);
        }            	

		sort(marbles.begin(), marbles.end());  // Colocando os marbles na ordem	
		
		cout << "CASE# " << case_ << ":" << endl;
		case_++;

		for (int i = 0; i < Q; i++) {  // Tentativas
		
			cin >> x;
			it = find(marbles.begin(), marbles.end(), x);

			if (it != marbles.end()) cout << x << " found at " << distance(marbles.begin(), it) + 1 << endl;
			else cout << x << " not found" << endl;
		
		}
			
	
	}


	return 0;
}