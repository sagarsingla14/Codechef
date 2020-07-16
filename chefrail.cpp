#include<bits/stdc++.h>
using namespace std;
#define ll long long int

set <ll> primefactors(ll n) {
    map <ll,ll> check;
    check[1]=1;
    set <ll> s;
    for (ll i = 2 ; i <= sqrt(n) ; i += 2) {

        if (n % i == 0) {
            n /= i;
            check[i]++;

            while (n % i == 0) {
                check[i]++;
                n /= i;
            }
        }
    }

    if(n >= 2) {
        check[n]++;
    }

    ll flag=0;
    for(auto it : check)
        if(it.second % 2 == 1){
            flag=1;
            s.insert(it.first);
        }
    if(!flag) {
        s.insert(-1);
    }

    return s;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n , m;
        cin >> n >> m;
        vector <ll> xpos , xneg , ypos , yneg;
        map <ll , ll> xsq , ysq;
        ll zerox = 0 , zeroy = 0;
        ll x[n] = {0};
        ll y[m] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> x[i];
            if(x[i] == 0) {
                zerox = 1;
            }
            else{
                if(x[i] > 0) {
                    xpos.push_back(x[i]);
                }
                else{
                    xneg.push_back(abs(x[i]));
                }
            }
            ll sq = x[i] * x[i];
            xsq[sq] ++;
        }

        for(ll i = 0 ; i < m ; i++) {
            cin >> y[i];
            if(y[i] == 0) {
                zeroy = 1;
            }
            else{
                if(y[i] > 0) {
                    ypos.push_back(y[i]);
                }
                else{
                    yneg.push_back(abs(y[i]));
                }
            }
            ll sq = y[i] * y[i];
            ysq[sq] ++;
        }
        ll count = 0;

        map<set<ll>,vector<ll>> facxn , facxp ,facyn , facyp;

        for(ll i=0 ; i < xpos.size() ; i++) {
            set <ll> s = primefactors(xpos[i]);
            facxp[s].push_back(i);
        }

        for(ll i = 0 ; i < ypos.size(); i++) {
            set <ll> s=primefactors(ypos[i]);
            facyp[s].push_back(i);
        }

        for(ll i = 0 ; i < xneg.size() ; i++) {
            set <ll> s = primefactors(xneg[i]);
            if(facxp.find(s) != facxp.end()) {
                for(auto it:facxp[s]) {
                    ll ans = xneg[i] * xpos[it];
                    if(ysq.find(ans) != ysq.end()) {
                        count += ysq[ans];
                    }
                }

            }

        }

        for(ll i = 0 ; i < yneg.size() ; i++) {
            set <ll> s = primefactors(yneg[i]);
            if(facyp.find(s)!=facyp.end()) {
                for(auto it:facyp[s]) {
                ll ans = yneg[i] * ypos[it];
                if(xsq.find(ans) != xsq.end())
                    count += xsq[ans];
                }
            }
        }

        ll ans = 0;
        if(zeroy == 1) {
            ans += (m - 1) * n;
        }
        if(zerox == 1) {
            ans += (n - 1) * m;
        }

        cout << ans + count << endl;
    }
    return 0;
}
