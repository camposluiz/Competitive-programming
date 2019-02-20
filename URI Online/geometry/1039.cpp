#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int R1, X1, Y1, R2, X2, Y2;

	while (cin >> R1 >> X1 >> Y1 >> R2 >> X2 >> Y2) {
	
		double distancia = sqrt( pow(X2 - X1, 2) + pow(Y2 - Y1, 2));	

		if (distancia <= R1 - R2) cout << "RICO" << endl;
		else cout << "MORTO" << endl;
	
	}           	


	return 0;
}
