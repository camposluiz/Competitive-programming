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
		No* buscar(int);
		void in_fixa();
		void pos_fixa();
		void pre_fixa();
		void apagar(int);
		void recortar(No*, No*);
		No* sucessor(int);
		No* minimo(No*);
		No* antecessor(int);
		No* maximo(No*);
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


No* Bst::maximo(No* atual) {
    if (atual == nullptr) {
    	atual = this->raiz;
    }

	while (atual->direita != nullptr) {
		atual = atual->direita;
	}
	
	return atual;

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


No* Bst::buscar(int value) {

    No *atual = this->raiz;

    while (atual != nullptr && atual->chave != value) {
    	
    	if (atual->chave > value)
    		atual = atual->esquerda;
    	else
    		atual = atual->direita;		
    }
	
	return atual;		

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


No* Bst::antecessor(int value) {

	No *atual = this->buscar(value);

	if (atual == nullptr) {
		return atual;
	}
	
	if (atual->esquerda != nullptr) {
		return this->maximo(atual->esquerda);
	}

	No *pai_atual = atual->pai;
	while (pai_atual != nullptr && atual == pai_atual->esquerda) {
		atual = pai_atual;
		pai_atual = pai_atual->pai;
	}

	return pai_atual;		

}


void Bst::apagar(int value) {

	No *sera_removido = this->buscar(value);

	if (sera_removido == nullptr) {
		return;
	}

	if (sera_removido->esquerda == nullptr) {
		this->recortar(sera_removido, sera_removido->direita);
	}
	else if (sera_removido->direita == nullptr) {
		this->recortar(sera_removido, sera_removido->esquerda);
	}	
	else {
	
		No *antecessor = this->antecessor(sera_removido->chave);
	
		if (antecessor->pai != sera_removido) {
			this->recortar(antecessor, antecessor->esquerda);
			antecessor->esquerda = sera_removido->esquerda;
			antecessor->esquerda->pai = antecessor;
		}

		this->recortar(sera_removido, antecessor);
	    antecessor->direita = sera_removido->direita;
	    antecessor->direita->pai = antecessor;


	}

	this->len -= 1;

}

void Bst::recortar(No* sera_removido, No* sera_recortado) {

	if (sera_removido->pai == nullptr) {
		this->raiz = sera_recortado;
	}
	else if (sera_removido == sera_removido->pai->esquerda) {
		sera_removido->pai->esquerda = sera_recortado;
	}
	else {
		sera_removido->pai->direita = sera_recortado;
	}

	if (sera_recortado != nullptr) {
		sera_recortado->pai = sera_removido->pai;	
	}
}


int main() {
	
	Bst bst;
	string operacao, temp;
	bool contem;
	int c;
	No *no;
	
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
			
			temp = operacao;
			temp.erase(0, 2);

			
			c = stoi(temp);
			
		    if (operacao[0] == 'I') {
		    	bst.inserir(int(c));
			}	
			
			else if (operacao[0] == 'R') {
				bst.apagar(c);
			}

			else {
				
				no = bst.buscar(c);

				if (no == nullptr)
					cout << c << " nao existe" << endl;
				else
					cout << c << " existe" << endl;						
			}
		}           
	}
	return 0;
}