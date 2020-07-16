#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main() {
    ll n , k;
    cin >> n >> k;
    priority_queue <ll , vector <ll> , greater <ll> > a , b , c;
    ll cntA = 0 , cntB = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll t , x , y;
        cin >> t >> x >> y;
        if(!x && !y) {
            continue;
        }
        else if(x && y) {
            c.emplace(t);
            cntA ++ , cntB ++;
        }
        else if(!x && y) {
            b.emplace(t);
            cntB ++;
        }
        else {
            a.emplace(t);
            cntA ++;
        }
    }

    if(cntA < k || cntB < k) {
        cout << - 1 << endl;
    }
    else {
        ll ans = 0;
        ll cnt = k;
        while(cnt && !a.empty() && !b.empty() && !c.empty()) {
            ll ai = a.top();
            ll bi = b.top();
            ll ci = c.top();

            if(ai + bi <= ci) {
                ans += (ai + bi);
                a.pop();
                b.pop();
            }
            else{
                ans += ci;
                c.pop();
            }
            cnt --;
        }

        while(cnt && !a.empty() && !b.empty()) {
            ans += (a.top() + b.top());
            a.pop();
            b.pop();
            cnt --;
        }
        while(cnt && !c.empty()) {
            ans += c.top();
            c.pop();
            cnt --;
        }
        cout << ans << endl;
    }

    return 0;
}
