#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string a , b;
ll la , lb , ans = -1;
ll arr[200000];

void input() {
    memset(arr , 0 , sizeof(arr));
    cin >> a >> b;
    la = a.length();
    lb = b.length();

    for(ll i = 0 ; i < la ; i++) {
        cin >> arr[i];
    }
}

bool check(ll index) {
    unordered_map <ll , ll> mp;
    for(ll i = 0 ; i < index ; i ++) {
        mp[arr[i] - 1] = 1;
    }

    ll ok = 0;
    ll j = 0;
    for(ll i = 0 ; i < la ; i++) {
        if(mp[i] == 0 && b[j] == a[i]) {
            j ++;
        }
        if(j == lb) {
            ok = 1;
            break;
        }
    }
    return ok;
}

void solve() {
    ll start = 0 , end = la - 1;
    ll mid;
    while(start <= end) {
        mid = (start + end) / 2;
        if(check(mid)) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }
}

void printAnswer() {
    cout << ans << endl;
}

int main() {
    input();
    solve();
    printAnswer();
}
