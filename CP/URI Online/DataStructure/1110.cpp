#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        Node *next;  // proximo elemento do Nó
        int content;  // Conteúdo do Nó
    public:
        Node(int);  // Assinatura do construtor
};

Node::Node(int value) {
    this->content = value;
    this->next = nullptr;
}

class struct_cards {
    private:
        Node* head;  
        Node* tail;  
        int length;   
    public:
        struct_cards();  
        void push_back(int); 
        int pop();
    	void move();
    	int peek();
};

int struct_cards::peek() {
    return this->tail->content;
}

struct_cards::struct_cards() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

void struct_cards::move() {
    
    Node *current = this->head;

    this->head = current->next;
    this->tail->next = current;
    this->tail = current;
}

void struct_cards::push_back(int value) {
    Node *new_node = new Node(value);
    
    if (length == 0) {
        head = new_node;
        tail = new_node;
    }

    else{
    	tail->next = new_node;
        tail = new_node;
    }
    
    length++;
}

int struct_cards::pop() {
    
    Node *current = this->head;
    int valor = current->content;

    this->head = current->next;
    delete(current);    
    length--;
    
    return valor;
}

int main(int argc, char const *argv[])
{
    int number_cards, len;
    
    while(true) {

	cin >> number_cards;
	if (number_cards == 0) break;
	
	struct_cards cartas;
	for (int i = 1; i <= number_cards; i++) cartas.push_back(i);

	len = number_cards;
	cout << "Discarded cards:";
	while (number_cards >= 2) {
	    
	    cout << " " << cartas.pop();
	    if (number_cards > 2) cout << ",";
	    number_cards--;
	    cartas.move();
	}

	cout << "\nRemaining card: " << cartas.peek() << endl;
    
    }
    
    return 0;
}