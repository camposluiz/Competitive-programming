#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef URI
	freopen("input.txt", "r", stdin)
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
	string vogais, frase;
	int soma;

	while (cin >> vogais) {
		
		cin >> ws;	
		getline(cin, frase);	
		soma = 0;
	    
	    for (int i = 0; i < vogais.length(); i++) {
	        
		    for (int j = 0; j < frase.length(); j++) {
		    	if (frase[j] == vogais[i]) 
		    		soma += 1;    
		    }
	    }

		cout << soma << endl;     	
	
	}
	
	return 0;
}
