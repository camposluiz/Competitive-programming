#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool dentroRaio(ll x, ll y, ll raio) {
    return (x * x) + (y * y) <= raio;
}

int main() {
#ifdef uast
    freopen("input.txt", "r", stdin)
    freopen("output.txt", "w", stdout)
#endif

    ll c, t, x, y, valorRaio;

    scanf("%lld %lld", &c, &t);

    vector<ll> raios;
    for (int i = 0; i < c; i++) {
        scanf("%lld", &valorRaio);
        raios.push_back(valorRaio * valorRaio);
    }

    ll pontos = 0;
    vector<ll>::iterator low;
    for (int i = 0; i < t; i++) {
    
        scanf("%lld %lld", &x, &y);

        if (!dentroRaio(x, y, raios[c-1])) continue;
        if (dentroRaio(x, y, raios[0])) { pontos += c; continue; }
                                                                                
        low = lower_bound(raios.begin(), raios.end(), (x*x) + (y*y));
        pontos += c - (low - raios.begin());
    
    }
    
    printf("%lld\n", pontos);

    return 0;
}
