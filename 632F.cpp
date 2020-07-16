#include <bits/stdc++.h>
#define ll long long int
using namespace std;


vector <ll> ans;
ll n;

void sieve() {
    ans.assign(n + 1 , 0);
    ans[0] = INT_MAX;
    ans[1] = 1;
    for(ll i = 2 ; i <= n ; i++) {
        if(!ans[i]) {
            for(ll j = i ; j <= n ; j += i) {
                if(ans[j]) {
                    continue;
                }
                else{
                    ans[j] = j / i;
                }
            }
        }
    }
}


int main() {
    cin >> n;
    sieve();
    sort(ans.begin(), ans.end());
    for (ll i = 1 ; i < n ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
