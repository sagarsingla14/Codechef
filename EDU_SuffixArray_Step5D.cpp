#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> cnt(400001);
vector <pair <pair <ll , ll> , ll>> v[400001];
vector <pair <pair <ll , ll> , ll>> cur;

void radix_sort(vector <pair <pair <ll , ll> , ll>> &a) {
    cur.clear();
    ll n = a.size();
    for(auto i : a) {
        ll in = i.first.second;
        v[in].push_back(i);
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < v[i].size() ; j++) {
            cur.push_back(v[i][j]);
        }
        v[i].clear();
    }
    a = cur;
    cur.clear();

    for(auto i : a) {
        ll in = i.first.first;
        v[in].push_back(i);
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < v[i].size() ; j++) {
            cur.push_back(v[i][j]);
        }
        v[i].clear();
    }
    a = cur;
    cur.clear();
}

int main() {
    fast_io
    string aa;
    cin >> aa;
    string str = "";
    str += aa;
    str += "$";
    reverse(aa.begin() , aa.end());
    str += aa;
    cout << str << endl;

    ll n = str.length();

    vector <pair <char , ll>> a;
    for(ll i = 0 ; i < n ; i++) {
        a.push_back({str[i] , i});
    }
    sort(a.begin() , a.end());

    vector <ll> p(n) , c(n);
    for(ll i = 0 ; i < n ; i++) {
        p[i] = a[i].second;
    }

    c[p[0]] = 0;
    for(ll i = 1 ; i < n ; i++) {
        if(a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        }
        else{
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    ll k = 0;

    while((1ll << k) < n) {
        vector <pair <pair <ll , ll> , ll>> a(n);
        for(ll i = 0 ; i < n ; i++) {
            a[i] = {{c[i] , c[(i + (1ll << k)) % n]} , i};
        }

        radix_sort(a);
        for(ll i = 0 ; i < n ; i++) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;
        for(ll i = 1 ; i < n ; i++) {
            if(a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            }
            else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k ++;
    }

    vector <ll> lcp(n);
    k = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(i != aa.length()) {
            ll positionI = c[i];
            ll prev = p[positionI - 1];
            while(str[i + k] == str[prev + k]) {
                k ++;
            }
            lcp[positionI] = k;
            k = max(k - 1 , 0ll);
        }
    }


    vector <ll> dp(n);
    for(ll i = 0 ; i < n ; i++) {
        if(p[i] > aa.length()) {
            dp[i] = 2;
        }
        else if(p[i] < aa.length()) {
            dp[i] = 1;
        }
    }

    for(ll i = 1 ; i < n ; i++) {
        cout << p[i] << " " << dp[i] << " " << str.substr(p[i]) << " " << lcp[i] << endl;
    }

    ll mxCommon = 0 , sum = 0 , flag = 0;
    for(ll i = 2 ; i < n ; i++) {
        if(dp[i] != dp[i - 1]) {
            if(lcp[i]) {
                sum += lcp[i] - 1;
            }
            if(lcp[i] == 1) {
                flag = 1;
            }
        }
    }

    sum += flag;

    cout << sum << " " << (aa.length() * (aa.length() + 1)) / 2 << endl;
    sum += (aa.length() * (aa.length() + 1)) / 2;
    cout << sum << endl;

    return 0;
}