#include <iostream>
#include <stack>
#include <string>

using namespace std;

void minerar_expressao(string expressao);
void contar_diamantes(stack<string> expressao_minerada);


void contar_diamantes(stack<string> expressao_minerada) {

    int abriu = 0, fechou = 0, quantidade = 0;
    
    while (!expressao_minerada.empty()){
    
        if (expressao_minerada.top() == ">")
            fechou++;
        else if (expressao_minerada.top() == "<" && fechou > 0) {
            fechou--;
            quantidade++;
        }

        expressao_minerada.pop();
    }

    cout << quantidade << endl;

}

void minerar_expressao(string expressao) {

    stack<string> expressao_minerada;
    string aux;
    for (int i = 0; i < expressao.size(); i++) {

        if (expressao[i] == '<' || expressao[i] == '>') {
            aux = expressao[i];
            expressao_minerada.push(aux);
        }
    }

    contar_diamantes(expressao_minerada);
}


int main() {

    int N;
    string expressao;

    cin >> N;
    
    cin >> ws;
    for (int i = 0; i < N; i++) {
        getline(cin, expressao);
        minerar_expressao(expressao);
    }

    return 0;
}
