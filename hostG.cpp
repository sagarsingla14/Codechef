#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll spf[100010] = {0};
ll n;

void sieve() {
    for(ll i = 0 ; i <= 100010 ; i++) {
        spf[i] = i;
    }

    for(ll i = 2 ; i * i <= 100010 ; i++) {
        if(spf[i] == i) {
            for(ll j = i * i ; j <= 100010 ; j += i) {
                spf[j] = i;
            }
        }
    }
}

int main() {
    sieve();
    cin >> n;

    set <ll> s;
    vector <ll> ans;

    for(ll i = 2 ; i <= n + 1 ; i++) {
        if(spf[i] == i) {
            ans.push_back(1);
            s.insert(1);
        }
        else{
            ans.push_back(2);
            s.insert(2);
        }
    }

    cout << s.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
