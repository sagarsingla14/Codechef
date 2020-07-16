#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void printString(string str , ll index , ll n) {
    for(ll i = 0 ; i <= n - 1 - index ; i++) {
        ll start = i , end = i + index;
        while(start <= end) {
            swap(str[start] , str[end]);
            start ++ , end --;
        }
    }

    cout << str << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        string str;
        cin >> n >> str;
        map <char , ll> freq;
        map <char , ll> index;
        for(ll i = 0 ; i < n ; i++) {
            freq[str[i]] ++;
            index[str[i]] = i;
        }
        if(freq.size() == 1) {
            cout << str << endl;
            cout << 1 << endl;
            continue;
        }
        map <char , ll> :: iterator itr;
        char ans ;
        for(itr = freq.begin() ; itr != freq.end() ; itr ++) {
            ans = itr -> first;
            break;
        }
        if(freq[ans] == 1) {
            printString(str , index[ans] , n);
            cout << index[ans] + 1 << endl;
        }
        else{
            ll mn = INT_MAX;
            ll revIndex = -1;
            for(ll i = 0 ; i < n ; i++) {
                if(str[i] == ans) {
                    ll diff;
                    if(i == 0 || i == n - 1) {
                        if(i == 0) {
                            diff = abs(str[i] - str[i + 1]);
                        }
                        else{
                            diff = abs(str[i] - str[i - 1]);
                        }
                    }
                    else{
                        diff = abs(str[i] - str[i - 1]);
                        diff = min(abs(str[i] - str[i - 1]) , abs(str[i] - str[i + 1]));
                    }
                    if(mn > diff) {
                        mn = diff;
                        revIndex = i;
                    }
                }
            }
            printString(str , revIndex , n);
            cout << revIndex + 1 << endl;
        }
    }
}
