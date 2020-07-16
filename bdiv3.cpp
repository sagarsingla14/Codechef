#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        string s;
        for (int i = 0; i < n; i++)
        {
            s.push_back('a');
        }
        ll k1 = ceil((-1.0+(sqrt(1+8*(k))))/(2.0));
        ll k2 = k-(k1*(k1-1))/2 -1;
        s[n-k1-1] = 'b';
        s[n-k2-1] = 'b';
        cout<<s<<endl;
    }
}
