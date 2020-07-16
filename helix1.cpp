#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> dp[10000];

int main() {
    ll n , q;
    cin >> n >> q;
    ll sum = 0;

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            dp[i].push_back(0);
        }
    }

    ll s[10000] = {0};
    ll freq[10000] = {0};

    map < pair <ll , ll> , ll> mp;

    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            cout << sum << endl;
        }
        else if(t == 2) {
            ll i , j;
            cin >> i >> j;
            i -- , j --;

            mp[{i , j}] ++;

            ll cur = mp[{i , j}];
            cur += freq[i];
            if(cur % 2 != 0) {
                sum ++;
                s[i] ++;
                mp[{i , j}] = (cur % 2);
                freq[i] = 0;
            }
            else {
                sum --;
                s[i] --;
                mp[{i , j}] = (cur % 2);
                freq[i] = 0;
            }
        }
        else {

            ll row;
            cin >> row;
            row --;

            ll curSum = s[row];
            ll newSum = n - s[row];
            ll varry = newSum - curSum;

            sum += varry;
            freq[row] ++;
        }
    }

    return 0;
}
