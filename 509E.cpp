#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
vector <ll> arr;
vector <pair <ll , ll> > ans;
ll u , v;
ll ok = 1;

int main() {
    cin >> n;
    ll sum[n + 1] = {0};
    map <ll , ll> mp;

    for(ll i = 0 ; i < n - 1 ; i++) {
        cin >> u >> v;
        sum[u] ++;
        mp[u] ++;
        if(v != n) {
            ok = 0;
        }
    }

    if(!ok) {
        cout << "NO" << endl;
    }
    else{
        for(ll i = 1 ; i <= n ; i++) {
            sum[i] += sum[i - 1];
        }
        for(ll i = 1 ; i <= n - 1 ; i++) {
            if(sum[i] > i) {
                ok = 0;
            }
        }

        if(!ok) {
            cout << "NO" << endl;
        }
        else{
            ans.clear();
            priority_queue <ll , vector <ll> , greater <ll> > pq;
            for(ll i = 1 ; i <= n ; i++) {
                if(mp[i] == 0) {
                    pq.push(i);
                }
            }

            ll prev = -1;
            for(ll i = 1 ; i <= n ; i++) {
                if(mp[i] == 0) {
                    continue;
                }

                mp[i] --;
                if(prev != -1) {
                    ans.push_back({prev , i});
                }
                prev = i;

                while(mp[i] > 0) {
                    ans.push_back({prev , pq.top()});
                    prev = pq.top();
                    mp[i] --;
                    pq.pop();
                }
            }
            ans.push_back({prev , n});

            cout << "YES" << endl;
            for(ll i = 0 ; i < n - 1 ; i++) {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }
    return 0;
}
