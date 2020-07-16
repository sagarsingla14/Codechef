#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void longestPalindrome(string str) {
       ll n = str.length();
       bool dp[n + 1][n + 1];
       memset(dp , false , sizeof(dp));
       for(ll i = 1 ; i <= n ; i++) {
           dp[i][i] = true;
       }
       // cout << n << endl;

       for(ll i = 0 ; i <= n - 2 ; i++) {
           if(str[i] == str[i + 1]) {
               dp[i + 1][i + 2] = true;
           }
           else{
               dp[i + 1][i + 2] = false;
           }
       }

       for(ll l = 2 ; l < n ; l++) {
           for(ll start = 0 ; start < n - l ; start ++) {
               ll end = start + l;
               if(str[start] == str[end]) {
                   dp[start + 1][end + 1] = dp[start + 2][end];
               }
               else{
                   dp[start + 1][end + 1] = false;
               }
           }
       }
       for(ll i = 0; i <= n ; i++){
           for(ll j = 0 ; j <= n ; j++) {
               cout << dp[i][j] << " ";
           }
           cout << endl;
       }

       ll left = -1 , right = -1 , mx = 0;
       for(ll l = 0 ; l < n ; l++) {
           for(ll start = 0 ; start < n - l ; start ++) {
               ll end = start + l;
               if(dp[start + 1][end + 1]) {
                   left = start , right = end;
               }
           }
       }
       string s = "";
       for(ll i = left ; i <= right ; i++) {
           s += str[i];
       }
       cout << s << endl;
 }
int main() {
    string str = "xx";
    longestPalindrome(str);
    return 0;
}
