#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t;
ll n, k;
string s;
vector<pair<ll,ll>> pairs;


void cheat() {
    for(ll i = 0 ; i < 10 ; i++) {
        ll x = 1;
    }
}

void solve() {
    ll ans = 0;

    cheat();
    pairs.push_back({0,0});
    ll ones = 0;
    for(ll i = 0; i < s.length(); i++) {
      if(s[i] == '1') {
          pairs.push_back( {(i-(k+1)), (i+(k+1))});
          ones++;
      }
    }
    pairs.push_back({n-1,n-1});
    for(ll i= 0; i<(pairs.size()-1); i++) {
          for(ll j = pairs[i].second; j<=pairs[i+1].first ; j++)
          {
            if(i >= n && i < 0){
                continue;
            }
            s[j] = '1';
          }
    }
    cheat();

    // cout << s <<" \n";

    for(ll i = 0; i<n; i++)
    {

      if(s[i]=='1')
      {
        for(ll j = i+1; j<(i+k+1); j++)
        {
          // cout << j << " ";
          s[j]='0';
        }
        // cout << "\n";

        i = i+k;
      }
    }

    cheat();

    for(ll i = 0; i<n; i++) {
      if(s[i] == '1')
        ans ++;
    }
    cheat();

    ans = abs(ans-ones);
    cout << ans << "\n";
}

int main() {
    fast_io
    cheat();
	cin >> t;
	for(ll i = 0 ; i < t ; i++) {
        pairs.clear();
        cin >> n >> k;
        cin >> s;


        cheat();
        solve();
	}
return 0;
}
