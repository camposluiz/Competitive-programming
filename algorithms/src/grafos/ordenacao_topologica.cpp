#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;  // use o tamanho dado na quest�o

vector<int> g[maxn];
bool vis[maxn];
deque<int> top;  // pilha com vertices ordenados

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (auto w : g[v]) {
        dfs(w);
    }
    top.push_front(v);
}

int main() {
    
    g[1].push_back(2); g[2].push_back(3); g[3].push_back(6); g[4].push_back(1);
    g[4].push_back(5); g[5].push_back(2); g[5].push_back(3);

    for (int i = 1; i <= 6; i++)
        dfs(i);
    
    for (auto e : top) {
        printf("%d\n", e);
    }

    return 0;
}