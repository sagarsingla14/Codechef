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

    for(ll i = 0 ; i < n ; i++) {
        string str;
        cin >> str;
        string inp = "";
        for(ll j = 1 ; j < str.length() ; j++) {
            inp += str[j];
        }
        arr[i] = inp;
        dp[i] = inp;
    }

    sort(dp , dp + n);

    vector <string> ans;
    unordered_map <string , ll> mp;

    ll i = 0 , j = 0;
    while(i < n && j < n) {
        string op = "";
        if(mp[dp[j]]) {
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
            mp[arr[i]] = 1;
            i ++;
            ans.push_back(op);
        }
        else if(arr[i] == dp[j]) {
            op = arr[i];
            i ++;
            j ++;
            ans.push_back(op);
        }
        else if(arr[i] < dp[j]) {
            op = arr[i];
            j ++;
            ans.push_back(op);
        }
    }

    for(ll i = n - 1 ; i >= 1 ; i--) {
        if(ans[i] < ans[i - 1]) {
            ans[i - 1] = ans[i];
        }
    }

    for(auto ii : ans) {
        cout << "#" << ii << endl;
    }
    return 0;
}
