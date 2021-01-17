#include <bits/stdc++.h>
using namespace std;

/*
  Namespace with functions to number theory problems.
  Algorithms from Valiors blog: https://codeforces.com/blog/entry/61290
 */
namespace NumberTheory {

  struct GcdComponent {
    long long x, y, g;
  };

  inline long long normalize(long long x, long long mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
  }

  GcdComponent extendEuclids(long long a, long long b) {
    if (b == 0) {
      return {1, 0, a};
    }
    int x, y, g;
    GcdComponent component = extendEuclids(b, a % b);
    return {component.y, component.x - (a / b) * component.y, component.g};
  }

  long long Gcd(long long a, long long b) {
    if (b == 0) {
      return a;
    }
    return Gcd(b, a % b);
  }

  inline long long Lcm(long long a, long long b) {
    return a / Gcd(a, b) * b;
  }

  struct crt_type {
    bool solve;
    long long ans, lcm;
  };

  const int number_of_congruences = 3;
  crt_type chineseRemainder(long long (&a)[number_of_congruences+1], long long (&n)[number_of_congruences+1]) {
    long long ans, lcm;

    ans = a[1];
    lcm = n[1];
    for (int i = 2; i <= number_of_congruences; i++) {
      auto gcd_component = extendEuclids(lcm, n[i]);
      int x1 = (int) gcd_component.x;
      int g = (int) gcd_component.g;
      if ((a[i] - ans) % g != 0) {
        return {false, 0, 0 };
      }
      ans = normalize(ans + x1 * (a[i] - ans) / g % (n[i] / g) * lcm, lcm * n[i] / g);
      lcm = Lcm(lcm, n[i]);
    }
    return {  true, ans, lcm };
  }

}
