#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
}

// Lowest Common Multiple: Smaller integer that is divisible by both a and b
int lcm(int a, int b) {
    return a * b / (gcd(a, b));
}

int main() {
    cout << lcm(30, 12) << "\n";
    return 0;
}