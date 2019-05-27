#include <bits/stdc++.h>

using namespace std;


class No {

	public:
		No *pai;
		No *direita;
		No *esquerda;
		int chave;
	public:
		No(int);
};

class Bst {
	
	public:
		No *raiz;
		int len;
	public:
		Bst();
		void inserir(int);
		void imprimirNivel();
};

No::No(int value) {

	this->pai = nullptr;
	this->direita = nullptr;
	this->esquerda = nullptr;
	this->chave = value;
}

Bst::Bst() {
	this->raiz = nullptr;
	this->len = 0;
}

void Bst::inserir(int value) {
	No *pai_atual = nullptr;
	No *atual = this->raiz;

	No *novo = new No(value);

	while (atual != nullptr) {
		pai_atual = atual;

		if (novo->chave < atual->chave) 
			atual = atual->esquerda;
		else
			atual = atual->direita;
	}

	novo->pai = pai_atual;
	this->len += 1;
	
	if (pai_atual == nullptr)
		this->raiz = novo;
	else if (novo->chave < pai_atual->chave)
		pai_atual->esquerda = novo;
	else
		pai_atual->direita = novo;		

}

void Bst::imprimirNivel() {

	No *atual;
	deque<No*> fila;
	fila.push_back(this->raiz);

	int i = 0;
    	while (!fila.empty()) {
    	
    		atual = fila.front();
    		fila.pop_front();

    		cout << atual->chave;
    		if (i < this->len - 1) cout << " "; i++;
                      
    		if (atual->esquerda != nullptr) fila.push_back(atual->esquerda);
    		if (atual->direita != nullptr) fila.push_back(atual->direita);
    	}
    	cout << endl;
}

int main() {

	int n, c, e;
	
	cin >> c;
	for (int i = 0; i < c; i++) {
		
		Bst bst;
		cin >> n;
		for (int j = 0; j < n; j++) {
		
			cin >> e;
			bst.inserir(e);
		}
		
		cout << "Case " << i+1 << ":"<< endl;
		bst.imprimirNivel();
		cout << endl;	 
	}

	return 0;
}
