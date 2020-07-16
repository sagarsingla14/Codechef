#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll check = 0;
        vector <ll> ans;
        unordered_map <ll , ll> mp;
        for(ll j = 0 ; j < n ; j++) {
            ll v ;
            cin >> v;
            ll flag = 0;
            for(ll i = 0; i < v ; i++) {
                ll p;
                cin >> p;
                if(!mp[p] && flag == 0 && check == 0) {
                    mp[p] = 1;
                    flag = 1;
                }
            }

            if(flag == 0 && check == 0) {
                check = 1;
                for(ll i = 1 ; i <= n ; i++) {
                    if(!mp[i]) {
                        ans.push_back(j + 1);
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        if(check) {
            cout << "IMPROVE" << endl;
            cout << ans[0] << " " << ans[1] << endl;
        }
        else{
            cout << "OPTIMAL" << endl;
        }
    }
    return 0;
}
