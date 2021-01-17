#include <bits/stdc++.h>

using namespace std;

long long int exponenciacao_rapida(long long int base, long long int e);

const int M = 2147483647;

long long int exponenciacao_rapida(long long int base, long long int e) {
	
	long long int resul = 1;
    
    	while (e > 0) {
    	
    		if (e % 2 == 1)   // Representação binária possui 1 no ultimo bit
			resul = (resul * base) % M;

		base = (base * base) % M;
		e /= 2;			   
    	}

	return resul;

}


int main() {
	
	int R;

	cin >> R;

	long long a = exponenciacao_rapida(3, R);
	cout << a << endl;
	
	return 0;
}
