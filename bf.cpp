#include<bits/stdc++.h>
using namespace std;
#define ll long long int
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        ll count = 0;
        ll c=b;
        while(c!=0) {
            count ++;
            c/=10;
        }
        ll sub=count;
        ll num=power(10LL,sub)-1;

      if(num > b) {
        count --;
      }
      cout<<a* count<<endl;
    }




return 0;


}
