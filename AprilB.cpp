#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll countSub(ll div[] , ll n , ll sum) {
    ll currsum = 0;
    ll cnt = 0;
    unordered_map <ll , ll> prev;
    for(ll i = 0 ; i < n ; i++) {
        currsum += div[i];
        if(currsum == sum) {
            cnt++;
        }
        if(prev.find(currsum - sum) != prev.end()) {
            cnt += (prev[currsum - sum]);
        }
        prev[currsum]++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t-- ){
        ll  n;
        cin >> n;
        ll ans = (n * (n + 1)) / 2;
        ll arr[n] = {0};

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        ll div[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            ll cnt = 0;
            ll temp = arr[i];
            if(temp % 2 == 1) {
                div[i] = 0;
            }
            else if(temp % 4 == 0) {
                div[i] = 2;
            }
            else{
                div[i] = 1;
            }
        }
        for(ll i = 0 ; i < n ; i++) {
                cout << div[i] << " ";
            }
            cout << endl;

        ll sum = 1;
        ll sub = countSub(div , n , sum);
        cout << ans - sub << endl;
    }
    return 0;
}
