#include <iostream>
#include <vector>
#include <string>

using namespace std;

void retirar_parenteses(string expressao);
void verificar_parenteses(vector<string> parenteses);

void verificar_parenteses(vector<string> parenteses) {

    int abriu = 0, fechou = 0;
    int tamanho = parenteses.size();
    bool muito_grande = true;

    if (tamanho % 2 != 0) 
        cout << "incorrect" << endl;
    else {

        for (int i = 0; i < tamanho; i++) {
            
            if (parenteses[0] == ")" || parenteses[tamanho-1] == "("){
                cout << "incorrect" << endl;
                muito_grande = false;
                break;
            }

            else if (parenteses[i] == "(") {
                abriu++;
                fechou--;
            }
            else if (parenteses[i] == ")" && fechou < 0) {
                abriu--;
                fechou++;
            }
            else {
                cout << "incorrect" << endl;
                muito_grande = false;
                break;
            }
        }

        if (muito_grande) {
            if (abriu == 0 && fechou == 0)
                cout << "correct" << endl;
            else
                cout << "incorrect" << endl;
        }
    }
}

void retirar_parenteses(string expressao) {

    vector<string> parenteses;
    string aux;

    for (int i = 0; i < expressao.size(); i++) {
        if (expressao[i] == '(' || expressao[i] == ')') {
            aux = expressao[i];
            parenteses.push_back(aux);
        }
    }

    verificar_parenteses(parenteses);

}

int main() {

    string expressao;
    cin >> ws;
    while (getline(cin, expressao)) {

        retirar_parenteses(expressao);

    }

    return 0;
}