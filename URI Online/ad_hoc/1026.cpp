#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef uast
	freopen("input.txt", "r", stdin)
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
	ll num1, num2;
	ll result;
	
	while (cin >> num1 >> num2) {
		result = num1 ^ num2; 			
		cout <<  result << endl;
	}
	
	return 0;
}