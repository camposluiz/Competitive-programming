#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string assassino, assassinado;
	map< string, int > hall;
	
	while (cin >> assassino >> assassinado){

		// Se o assassino ou o assassinado ainda não existem na árvore, criamos eles
		if (hall.find(assassino) == hall.end())
			hall[assassino] = 0;
		if (hall.find(assassinado) == hall.end())
			hall[assassinado] = 0;
	    
		hall[assassino] += 1;  // Matou
        hall[assassinado] = -100000000000;   // Foi morto
    
	}	

	// Impressão do Hall
	cout << "HALL OF MURDERERS" << endl;
	for (auto const & pair : hall) {
		
		if (pair.second >= 1)
			cout << pair.first << " " << pair.second << endl;
	}


	return 0;
}