#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t , n;
string str , pre , mid , suf;

void calcPreAndSuf() {
    ll i = 0;
    ll j = n - 1;
    while(str[i] == str[j] && i < n / 2) {
        pre += str[i];
        suf += str[j];
        i ++;
        j --;
    }
    reverse(suf.begin() , suf.end());
}

string KMP(string ss) {
    string res = ss;
    string s = ss;
    reverse(s.begin() , s.end());
    ss += '#';
    ss += s;

    n = ss.length();
    ll pi[n] = {0};
    ll point = 0;

    for(ll i = 1 ; i < n ; i++) {
        while(point != 0 && ss[i] != ss[point]) {
            point = pi[point - 1];
        }

        if(ss[i] == ss[point]) {
            point ++;
        }
        pi[i] = point;
    }

    s = "";
    for(ll i = 0 ; i < point ; i++) {
        s += res[i];
    }
    return s;
}

void calcMid(string ss) {
    if(ss.length()) {
        string mPrefix = "";
        string mSuffix = "";

        mPrefix = KMP(ss);
        reverse(ss.begin() , ss.end());

        mSuffix = KMP(ss);

        if(mPrefix.length() > mSuffix.length()) {
            mid = mPrefix;
        }
        else{
            mid = mSuffix;
        }
    }
}

void print() {
    cout << pre + mid + suf << endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> str;
        n = str.length();

        pre = "";
        mid = "";
        suf = "";

        calcPreAndSuf();
        string ss = "";

        ll l = n - 2 * suf.length();
        for(ll i = 0 ; i < l ; i++) {
            ss += str[suf.length() + i];
        }

        calcMid(ss);
        print();
    }
    return 0;
}
