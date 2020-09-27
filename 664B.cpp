#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

int main() {
    ll n , m , x , y;
    cin >> n >> m >> x >> y;
    vector <pair <ll , ll>> v;

    cout << x << " " << y << endl;
    for(ll i = 1 ; i <= m ; i++) {
        if(i % 2) {
            for(ll j = 1 ; j <= n ; j++) {
                v.push_back({j , i});
            }
        }
        else {
            for(ll j = n ; j >= 1 ; j --) {
                v.push_back({j , i});
            }
        }
    }

    vector <pair <ll , ll>> b , a;
    for(ll i = 0 ; i < v.size() ; i++) {
        if(v[i].first == x && v[i].second == y) {
            break;
        }
        else{
            b.push_back(v[i]);
        }
    }
    for(ll i = v.size() - 1 ; i >= 0 ; i--) {
        if(v[i].first == x && v[i].second == y) {
            break;
        }
        else{
            a.push_back(v[i]);
        }
    }

    reverse(b.begin() , b.end());
    reverse(a.begin() , a.end());

    for(auto i : a) {
        cout << i.first << " " << i.second << endl;
    }
    for(auto i : b) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
