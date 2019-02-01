#include <bits/stdc++.h>

using namespace std;

int main() {

	cout << fixed << setprecision(4);
	
	int N, i;
	string nome_arvore;
	double per, len;
	    
	cin >> N;
	cin >> ws;
	for (i = 0; i < N; i++) {  // Casos de contagem
		
		map< string, int > arvores;
		
		len = 0.0;
		while(getline(cin, nome_arvore)) {  // Contagem de árvores
			
			if (nome_arvore == "") break;
			
			len++;

			if (arvores.find(nome_arvore) != arvores.end())
				arvores[nome_arvore] += 1;  // Icrementando quantidade de árvore existente
			else
				arvores[nome_arvore] = 1;  // Criando nova árvore			
				
		}

		
		for (auto const & pair : arvores){
			per = (pair.second / len) * 100;
		
			cout << pair.first << " " << per << endl;
		
		}

		if (i < N-1)
			cout << "\n";
		                                             		
	}

	return 0;
}