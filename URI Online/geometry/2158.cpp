#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	
	ll FP, FH, A, V;
	
	int i = 1;
	while (cin >> FP >> FH) {

		A = ( (5 * FP) + (6 * FH) ) / 2; 
		V = (A + 2) - (FP + FH);

		cout << "Molecula #" << i << ".:." << endl;
		cout << "Possui " << V << " atomos e " << A << " ligacoes" << endl;
		cout << endl;
		i++;	
	} 


	return 0;
}
