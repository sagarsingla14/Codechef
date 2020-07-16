#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n , s;
vector <pair <ll , ll> > v;
ll mn , mx ;

void solve() {
    ll flag = 0;
    ll i = n - 1;
    while(mx > s) {
        while(v[i].second > v[i].first && mx > n) {
            mx --;
            v[i].second --;
            if(mx == s) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            break;
        }
        i --;
    }

    for(ll i = 0 ; i < n ; i++) {
        // cout << v[i].first << " " << v[i].second << endl;
        cout << v[i].second << " ";
    }
    cout << endl;

}
int main() {
    cin >> n >> s;
    mx = 0 , mn = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll a , b;
        cin >> a >> b;
        v.push_back(make_pair(a , b));
        mn += a, mx += b;
    }
    if(s >= mn && s <= mx) {
        // cout << mn << " " << mx << endl;
        cout << "YES" << endl;
        solve();
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
