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

class BST {

	public:
		No *raiz;
		int len;
	public:
		BST();
		void insert(int);
		void in_order();
		void pre_order();
		void pos_order();
};

No::No(int value) {
	
	this->pai = nullptr;
	this->direita = nullptr;
	this->esquerda = nullptr;
	this->chave = value;
}

BST::BST(){
	this->raiz = nullptr;
	this->len = 0;
}


void BST::insert(int value) {

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

void BST::in_order() {

	stack<No *> pilha;
	No *atual = this->raiz;
	
	int i = 0;
	while (atual != nullptr || pilha.empty() == false) {
	
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

void BST::pre_order() {

	stack<No *> pilha;
	No *atual = this->raiz;
	pilha.push(atual);

	int i = 0;

	while (!pilha.empty()){

		atual = pilha.top();
		pilha.pop();	
		
		cout << atual->chave;
		if (i < this->len - 1)
			cout << " ";
	   	i++;
		
		if (atual->direita != nullptr)
			pilha.push(atual->direita);
		if (atual->esquerda != nullptr)
			pilha.push(atual->esquerda);			
	}

}

void BST::pos_order() {

	No *atual = this->raiz;
	stack<No *> pilha;
	
	int i = 0;

	while (atual != nullptr || pilha.empty() == false) {

		if (atual != nullptr) {
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
				i++;	

				while (!pilha.empty() && temp == pilha.top()->direita) {
					temp = pilha.top();
					pilha.pop();

					cout << temp->chave;
					if (i < this->len - 1)
						cout << " ";
					i++;
								
				}
			}

			else {
				atual = temp;
			}		
		}
	}
}

int main() {
	
	int C, N, num, i, j;
	
	cin >> C;

	for (i = 0; i < C; i++) {   // Casos de teste

		BST bin;

		cin >> N;
		for (j = 0; j < N; j++) {  // Lendo e inserindo os elementos na árvore
			cin >> num;			
			bin.insert(num);						
		}
	
	    cout << "Case " << i+1 << ":" << endl;
		
		cout << "Pre.: ";
		bin.pre_order(); cout << endl;	

		cout << "In..: ";
		bin.in_order(); cout << endl;

		cout << "Post: ";
		bin.pos_order(); cout << endl;
		                              	
		cout << endl;

	}


	return 0;
}