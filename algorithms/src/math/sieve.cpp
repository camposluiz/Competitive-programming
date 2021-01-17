#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;

/*
   Primeiro setamos que 0 e 1 não são primos.
   Então, setamos que 2 é primo, e riscamos todos os seus múltiplos: 2 X 2 = 4, 6, 8, 10...N
   Depois, setamos que 3 é primo, e riscamos todos os seus múltiplos: 3 x 3 = 9, 12, 15...N
   E seguimos fazendo isso... No final, todos os números que ficarem, são primos.
*/

void sieve(long long upperbound) {  // cria uma lista de primos em [0..upperbound]
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // riscando todos os múltiplos de i, começando de i * i
    for (long long j = i * i; j <= _sieve_size; j += 1) {
      bs[j] = 0; 
    }
    primes.push_back((int)i);
  }
}

bool isPrime(long long n) {
  if (n <= _sieve_size) {
    return bs[n];
  }
  for (int i = 0; i < (int)primes.size(); i++) {
    if (n % primes[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
	      
  sieve(10000000);
  long long a = 2147483647;
  long long b = 136117223861LL;
  cout << a << " eh primo: " << isPrime(a) << endl;
  printf("%d\n", isPrime(136117223861LL));

}
