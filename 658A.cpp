#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string a , b;
        cin >> a >> b;
        vector <ll> v;
        for(ll i = 0 ; i < n - 1 ; i++) {
            if(a[i] == '1' && a[i + 1] == '0') {
                v.push_back(i + 1);
            }
            if(a[i] == '0' && a[i + 1] == '1') {
                v.push_back(i + 1);
            }
        }

        ll i = n - 1;
        char cur = '1';
        ll cnt = 0;
        ll start = n - 1;
        while(i >= 0) {
            cnt = 0;
            start = i;
            while(i >= 0 && cur != b[i]) {
                cnt ++;
                i --;
            }

            if(cur == '0') {
                cur = '1';
            }
            else{
                cur = '0';
            }
            if(cnt) {
                v.push_back(start + 1);
                v.push_back(start + 1 - cnt);
            }
        }

        vector <ll> ans;
        for(ll i = 0 ; i < v.size() ; i++) {
            if(v[i]) {
                ans.push_back(v[i]);
            }
        }

        cout << ans.size() << " ";
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
