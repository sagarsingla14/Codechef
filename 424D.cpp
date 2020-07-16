#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k , p;

int main() {
    cin >> n >> k >> p;

    ll person[n] = {0};
    ll key[k] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> person[i];
    }
    for(ll i = 0 ; i < k ; i++) {
        cin >> key[i];
    }

    sort(person , person + n);
    sort(key , key + k);


    ll ans = 9e18;
    for(ll i = 0 ; i <= k - n ; i++) {
        ll curAns = 0;
        ll index = 0;
        for(ll j = i ; j < i + n ; j++) {
            curAns = max(curAns , abs(person[index] - key[j]) + abs(p - key[j]));
            index ++;
        }
        ans = min(ans , curAns);
    }

    cout << ans << endl;
    return 0;
}
