#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n,k;
   cin>>n>>k;
   if(n<k*k)
   {
       cout<<"NO\n";
       continue;
   }
   if(k%2==0)
   {
       if(n%2==0)
       {
          cout<<"YES\n";

       }
       else cout<<"NO\n";


   } else
   {

       if(n&1)
       {

       cout<<"YES\n";
       }
       else cout<<"NO\n";
   }    cout << "NO" << endl;
        }
        return 0;
    }
