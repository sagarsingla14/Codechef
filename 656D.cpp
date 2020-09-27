#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ans;
ll n;
string str;

void solve(ll left , ll right , ll val , char ch) {

    ll mid = (left + right) >> 1ll;
    ll len = (right - left + 1) >> 2;

    if(left == right) {
        if(str[left] == ch) {
            ans = min(ans , val);
        }
        else{
            ans = min(ans , val + 1);
        }
        return;
    }

    map <char , ll> mp;
    for(ll i = left ; i <= mid ; i++) {
        mp[str[i]] ++;
    }
    solve(mid + 1 , right , val + (len - mp[ch]) , ch + 1);

    mp.clear();
    for(ll i = mid + 1 ; i <= right ; i++) {
        mp[str[i]] ++;
    }
    solve(left , mid , val + (len - mp[ch]) , ch + 1);

    return;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ans = 1000000000000000000;
        cin >> n >> str;

        solve(0 , n - 1 , 0 , 'a');
        cout << ans << endl;
    }
    return 0;
}
