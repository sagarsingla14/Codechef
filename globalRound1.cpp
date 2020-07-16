#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m , k;
ll ans = 0;

ll arr[100001];
vector <ll> v;

void calcAnswer() {
    ll cnt = n - k;
    for(ll i = 0 ; i < cnt ; i++) {
        ans += v[i];
    }
    cout << ans << endl;
}

int main() {

    cin >> n >> m >> k;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 0 ; i < n - 1 ; i++) {
        v.push_back(abs(arr[i] - arr[i + 1]) - 1);
    }
    sort(v.begin() , v.end());

    ans = n;
    calcAnswer();

    return 0;
}
