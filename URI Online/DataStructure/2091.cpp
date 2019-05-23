#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {                                                                                                         
#ifdef uast
	freopen("input.txt", "r", stdin)
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int N;
	
	ll numeroSozinho;
	ll num;	
	while (true) {

    	cin >> N;
    	if (N == 0) break;
    	
    	numeroSozinho = 0;
    	for (int i = 0; i < N; ++i) {
    		cin >> num;
    		numeroSozinho = numeroSozinho ^ num;
		}		

    	cout << numeroSozinho << endl; 

	}
		
	return 0;
}