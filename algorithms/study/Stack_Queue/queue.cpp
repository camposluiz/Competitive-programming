#include <iostream>
#include <ostream>

using namespace std;


template <class T>
class Node {
    public:
	Node<T>* next;
	T content;
    public:
	Node(const T&);
};

template <class T>
class my_queue {
    private:
	Node<T>* head;
	Node<T>* tail;
	int length;
    public:
	my_queue();  // Assinatura do construtor
	~my_queue();  // Desctructor
	enqueue(const T&);  // Insere no último nó da fila
	dequeue();  // Remove o primeiro nó da fila
	bool is_empty();
	template <class U> friend ostream& operator<<(ostream&, const my_queue<U>&);
};

template <class T>
Node<T>::Node(const T& value){
    this->next = nullptr;
    this->content = value;
}

template <class T>
my_queue<T>::my_queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <class T>
my_queue<T>::~my_queue(){
    
    Node<T>* current = this->head;
    while(current != nullptr){
	Node<T>* removed = current;
	current = current->next;
	delete(removed);
    }
    
    this->head = nullptr;
    this->length = 0;
}

template <class T>
bool my_queue<T>::is_empty() {
    return (this->length == 0);
}

template <class T>
my_queue<T>::enqueue(const T& value) {
    
    Node<T>* new_item = new Node<T>(value);

    if (this->length == 0) {
	this->head = new_item;
	this->tail = new_item;
    }
    else {
	this->tail->next = new_item;
	this->tail = new_item;
    }

    this->length += 1;
}

template <class T>
my_queue<T>::dequeue(){
    
    if (!is_empty()) {
	
	if (this->length == 1) {  // Se houver apenas um elemnto na fila
	    this->head = nullptr;
	    this->tail = nullptr;
	}

	else {
	    
	    Node<T>* current = this->head;
	    
	    this->head = current->next;
	    delete(current);	
	}
	
	this->length -= 1;
    }
    
}

template <class T>
ostream& operator<<(ostream &output, const my_queue<T> &queue) {
    Node<T>* current = queue.head;

    output << "[";
    for (int i = 0; i < queue.length; i++) {
	output << current->content;

	if (i < queue.length - 1) output << ", ";

	current = current->next;
    }

    output << "]";

    return output;
}

int main() {
    
    my_queue<int> teste;
    cout << teste << endl;
    
    teste.dequeue();
    teste.enqueue(1);
    teste.enqueue(2);
    cout << teste << endl;
    teste.dequeue();
    teste.dequeue();
    cout << teste << endl;
    return 0;
}
