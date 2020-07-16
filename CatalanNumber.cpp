#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll catalan[5001];
void catalanDP() {
	catalan[0] = catalan[1] = 1;
	for(ll i = 2; i <= 5000; i++) {
		catalan[i] = 0;
		for(ll j = 0 ; j < i ; j++) {
			catalan[i] += (catalan[j] % mod) * (catalan[i - j - 1] % mod);
			catalan[i] %= mod;
		}
	}
}

int main() {
	catalanDP();
	ll q;
	cin >> q;
	for(ll i = 0 ; i < q ; i++) {
		ll x;
		cin >> x;
		cout << catalan[x] % mod << endl;
	}
	return 0;
}
