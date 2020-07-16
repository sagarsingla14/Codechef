#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


vector <ll> KMP(string str) {
    ll n = str.length();
    vector <ll> pi(n , 0);
    ll point = 0;
    for(ll i = 1 ; i < n ; i++) {
        while (point > 0 && str[i] != str[point]) {
            point = pi[point - 1];
        }
        if(str[i] == str[point]) {
            point ++;
        }
        pi[i] = point;
    }

    return pi;
}

int main() {
    ll n;
    cin >> n;
    string arr[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    string ans = "";

    for(ll i = 0 ; i < n ; i++) {

        string str = arr[i];
        ll ansLen = ans.length();
        ll curLen = str.length();
        ll start = max(0ll , ansLen - curLen);

        vector <ll> pi = KMP(str);

        ll point = 0;
        for(ll j = start ; j < ans.length() ; j++) {
            while(point > 0 && ans[j] != str[point]) {
                point = pi[point - 1];
            }
            if(ans[j] == str[point]) {
                point ++;
            }
        }
        for(ll j = point ; j < str.length() ; j++) {
            ans += str[j];
        }
    }

    cout << ans << endl;
    return 0;
}
