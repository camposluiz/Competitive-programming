// exemplo do livro: Guide to Competitive Programming - Antti Laaksonen
#include <bits/stdc++.h>

int const maxn = 5 + 1;
int dist[maxn];  // array de distância para os vétices
std::vector<std::tuple<int, int, int>> edges;

/*
  Menor caminho do vértice x para todos outros do grafo. Complexidade O(n*m)
*/
void bellman_ford(int x) {
  memset(dist, 0x3f, sizeof(dist));
  dist[x] = 0;

  for (int i = 1; i <= maxn-1; i++) {
    for (auto e : edges) {
      int a, b, w;
      std::tie(a, b, w) = e;
      dist[b] = std::min(dist[b], dist[a] + w);
    }
  }
}

int main() {
  /* tupla da seguinte forma (aresta a, aresta b, peso aresta) */
  edges.emplace_back(1, 2, 2); edges.emplace_back(1, 4, 7); edges.emplace_back(1, 3, 3);
  edges.emplace_back(2, 4, 3); edges.emplace_back(2, 5, 5); edges.emplace_back(3, 4, -2); edges.emplace_back(4, 5, 2);

  int primeiro_vertice = 1;
  bellman_ford(primeiro_vertice);

  for (int i = 2; i <= maxn-1; i++) {
    printf("Menor distancia de %d para %d = %d\n", primeiro_vertice, i, dist[i]);
  }

  return 0;
}