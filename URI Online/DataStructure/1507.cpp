#include <iostream>
#include <algorithm>

using namespace std;

bool is_subpalavra(string v, string k);

bool is_subpalavra(string v, string k) {

    int aux1 = 0;  // Auxiliar para o k
    int aux2 = 0;  // Auxiliar para o v

    for (int i = 0; i < v.size(); i++) {

        if (k[aux1] == v[aux2]) {
            aux1 += 1;
            aux2 += 1;
        }
        else 
            aux2 += 1;
        
    }

    if (aux1 == k.size()) 
        return true;

    return false;
}


int main() {

    int N, Q, i, j;
    string S, R;

    cin >> N;

    for (i = 0; i < N; i++) {

        cin >> S;
        cin >> Q;
        for (j = 0; j < Q; j++) {

            cin >> R;
            if (is_subpalavra(S, R))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

        }

    }

    return 0;
}
