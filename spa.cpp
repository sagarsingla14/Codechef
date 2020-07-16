#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define fio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

ll dp[100001];
void fact() {
    dp[0] = 1;
    for(ll i = 1 ; i <= 100000 ; i++) {
        dp[i] = ((dp[i - 1] % mod) * ( i % mod));
        dp[i] %= mod;
    }
}

ll power(ll x , ll y) {
    ll res = 1;
    x %= mod;
    while(y > 0) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        y = y >> 1;
        // y %= mod;
        x *= x;
        x %= mod;
    }
    return res % mod;
}

int main() {
    fio
    ll t;
    // cin >> t;
    scanf("%lld",&t);
    fact();
    while(t--) {
        ll n ;
        // cin >> n;
        scanf("%lld",&n);

        ll arr[2 * n] = {0};
        ll sum = 0;

        for(ll i = 0 ; i < 2 * n ; i++) {
            // cin >> arr[i];
            scanf("%lld",&arr[i]);

            sum += arr[i];
        }

        ll arraySum = sum / (n + 1);
        ll rem = sum % (n + 1);
        ll cnt = 0;

        for(ll i = 0 ; i < 2 * n ; i++) {
            if(arraySum == arr[i]) {
                cnt ++;
            }
            if(cnt == 2) {
                break;
            }
        }
        if(rem) {
            // cout << 0 << endl;
            printf("0\n");

        }
        else{
            if(cnt != 2) {
                // cout << 0 << endl;
                printf("0\n");

            }
            else{
                cnt = 0;
                vector <ll> v;
                for(ll i = 0 ; i < 2 * n ; i++) {
                    if(arr[i] == arraySum) {
                        if(cnt < 2) {
                            cnt ++;
                        }
                        else{
                            v.push_back(arr[i]);
                        }
                    }
                    else{
                        v.push_back(arr[i]);
                    }
                }

                ll pw = 0;
                sort(v.begin() , v.end());
                ll sze = v.size();
                unordered_map <ll , ll> freq;
                ll flag = 0;
                for(ll i = 0 ; i < sze / 2 ; i++) {
                    if(v[i] != arraySum - v[sze - 1 - i]) {
                        flag = 1;
                        break;
                    }
                    else{
                        if(v[i] != v[sze - i - 1 ]) {
                            freq[v[i]] ++;
                            pw ++;
                        }
                        else{
                            freq[v[i]] ++;
                        }
                    }
                }

                if(flag == 1) {
                    // cout << 0 << endl;
                    printf("0\n");

                }
                else {
                    ll result = 0;

                    ll pow = power(2 , pw);
                    // pow %= mod;
                    ll fact = dp[n - 1];
                    // fact %= mod;

                    result = (pow % mod )* (fact % mod);
                    result %= mod;

                    unordered_map <ll , ll> :: iterator itr;
                    for(itr = freq.begin() ; itr != freq.end() ; itr++) {
                        ll x = dp[itr -> second];
                        result *= power(x , mod - 2);
                        result %= mod;
                    }
                    // cout << result % mod << endl;
                    printf("%lld\n", result % mod);
                    
                }
            }
        }
    }
    return 0;
}
