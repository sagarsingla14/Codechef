#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
    }
    else {
        ll dp[n - 1] = {0};

        for(ll i = 0 ; i < n - 1 ; i ++) {
            dp[i] = arr[i + 1] - arr[i];
        }

        ll impo = 0;
        ll cnt = 0;
        ll temp = 0;

        for(ll i = 0 ; i < n - 1 ; i++) {
            if(dp[i] <= -1) {
                temp ++;
            }
            else{
                if(temp) {
                    cnt ++;
                }
                temp = 0;
            }
        }

        if(temp) {
            cnt ++;
        }
        if(cnt > 1) {
            cout << "no" << endl;
        }
        else{
            if(cnt == 0) {
                cout << "yes" << endl;
                cout << 1 << " " << 1 << endl;
            }
            else {
                ll found = 0;
                ll start = 0;
                ll last = 0;
                for(ll i = 0 ; i < n - 1 ; i++) {
                    if(!found && dp[i] <= -1) {
                        found = 1;
                        start = i + 1;
                    }
                    if(found) {
                        if(dp[i] <= -1) {
                            last = i + 1;
                        }
                        else {
                            break;
                        }
                    }
                }
                last ++;


                vector <ll> v;
                for(ll i = start - 1 ; i <= last - 1 ; i++) {
                    v.push_back(arr[i]);
                }

                reverse(v.begin() , v.end());

                for(ll i = 0; i < v.size() ; i++) {
                    arr[start - 1 + i] = v[i];
                }

                ll impo = 0;
                for(ll i = 0 ; i < n - 1 ; i++) {
                    if(arr[i + 1] < arr[i]) {
                        impo = 1;
                    }
                }

                if(impo) {
                    cout << "no" << endl;
                }
                else {
                    cout << "yes" << endl;
                    cout << start << " " << last << endl;
                }
            }
        }
    }
    return 0;
}
