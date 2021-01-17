#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;  // use o tamanho m�ximo dado na quest�o

vector<int> g[maxn];
bool vis[maxn];
int dis[maxn];  // vetor de dist�ncia para o n�s
deque<int> deq;

/* Achando a menor dist�ncia de um n� para todos os outros.
   Suponha que os pesos das arestas sejam iguais a 1 */
void bfs(int v) {
    dis[v] = true;
    deq.push_back(v);
    while (!deq.empty()) {
        int s = deq.front(); deq.pop_front();
        for (auto u : g[s]) {
            if (vis[u]) { continue; }
            vis[u] = true;
            dis[u] = dis[s] + 1;
            deq.push_back(u);
        }
    }
}

int main() {
    /*
      liga��o entre os v�rtices, g[n].push_back(m)
      (o vertice n tem uma aresta com o vertice m)
    */
    g[1].push_back(2); g[1].push_back(4); g[2].push_back(1); g[2].push_back(5);
    g[2].push_back(3); g[3].push_back(2); g[3].push_back(6); g[4].push_back(1);
    g[5].push_back(2); g[5].push_back(6); g[6].push_back(5); g[6].push_back(3);

    bfs(1);
    printf("%d\n", dis[6]);  // menor dist�ncia do vertice 1 para o vertice 6

    // lembre sempre de reniciar caso existam v�rios casos de testes
    memset(vis, false, sizeof dis);
    memset(dis, 0, sizeof dis);
    for (int i = 1; i <= maxn; i++) g[i].clear();

    return 0;
}