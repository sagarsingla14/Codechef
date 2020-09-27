#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

map <ll , ll> mp;
set <ll> f, t;
ll n , x , q;
char s;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

void print(ll x) {
    if(x == 1) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main() {
    fast_io

    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++){
        cin >> arr[i];
        mp[arr[i]]++;
        if(mp[arr[i]] == 4){
            f.insert(arr[i]);
            t.erase(arr[i]);
        }
        else if(mp[arr[i]] == 2 ){
            t.insert(arr[i]);
        }
    }

    cin >> q;
    while(q--){
        cin >> s >> x;
        if(s == '+'){
            mp[x]++;
            if(mp[x] == 4){
                f.insert(x);
                t.erase(x);
            }
            else if(mp[x] == 2){
                t.insert(x);
            }
        }
        else if(s == '-') {
            if(mp[x] == 4){
                f.erase(x);
                t.insert(x);
            }
            else if(mp[x] == 2) {
                t.erase(x);
            }
            mp[x]--;
        }

        if(f.size() == 1) {
            ll front = mp[*f.begin()];
            if(front >= 6) {
                if(front >= 8) {
                    print(1);
                }
                else if(t.size() >= 1) {
                    print(1);
                }
                else {
                    print(0);
                }
            }
            else if(front >= 4) {
                if(t.size() < 2){
                    print(0);
                }
                else{
                    print(1);
                }
            }
            else {
                print(0);
            }
        }
        else if(f.size() >= 2) {
            print(1);
        }
        else {
            print(0);
        }
    }
    return 0;
}
