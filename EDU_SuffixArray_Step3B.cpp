#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    string str;
    cin >> str;
    str += "$";

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

    ll q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        ll len = s.length();

        ll l = 0 , r = n - 1;
        ll left = -1 , right = -1;

        while(l <= r) {
            ll mid = (l + r) >> 1ll;
            ll index = p[mid];
            string cur = "";

            for(ll i = index ; i < min(index + len , n) ; i++) {
                cur += str[i];
            }
            if(cur == s) {
                left = mid;
                r = mid - 1;
            }
            else if(cur < s) {
                l = mid + 1;
            }
            else if(cur > s) {
                r = mid - 1;
            }
        }

        l = 0 , r = n - 1;
        while(l <= r) {
            ll mid = (l + r) >> 1ll;
            ll index = p[mid];
            string cur = "";
            for(ll i = index ; i < min(index + len , n) ; i++) {
                cur += str[i];
            }
            if(cur == s) {
                right = mid;
                l = mid + 1;
            }
            else if(cur < s) {
                l = mid + 1;
            }
            else if(cur > s) {
                r = mid - 1;
            }
        }

        if(left != -1 && right != -1) {
            cout << right - left + 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
