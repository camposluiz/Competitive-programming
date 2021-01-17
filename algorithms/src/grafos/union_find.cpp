#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;  // Use o tamanho máximo de entrada dada na questão

int link[MAX];
int size[MAX];

/*
  Inicialmento cada elemento pertence a um conjunto diferente em que contém apenas ele mesmo
*/
void build() {
    for (int i = 1; i <= MAX; i++) {
        link[i] = i;
        size[i] = 1;
    }
}

/* 
  Retorna o representante do conjunta ao qual um dado elemento x pertence.
  Basta apenas seguir a cadeia de blocos 
*/
int find(int x) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

/*
  verifica se dois elementos a e b pertence ao mesmo conjunto
*/
bool same(int a, int b) {
    return find(a) == find(b);
}


/*
  Une dois conjuntos aos quais a e b pertencem.
  Conectando o conjunto de menor cardinalidade ao de maior
*/
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (size[a] < size[b]) 
        swap(a, b);
    
    if (a != b) 
        size[a] += size[b];
    
    link[b] = a;
}

int main() {
    
    build();
    unite(1, 2);
    unite(3, 2);
    printf("%d\n", same(1, 3));

    return 0;
}