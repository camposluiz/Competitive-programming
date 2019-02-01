#include <bits/stdc++.h>

using namespace std;

int main() {

	cout << fixed << setprecision(2);	

	int N, M, P, i, j;
	string nome;
	double preco, soma_compra;
	int quantidade;

	cin >> N;

	for (i = 0; i < N; i++) {    // Idas à feira
	
		cin >> M;
		map< string, double > frutas;
		for (j = 0; j < M; j++) {  // Cadastro de frutas

			cin >> nome >> preco;
			frutas[nome] = preco;
		}

		cin >> P;
		soma_compra = 0;  // O preço das compras ainda é zero
		quantidade = 0;  // Nenhum produto comprado
		for (j = 0; j < P; j++) {    // Realização das compras
			
			cin >> nome >> quantidade;
			soma_compra += frutas[nome] * quantidade;
		}	
		
		cout << "R$ " << soma_compra << endl;

	}


	return 0;
}