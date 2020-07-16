#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[100001];

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();

        map <pair <ll , ll> , ll> mp;
        map <pair <ll , ll> , ll> edge;

        ll ans = 0;

        mp[{0 , 0}] = 0;
        ll h = 0 , v = 0;
        for(ll i = 0 ; i < n ; i++) {

            ll bh = h;
            ll bv = v;
            if(str[i] == 'N') {
                v --;
            }
            if(str[i] == 'S') {
                v ++;
            }
            if(str[i] == 'W') {
                h --;
            }
            if(str[i] == 'E') {
                h ++;
            }

            ll prevNode = mp[{bh , bv}];
            ll curNode = i + 1;
            if(mp.find({h , v}) != mp.end()) {
                curNode = mp[{h , v}];
            }
            if(edge.find({prevNode , curNode}) != edge.end()) {
                ans ++;
            }
            else{
                ans += 5;
                if(mp.find({h , v}) == mp.end()) {
                    mp[{h , v}] = i + 1;
                }
                edge[{curNode , prevNode}] = 1;
                edge[{prevNode , curNode}] = 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
