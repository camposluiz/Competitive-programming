#include <bits/stdc++.h>
using namespace std;


// Greatest Common Divisor of: a, b -> Z
// Complexity: O(log n)
int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
}

int main() {
  cout << gcd(30, 12) << "\n";

  return 0;
}