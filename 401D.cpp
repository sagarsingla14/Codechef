#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n;
    cin >> n;
    string arr[n];
    string dp[n];
    map <string , ll> freq;

    for(ll i = 0 ; i < n ; i++) {
        string str;
        cin >> str;
        string inp = "";
        for(ll j = 1 ; j < str.length() ; j++) {
            inp += str[j];
        }
        freq[inp] ++;
        arr[i] = inp;
        dp[i] = inp;
    }

    sort(dp , dp + n);

    vector <string> ans;
    unordered_map <string , ll> mp;

    ll i = 0 , j = 0;
    while(i < n && j < n) {
        string op = "";
        if(mp[dp[j]] == freq[dp[j]]) {
            j ++;
        }
        else if(arr[i] > dp[j]) {
            for(ll k = 0 ; k < min(arr[i].length() , dp[j].length()) ; k ++) {
                if(arr[i][k] == dp[j][k]) {
                    op += arr[i][k];
                }
                else{
                    break;
                }
            }
            mp[arr[i]] ++;
            i ++;
            ans.push_back(op);
        }
        else if(arr[i] == dp[j]) {
            op = arr[i];
            mp[arr[i]] ++;
            i ++;
            j ++;
            ans.push_back(op);
        }
        else if(arr[i] < dp[j]) {
            j ++;
        }
    }

    for(ll i = n - 1 ; i >= 1 ; i--) {
        if(ans[i] < ans[i - 1]) {
            ans[i - 1] = ans[i];
        }
    }

    for(auto i : ans) {
        cout << "#" << i << endl;
    }
    return 0;
}
