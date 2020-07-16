#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n;
string str;

int main() {
    cin >> n >> str;
    vector <ll> dp[26];
    map <char , ll> mp , take;

    for(ll i = 0 ; i < 26 ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            dp[i].push_back(0);
        }
    }

    ll j = 0;
    for(auto i : str) {
        j ++;
        mp[i] ++;
        dp[i - 'A'][j] = 1;
    }

    for(ll i = 0 ; i < 26 ; i++) {
        for(j = 1 ; j <= n ; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    ll need = n / 4;
    for(auto i : mp) {
        ll curNeed = i.second - need;
        if(curNeed > 0) {
            take[i.first] = curNeed;
        }
    }

    if(take.size() == 0) {
        cout << 0 << endl;
    }
    else {
        ll f = 1 , l = n;
        for(auto i : take) {
            f = max(f , i.second);
        }

        ll ans = -1;
        while(f <= l) {
            ll mid = (f + l) / 2;
            ll ok = 0;

            for(ll i = 0 ; i <= n - mid ; i++) {
                ll left = i;
                ll right = i + mid;
                ll flag = 1;
                for(auto itr : take) {
                    char ch = itr.first;
                    need = itr.second;
                    ll present = dp[ch - 'A'][right] - dp[ch - 'A'][left];
                    if(present < need) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    ok = 1;
                    break;
                }
            }

            if(ok) {
                l = mid - 1;
                ans = mid;
            }
            else{
                f = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
