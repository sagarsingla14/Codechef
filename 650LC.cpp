#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll checkprime(ll n) {
    if(n == 2 || n ==3) {
        return 1;
    }
    ll flag = 1;
    for(ll i = 2 ; i <= sqrt(n) ; i++) {
        if((n % i) == 0) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        return 1;
    }
    else{
        return 0;
    }
}

ll highestfactor(ll n) {
    ll mx = 1;
    for(ll i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            ll f1 = i;
            ll f2 = n / i;
            mx = max(mx , f1);
            mx = max(mx , f2);
        }
    }
    return mx;
}

int main() {
    ll n;
    cin >> n;
    ll dp[1001] = {0};
    dp[0] = 0 , dp[1] = 0 , dp[2] = 2 , dp[3] = 3 , dp[4] = 4 , dp[5] = 5;
    ll prime = checkprime(n);
    if(prime) {
        dp[n] = n;
    }
    else{
        for(ll i = 6 ; i <= n ; i++) {
            if(checkprime(i)) {
                dp[i] = i;
            }
            else{
                if(i % 2) {
                    ll factor = highestfactor(i);
                    cout << factor << endl;
                    ll val = dp[factor];
                    dp[i] = dp[factor] + (i / factor);
                }
                else{
                    dp[i] = dp[i / 2] + 2;
                }
            }
        }
    }

    for(ll i = 0; i <= n ; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    cout << dp[n] << endl;
    return 0;
}
