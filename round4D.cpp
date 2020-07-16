#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool prime(ll n) {
    ll prime = 1;
    for(ll i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            prime = 0;
            break;
        }
    }
    if(prime) {
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ll n;
    cin >> n;

    ll start = n;
    while(!prime(start)) {
         start ++;
    }

    vector <pair <ll , ll> > v;

    for(ll i = 0 ; i < n - 1 ; i++) {
        v.push_back({i + 1 , i + 2});
    }
    v.push_back({n , 1});
    for(ll i = 0 ; i < start - n ; i++) {
        v.push_back({i + 1 , i + 1 + n / 2});
    }

    cout << v.size() << endl;
    for(auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
