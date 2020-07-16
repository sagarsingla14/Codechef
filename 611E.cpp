#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[200001][3];
ll val[200001][3];
ll arr[200001] = {0};
ll mx = 0;
ll n;

void maxSolve() {

    mx = 0;
    map <ll , ll> visited;
    map <ll , ll> mp;
    set <ll> s;
    for(ll i = 0 ; i < n ; i ++) {
        mp[arr[i]] ++;
        s.insert(arr[i]);
    }

    for(auto i : s) {
        ll freq = mp[i];
        ll add = 0;
        if(freq >= 3) {
            add = 3;
            ll v = i;
            if(visited[v - 1]) {
                add --;
            }
            else{
                visited[v - 1] = 1;
            }
            if(visited[v]) {
                add --;
            }
            else{
                visited[v] = 1;
            }
            if(visited[v + 1]) {
                add --;
            }
            else {
                visited[v + 1] = 1;
            }
            mx += add;
        }
        else if(freq == 2) {
            add = 2;
            ll v = i;
            if(visited[v]) {
                add --;
            }
            else{
                visited[v] = 1;
            }
            if(visited[v - 1] && visited[v + 1]) {
                add --;
            }
            else {
                if(!visited[v - 1]) {
                    visited[v - 1] = 1;
                }
                else{
                    visited[v + 1] = 1;
                }
            }
            mx += add;
        }
        else {
            add = 1;
            ll v = i;
            if(visited[v] && visited[v - 1] && visited[v + 1]) {
                add = 0;
            }
            else{
                if(!visited[v - 1]) {
                    visited[v - 1] = 1;
                    mx += add;
                }
                else if (!visited[v]) {
                    visited[v] = 1;
                    mx += add;
                }
                else {
                    visited[v + 1] = 1;
                    mx += add;
                }
            }
        }
    }

    cout << mx << endl;
}

void minSolve() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for(ll i = 1 ; i < n ; i ++) {
        for(ll j = 0 ; j < 3 ; j ++) {
            for(ll k = 0 ; k < 3 ; k ++) {
                if(val[i][j] == val[i - 1][k]) {
                    dp[i][j] = min(dp[i][j] , dp[i - 1][k]);
                }
                else{
                    dp[i][j] = min(dp[i][j] , dp[i - 1][k] + 1);
                }
            }
        }
    }

    ll mn = INT_MAX;
    for(ll j = 0 ; j < 3 ; j++) {
        mn = min(mn , dp[n - 1][j]);
    }
    cout << mn << " ";
}

void fillValues() {
    for(ll i = 0 ; i < n ; i++) {
        val[i][0] = arr[i] - 1;
        val[i][1] = arr[i];
        val[i][2] = arr[i] + 1;
    }
}

void fillDp() {
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < 3 ; j++) {
            dp[i][j] = 1e10;
        }
    }

    minSolve();
    maxSolve();
}


int main() {

    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr , arr + n);

    fillValues();
    fillDp();

    return 0;
}
