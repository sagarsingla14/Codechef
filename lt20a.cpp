#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return res % mod;
}

int main() {
    train_choot_jayegi

    ll t ;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
        if(arr[0] == 1) {
            set <ll> s;
            map <ll , ll> mp;
            for(ll i = 0 ; i < n ; i++) {
                s.insert(arr[i]);
                mp[arr[i]] ++;
            }

            vector <ll> v;
            for(auto i : s) {
                v.push_back(i);
            }
            //
            // for(auto i : v) {
            //     cout << i << " ";
            // }
            // cout << endl;

            // series
            ll ans4 = 0;
            ll val = 0;

            ll mul = power(2 , mp[1]);
            mul += mod;
            mul --;
            mul %= mod;
            mul %= mod;

            // cout << "Mul " << mul << endl;

            ll index = 0;
            ll flag = 0;
            if(v[1] == 2) {
                ans4 = 1;
            }
            for(ll i = 1 ; i < v.size() ; i++) {
                ll diff = abs(v[i] - v[i - 1]);
                ll ways = 0;
                if(diff == 1) {
                    ways = power(2 , mp[v[i]]);
                    ways += mod;
                    ways --;
                    ways %= mod;
                    // cout << "Ways " << ways << endl;
                    ways *= (v[i] + 1);
                    ways %= mod;
                    // cout << "Ways " << ways << endl;
                    ans4 *= ways;
                    ans4 %= mod;
                }
                else{
                    index = i;
                    val = v[i - 1];
                    flag = 1;
                    break;
                }
            }

            // cout << "ans " << mul * ans4 << endl;
            // cout << index << " val " << val << endl;

            if(flag) {
                for(ll i = index ; i < v.size() ; i++) {
                    ll ways = power(2 , mp[arr[i]]);
                    ways += mod;
                    ways --;
                    ways *= val;
                    ways %= mod;

                    ans4 *= ways;
                    ans4 %= mod;
                }
            }

            ans4 *= mul;
            ans4 %= mod;

            // cout << "ans4 " << ans4 << endl;
            //

            //only 1
            ll ans1 = power(2 , mp[1]);
            ans1 += mod;
            ans1 --;
            ans1 %= mod;
            ans1 *= 2;
            ans1 %= mod;
            // cout << "ans1 " << ans1 << endl;

            ll cnt = 0;
            for(auto i : mp) {
                if(i.first > 2) {
                    cnt += i.second;
                }
            }

            // 1 without 2
            ll ans2 = power(2 , cnt);
            ans2 += mod;
            ans2 --;
            ans2 %= mod;
            ans2 *= 2;
            ans2 %= mod;
            ans2 *= mul;

            // cout << "ans2 " << ans2 << endl;


            // without 1
            cnt = 0;
            cnt = n - mp[1];
            ll ans3 = power(2 , cnt);
            // ans3 += mod;
            // ans3 --;
            ans3 %= mod;

            ans1 %= mod;
            ans1 += ans2;
            ans1 %= mod;
            ans1 += ans3;
            ans1 %= mod;
            ans1 += ans4;
            ans1 %= mod;

            // cout << "ans3 " << ans3 << endl;

            cout << (ans1 % mod) << endl;
            // series
        }
        else {
            ll ans = power(2 , n);
            cout << ans % mod << endl;
        }
    }
    return 0;
}
