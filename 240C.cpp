#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k;

int main() {
	cin >> n >> k;
	ll cnt = (n / 2) - 1;
	if(n == 1 && !k) {
		cout << 1 << endl;
	}
	else if(n == 1 || k < cnt + 1) {
		cout << -1 << endl;
	}
	else{
		cout << (k - cnt) << " " << (k - cnt) * 2 << " ";
		for(ll i = 3 ; i <= n ; i++) {
			cout << (k - cnt) * 2 + i << " ";
		}
		cout << endl;
	}
	return 0;
}
