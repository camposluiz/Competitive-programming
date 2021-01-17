#include <iostream>
#include <ostream>

using namespace std;

template <class T>
class Node {
    public:  // Atributos 
        Node *next;
        T content;
    public:  // Métodos
        Node(const T&);  // Assinatura do construtor
};

template <class T>
class mystack {
    private:  // Atributos
        Node<T> *head;
        int length;
    public:
        mystack();  // Assinatura do construtor
        ~mystack();  // Destructor
        bool empty();  // Verifica se a pilha está vazia
        push(const T&);
        swap();
        pop();
        template <class U> friend ostream& operator<<(ostream&, const mystack<U>&);  // Função de print: cout << stack
};

template <class T>  // Construtor da classe Node
Node<T>::Node(const T& value) {
    this->next = nullptr;
    this->content = value;
}

template <class T>  // Contrutor da classe mystack
mystack<T>::mystack() {
    this->head = nullptr;
    this->length = 0;
}

template <class T>  // Destructor da classe mystack
mystack<T>::~mystack() {

    Node<T> *current = this->head;
    while (current != nullptr) {
        Node<T> *removed = current;
        current = current->next;
        delete(removed);
    }

    this->head = nullptr;
    this->length = 0;
}

template <class T>  // Retorna se a lista está vazia ou não
bool mystack<T>::empty() {
    return (length == 0);
}

template <class T>  // Insere um elemento na ínicio 
mystack<T>::push(const T& value) {

    Node<T> *new_item = new Node<T>(value);

    // Inserindo se a pilha estiver vazia
    if (length == 0) 
        this->head = new_item;

    // Pilha não vazia, inserindo no inicio
    else {
        new_item->next = this->head;
        this->head = new_item;
    }

    length++;  // Um elemento foi adicionado
}

template <class T>  // Remove o primeiro Nó da lista
mystack<T>::pop() {
    Node<T> *current = this->head;

    if (!empty()) {
        this->head = current->next;
        
        length--;  // Removendo um elemento
    }
    
}

template <class T>  // Para imprimir a pilha: cout << pilha
ostream& operator<<(ostream &output, const mystack<T> &stack) {
    Node<T> *current = stack.head;

    if (stack.length == 0)
        cout << "no items in the stack";
    
    else {
        output << "[";
        for (int i = 0; i < stack.length; i++) {
            output << current->content;

            if (i < stack.length - 1)
                output << ", ";
            
            current = current->next;
        }

        output << "]";

        return output;
    }
}

int main()
{
    mystack<string> teste2;
    teste2.push("I have no girlfriend");
    teste2.push("I mr lonely");
    teste2.pop();
    cout << teste2 << endl;

    mystack<double> teste1;
    teste1.push(2.0001);
    teste1.push(3.1415);
    cout << teste1 << endl;

    return 0;
}
