#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;  // use o tamanho dado na quest�o
vector<int> g[maxn];
bool vis[maxn];  // vetor de visitados para os n�s

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (auto u : g[v]) {
        dfs(u);
    }
}

int main() {
    g[1].push_back(4); g[1].push_back(2); g[2].push_back(5);
    g[2].push_back(3); g[5].push_back(3);

    dfs(1);

    for (int i = 1; i <= 5; i++)
        printf("%d\n", vis[i]);  // todos os v�rtices foram visitados
       

    /* Lembre sempre de reinicializar, caso acham v�rios casos de testes na quest�o */
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= maxn; i++) g[i].clear();

    return 0;
}