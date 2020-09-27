#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        vector <ll> one , zero , ans(n);
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '0') {
                if(one.empty()) {
                    zero.push_back(zero.size());
                    ans[i] = zero.back();
                }
                else{
                    ll cur = one.back();
                    one.pop_back();
                    zero.push_back(cur);
                    ans[i] = cur;
                }
            }
            else {
                if(zero.empty()) {
                    one.push_back(one.size());
                    ans[i] = one.back();
                }
                else{
                    ll cur = zero.back();
                    zero.pop_back();
                    one.push_back(cur);
                    ans[i] = cur;
                }
            }
        }

        cout << one.size() + zero.size() << endl;
        for(auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
