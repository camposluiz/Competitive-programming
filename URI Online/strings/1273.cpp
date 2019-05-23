#include <bits/stdc++.h>

using namespace std;

bool primeiraVez = true;

int main() {
	
	int n;
	string palavra;
	int setagem;
	

	while(true) {
	
		cin >> n;
		if (primeiraVez == false && n != 0)
			cout << endl;

		if(n == 0) break;

		if (primeiraVez) {
			primeiraVez = false;			
		}


		string listaPalavras[50];
		setagem = 0;
		for (int i = 0; i < n; i++) {
			cin >> palavra;

            if(palavra.size() > setagem) {
            	setagem = palavra.size();
            }

            listaPalavras[i] = palavra;	         
		}
		
		for (int i = 0; i < n; i++) {
			cout << setw(setagem);
			cout << listaPalavras[i] << endl;			
		}

	}


	return 0;
}