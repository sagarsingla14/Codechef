#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void file_io() {
    freopen("running_on_fumes_chapter_1_input.txt" , "r" , stdin);
    freopen("o7.txt", "w" , stdout);
}

int main() {
    fast_io
    file_io();
    ll t;
    cin >> t;
    for(ll c = 1 ; c <= t ; c ++) {
        ll n , m;
        cin >> n >> m;
        ll arr[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        if(m >= n - 1) {
            cout << "Case #" << c << ": " << 0 << endl;
        }
        else{
            ll cnt = 0 , mx = 0;
            for(ll i = 2 ; i <= n - 1 ; i++) {
                if(arr[i] == 0) {
                    cnt ++;
                    mx = max(mx , cnt);
                }
                else{
                    cnt = 0;
                }
            }
            mx = max(mx , cnt);

            if(mx >= m) {
                cout << "Case #" << c << ": " << -1 << endl;
            }
            else{

                ll dp[n + 1] = {0};
                dp[1] = 0;

                deque <pair <ll , ll>> q;
                for(ll i = 2 ; i <= 1 + m ; i++) {
                    dp[i] = 0;
                    ll sum = dp[i] + arr[i];
                    if(arr[i] != 0) {
                        while(!q.empty() && sum <= q.back().first) {
                            q.pop_back();
                        }
                        q.push_back({sum , i});
                    }
                }

                for(ll i = 2 ; i <= n - m ; i++) {
                    if(arr[i] != 0) {
                        pair <ll , ll> cur = q.front();
                        dp[i + m] = cur.first;
                        if(i == cur.second) {
                            if(!q.empty()) {
                                q.pop_front();
                            }
                        }

                        ll sum = dp[i + m] + arr[i + m];
                        if(arr[i + m] != 0) {
                            while(!q.empty() && sum <= q.back().first) {
                                q.pop_back();
                            }
                            q.push_back({sum , i + m});
                        }
                    }
                }
                cout << "Case #" << c << ": " << dp[n] << endl;
            }
        }
    }
    return 0;
}
