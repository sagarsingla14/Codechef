#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , m , ans = 0;
ll arr[300001];

void input() {
    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
}

ll calcPrev(ll prev , ll cur , ll val) {
    if(cur < prev) {
        prev = prev;
    }
    else{
        ll reqOps = m - cur + prev;
        if(reqOps > val) {
            prev = cur;
        }
    }
    return prev;
}

bool predicateFunction(ll val) {
    ll ok = 1;
    ll prev = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(arr[i] == prev) {
            prev = arr[i];
        }
        else if(arr[i] > prev) {
            prev = calcPrev(prev , arr[i] , val);
        }
        else if(arr[i] < prev) {
            if(prev - arr[i] > val) {
                ok = 0;
                break;
            }
            else{
                prev = calcPrev(prev , arr[i] , val);
            }
        }
    }
    return ok;
}

void solve() {
    ll start = 0 , end = m;
    while(start <= end) {
        ll mid = (start + end) / 2;
        if(predicateFunction(mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
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
