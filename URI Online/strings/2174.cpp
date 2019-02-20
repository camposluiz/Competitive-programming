#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int N;
	int capturou = 0;
	string nome;
	map < string , bool > pokemons;

	cin >> N;	
	
	for (int i = 0; i < N; i++) {
		cin >> nome;
		
		if (pokemons.find(nome) == pokemons.end()){  // O pokemon ainda não existia
			pokemons[nome] = true;
			capturou += 1;
		}						

	}

	cout << "Falta(m) " << (151 - capturou) << " pomekon(s)." << endl;


	return 0;
}
