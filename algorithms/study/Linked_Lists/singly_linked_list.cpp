#include <iostream>
#include <ostream>
#include <typeinfo>
using namespace std;

// Criação da classe Node
template <class T>
class Node {
    public:
        Node *next;  // proximo elemento do Nó
        T content;  // Conteúdo do Nó
    public:
        Node(const T& value);  // Assinatura do construtor
};


// Inicializador da classe Node
template <class T>
Node<T>::Node(const T& value) {
    this->content = value;
    this->next = nullptr;
}

// Criação da classe Singlylist
template <class T>
class SinglyList {
    private:
        Node<T>* head;  // Aponta para o primeiro elemento da lista
        Node<T>* tail;  // Aponta para o último elemento da lista
        int length;  // A quantidade de elementos da lista 
    public:
        SinglyList();  // Assinatura do construtor
        void insert(int, const T&);  // Método para inserir elementos na lista: Recebe o índice e o elemento
        void erase(int);  // Remove um elemento pelo seu índice
        template <class U> friend ostream& operator<<(ostream&, const SinglyList<U>&);  // Para imprimir a lista assim: cout << lista << endl;
        bool isstring();  // Verificar se o conteúdo que está na lista é de strings
};

// Inicializador da classe SinglyList
template <class T>
SinglyList<T>::SinglyList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

// Insere um elemento na lista tomando como argumento um índice e o elemento
template <class T>
void SinglyList<T>::insert(int key, const T& value) {
    Node<T>* new_node = new Node<T>(value);
    
    // Inserindo em uma lista vazia
    if (length == 0) {
        head = new_node;
        tail = new_node;
    }

    // Inserindo no começo da lista
    else if (key <= 0) {
        new_node->next = head;
        head = new_node;
    }

    // Inserindo no fim da lista
    else if (key >= length) {
        tail->next = new_node;
        tail = new_node;
    }

    // Inserindo no meio da lista
    else {
    
        Node<T>* current = head;  // Começando do primeiro
        
        int i = 0;
        while(current != nullptr) {
            
            if (i == key - 1) {
                new_node->next = current->next;
                current->next = new_node;
                break;
            }

            current = current->next;
            i += 1;
        } 
    }

    length++;
}

// Método para remover um elemnto da lista através do seu índice
template <class T>
void SinglyList<T>::erase(int key) {

    // Permitindo trabalhar com índices negativos. Por exemplo: [-1] => último elemento
    if (key < 0)  
        key += length;

    // Caso o índice informado seja menor ou maior do que a quantide de elementos, lançamos uma exceção de índice
    if (key < 0 || key >= length)
        cerr << "IndexError: list assignment index out of range" << endl;  // Semelhante a saída do python quanto ocorre isso
    
    // Caso não tenha exceção iremos remover um elemento
    
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    int i = 0;
    while (i <= key) {

        if (current == nullptr) 
            break;

        // Removendo o primeiro elemento da lista
        if (key == i) {
            
            // Removendo o primeiro elemento da lista
            if (key == 0) {
                head = current->next;
                delete(current);
            }
            
            // Removendo o último elemento da lista
            else if (key == length - 1) {
                tail = previous;
                previous->next = nullptr;
                delete(current);
            }

            // Removendo um elemento no meio da lista
            else {
                previous->next = current->next;
                delete(current);
            }

        }

        previous = current;
        current = current->next;
        i += 1;
        
    }

    length--;  // Um elemento foi removido

}

// Retorna se o conteúdo da lista é do tipo string ou não
template <class T>
bool SinglyList<T>::isstring() {

    /* A função typeid retorna: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, sempre que o conteúdo for uma string */
    string id_string = "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE";
    
    if (length == 0)  // Se a lista estiver vazia, não sabemos o conteúdo da lista
        return false;
    else if (typeid(head->content).name() == id_string)  // Conteúdo da lista é uma string
        return true;

    return false;  // Não é uma lista de strings
}

// Para imprimir a lista assim: cout << lista << endl; Semelhante como é no python
template<class T>
ostream& operator<<(ostream &output, const SinglyList<T> &list) {
    Node<T>* current = list.head;
    
    SinglyList<T> aux;  // auxiliar para chamar o método isstring()
    aux = list;  
    
    bool is_string  = aux.isstring();

    output << "[";
    for (int i = 0; i < list.length; i++) {

        if (is_string)  // Como o valor é uma string colocamos aspas entre eles
            output << "'" << current->content << "'";
        else
            output << current->content;

        if (i < list.length - 1)
            output << ", ";
        
        current = current->next;
    }

    output << "]";
    delete(current);

    return output;
}

int main(int argc, char const *argv[])
{
    SinglyList<string> lista;
    
    lista.insert(0, "5");
    lista.insert(0, "9");

    cout << lista << endl;
    
    return 0;
}
