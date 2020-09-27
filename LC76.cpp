#include <bits/stdc++.h>
#define ll long long int
using namespace std;

map <char , ll> sf , tf , cur;

ll le , re;
ll ind , windowSize;

void check(string s , string t) {
    while(le < s.length()) {
       if(tf[s[le]]) {
           if(cur[s[le]] > tf[s[le]]) {
               cur[s[le]] --;
               le ++;
               if(windowSize > re - le + 1) {
                   windowSize = re - le + 1;
                   ind = le;
               }
           }
           else{
               break;
           }
       }
       else {
           le ++;
           if(windowSize > re - le + 1) {
               windowSize = re - le + 1;
               ind = le;
           }
       }
    }
}

string minWindow(string s, string t) {

    for(auto i : s) {
        sf[i] ++;
    }
    for(auto i : t) {
        tf[i] ++;
    }

    ll ok = 0 , dist = tf.size() , cnt = 0;

    for(char ch = 'a' ; ch <= 'z' ; ch ++) {
        if(tf[ch] > sf[ch]) {
            ok = 1;
            break;
        }
    }

    if(ok || t == "" || s == "") {
        return "";
    }
    le = 0 , re = -1;

    for(ll i = 0 ; i < s.length() ; i++) {
        if(tf[s[i]]) {
            cur[s[i]] ++;
            if(cur[s[i]] == tf[s[i]]) {
                cnt ++;
            }
            if(cnt == dist) {
                re = i;
                break;
            }
        }
    }

    ind = 0 , windowSize = re + 1;
    ll temp = re;


    check(s , t);
    for(ll i = temp + 1 ; i < s.size() ; i++) {
        re = i;
        if(tf[s[i]]) {
            cur[s[i]] ++;
        }
        check(s , t);
    }
    check(s , t);

    string ans = "";
    for(ll i = ind ; i < ind + windowSize ; i++) {
        ans += s[i];
    }

    return ans;
}

int main() {
    string s , t;
    cin >> s >> t;
    cout << minWindow(s , t) << endl;
    return 0;
}
