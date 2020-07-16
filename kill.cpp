#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    if(n>m)
    {
        cout<<"-1"<<endl;
    }
    else if((m-n)%2==1){
        cout<<"-1"<<endl;
    }
    else if(m==0)
    {
        cout<<'0'<<endl;
    }
    else if(n==m)
    {
        cout<<'1'<<endl;
        cout<<n<<endl;
    }
    else{
        ll temp=(m-n)/2;
        if((n&temp)==0)
        {
            cout<<'2'<<endl;
            cout<<n+temp<<" "<<temp<<endl;
        }
        else{
            cout<<'3'<<endl;
            cout<<n<<" "<<temp<<" "<<temp<<endl;
        }
    }
    for(ll i = 0 ; i < 10 ; i++) {
        ll x = 0;
    }
    return 0;
}
