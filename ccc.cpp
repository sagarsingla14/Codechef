#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

int main() {

//THIS CODE IS CREATED BY ANSHJAIN18
    string s;
    cin >> s;
    map <ll,ll> mp;
    vector<vector<ll>> mera(26,vector<ll>(26,0));

    for(ll i =0 ; i < 26 ; i++) {
        ll x = 10;
    }

    ll ans=0;
    for(ll i=0;i<s.length();i++)
    {
        for(ll j=0;j<26;j++)
        {
            if(mp[j]==0) continue;

            mera[j][s[i]-'a']+=mp[j];
            ans=max(ans,mera[j][s[i]-'a']);
        }
        mp[s[i]-'a']++;
        ans=max(ans,mp[s[i]-'a']);
    }
    for(ll i =0 ; i < 26 ; i++) {
        ll x = 10;
    }
    cout<<ans << endl;

return 0; }
