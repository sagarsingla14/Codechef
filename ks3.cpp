#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000000
using namespace std;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2) % mod;
    if(y & 1) {
        return (((pw * pw) % mod) * x) % mod;
    }
    return (pw * pw) % mod;
}

map<char,ll> sol(string s){
    string ans = "";
    stack<ll> sta;
    map<char,ll> m;
    map<ll,ll> num;

    for(ll i=0;i<s.size();i++){
        if(s[i] >= '2' && s[i] <= '9'){
            num[s[i]-'0']++;
            sta.push((s[i]-'0'));
        }
        else if(s[i] == '('){
            continue;
        }
        else if(s[i] == ')'){
            num[sta.top()]--;
            sta.pop();
        }
        else{
            long long sss = 1;
            for(auto j:num) {
                sss *= (power(j.first , j.second) % mod);
                sss = sss%1000000000;
                // cout<<s[i]<<" "<<sss<<" "<<j.first<<" "<<j.second<<" ";

            }
            // cout << endl;
            if(sss == 0) {
                sss = 1;
            }
            m[s[i]] += sss;
            m[s[i]] %= 1000000000;
        }
    }
    return m;
}

int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        string str;
        cin >> str;
        ll l = str.length();
        map <char , ll> mp = sol(str);

        ll vertical = 1;
        ll horizontal = 1;

        vertical -= mp['N'];
        if(vertical <= 0) {
            vertical += 1000000000;
        }

        vertical += mp['S'];
        if(vertical > 1000000000) {
            vertical %= 1000000000;
        }

        horizontal -= mp['W'];
        if(horizontal <= 0) {
            horizontal += 1000000000;
        }

        horizontal += mp['E'];
        if(horizontal > 1000000000) {
            horizontal %= 1000000000;
        }w

        cout << "Case #" << c << ": " << horizontal << " " << vertical << endl;
        c ++;
    }
    return 0;
}
