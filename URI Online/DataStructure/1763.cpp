#include <bits/stdc++.h>

using namespace std;

int main() {
	
	map< string, string > frase;   
	frase["brasil"] = "Feliz Natal!";
	frase["alemanha"] = "Frohliche Weihnachten!";
	frase["austria"] = "Frohe Weihnacht!";
	frase["coreia"] = "Chuk Sung Tan!";
	frase["espanha"] = "Feliz Navidad!";
	frase["grecia"] = "Kala Christougena!";
	frase["estados-unidos"] = "Merry Christmas!";
	frase["inglaterra"] = "Merry Christmas!";
	frase["australia"] = "Merry Christmas!";
	frase["portugal"] = "Feliz Natal!";
	frase["suecia"] = "God Jul!";
	frase["turquia"] = "Mutlu Noeller";
	frase["argentina"] = "Feliz Navidad!";
	frase["chile"] = "Feliz Navidad!";
	frase["mexico"] = "Feliz Navidad!";
	frase["antardida"] = "Merry Christmas!";
	frase["canada"] = "Merry Christmas!";
	frase["irlanda"] = "Nollaig Shona Dhuit!";
	frase["belgica"] = "Zalig Kerstfeest!";
	frase["italia"] = "Buon Natale!";
	frase["libia"] = "Buon Natale!";
	frase["siria"] = "Milad Mubarak!";
	frase["marrocos"] = "Milad Mubarak!";
	frase["japao"] = "Merii Kurisumasu!";

	string pais;
	while (cin >> pais) {

		if (frase.find(pais) != frase.end())
			cout << frase[pais] << endl;
		else
			cout << "--- NOT FOUND ---" << endl;
                  	
	}

	return 0;
}