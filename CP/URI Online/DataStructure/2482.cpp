#include <bits/stdc++.h>

using namespace std;


int main() {

	int N, M, i;
	string indioma, frase, nome;
	map< string, string > carta;

	cin >> N;
	cin >> ws;
	for (i = 0; i < N; i++) {  // Cadastro do "feliz natal"

		getline(cin, indioma);
		getline(cin, frase);
		carta[indioma] = frase;	
	}
	
	cin >> M;
	cin >> ws;
	for (i = 0; i < M; i++) {  // Escrita da carta
	
		getline(cin, nome);
		getline(cin, indioma);

		cout << nome << endl;
		cout << carta[indioma] << endl;
		cout << "\n";	
	}

	

	return 0;
}