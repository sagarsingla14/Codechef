#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAXN 10000001


ll spf[MAXN];
vector <ll> factors;

void sieve() {
	spf[1] = 1;
	for (ll i=2; i<MAXN; i++)
		spf[i] = i;

	for (ll i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (ll i=3; i*i<MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (ll j=i*i; j<MAXN; j+=i)
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

void getFac(ll x) {
    map <ll , ll> mp;

    // cout << "x " << x << endl;

    while(x != 1) {
        mp[spf[x]] ++;
        x /= spf[x];
    }


    ll cur = 1;
    for(auto i : mp) {
        cur *= (i.second + 1);
    }

    factors.push_back(cur);
}

int main() {
    ll n;
    cin >> n;

    sieve();
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 0 ; i < n ; i++) {
        getFac(arr[i]);
    }

    sort(factors.begin() , factors.end());

    ll cnt = 1;
    for(ll i = factors.size() - 2 ; i >= 0 ; i--) {
        if(factors[i] == factors[factors.size() - 1]) {
            cnt ++;
        }
        else{
            break;
        }
    }

    cout << n - cnt << endl;

    return 0;
}
