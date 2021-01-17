#include <bits/stdc++.h>

using namespace std;


class No {

	public:
		No *pai;
		No *direita;
		No *esquerda;
		char chave;
	public:
		No(char);
};

class Bst {
	
	public:
		No *raiz;
		int len;
	public:
		Bst();
		void inserir(char);
		bool buscar(char);
		void in_fixa();
		void pos_fixa();
		void pre_fixa();
};

No::No(char value) {

	this->pai = nullptr;
	this->direita = nullptr;
	this->esquerda = nullptr;
	this->chave = value;
}

Bst::Bst() {
	this->raiz = nullptr;
	this->len = 0;
}


void Bst::inserir(char value) {
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

void Bst::in_fixa() {
    stack<No*> pilha;
    No *atual = this->raiz;

    int i = 0;
    while(atual != nullptr || pilha.empty() == false) {
    	
    	while (atual != nullptr) {
    		
    		pilha.push(atual);
    		atual = atual->esquerda;
    	
    	}

    	atual = pilha.top();
    	pilha.pop();

    	cout << atual->chave;
    	if (i < this->len - 1)
    		cout << " ";
    	i += 1;

    	atual = atual->direita;

    }
	
}


bool Bst::buscar(char value) {

	if (this->len == 0)
		return false;

    No *atual = this->raiz;

    while (atual != nullptr && atual->chave != value) {
    	
    	if (atual->chave > value)
    		atual = atual->esquerda;
    	else
    		atual = atual->direita;		
    }

    if (atual == nullptr)
    	return false;

	return (atual->chave == value);		

}

void Bst::pre_fixa() {

	stack<No*> pilha;
	No *atual = this->raiz;
	pilha.push(atual);

	int i = 0;
	while(!pilha.empty()) {
		atual = pilha.top();
		pilha.pop();

		cout << atual->chave;

		if (i < this->len - 1)
			cout << " ";
		i += 1;

		if (atual->direita != nullptr)
			pilha.push(atual->direita);
		if (atual->esquerda != nullptr)
			pilha.push(atual->esquerda);
	
	}


}

void Bst::pos_fixa() {

	No *atual = this->raiz;
	stack<No*> pilha;

	int i = 0;
	while (atual != nullptr || pilha.empty() == false) {
	
		if (atual != nullptr){
			pilha.push(atual);
			atual = atual->esquerda;
		}

		else {
		
			No *temp = pilha.top()->direita;

			if (temp == nullptr) {
			
				temp = pilha.top();
				pilha.pop();

				cout << temp->chave;
				if (i < this->len - 1)
					cout << " ";
				i += 1;

				while(!pilha.empty() && temp == pilha.top()->direita) {
				
					temp = pilha.top();
					pilha.pop();

					cout << temp->chave;
					if (i < this->len - 1)
						cout << " ";
					i += 1;
				
				}
			}
			else {
				atual = temp;
			}
		}
	}
}


int main() {
	
	Bst bst;
	string operacao;
	bool contem;
	char c;
	
	while (getline(cin, operacao)) {
		
		if (operacao == "INFIXA") {
			bst.in_fixa(); cout << endl;			
		}
		else if (operacao == "PREFIXA") {
			bst.pre_fixa(); cout << endl;		
		}
		else if (operacao == "POSFIXA") {
			bst.pos_fixa(); cout << endl;	
		}

		else {

			c = operacao[2];	

		    if (operacao[0] == 'I') {
		    	bst.inserir(c);
			}	
			else {
				if (bst.buscar(c))
					cout << c << " existe" << endl;
				else 
					cout << c << " nao existe" << endl;
				
			}

		}           
	
	}
	

	return 0;
}