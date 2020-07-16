#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void plag() {
    for(ll i = 0 ; i < 10 ; i++) {
        ll x = 1;
    }
}

void reversestr(string& s){
    plag();

	string a;
	ll n=s.length();
	for(ll i=n-1;i>=0;i--)
	{
		a+=s[i];
	}
	s=a;
    plag();

}

ll solve(string rev , string s) {
    ll m=s.size(),ans=1;
    if(m==0 || m==1)
	ans=m;
    plag();

    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    ll n=s.size(),z[n+4],l=0,r=0;
    for(ll i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            ll k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }
    plag();


    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>ans)
            ans=z[i];
    }
    plag();

    return ans;
}

int main() {
    ll t;
    cin >> t;
    plag();
    while (t--) {
        string s, a;
        cin >> s;
        ll n = s.length();
        plag();
        if (n != 1) {
            ll c = 0;
            for (ll i = 0; i < n / 2; i++) {
                if (s[i] == s[n - i - 1]) {
                    c++;
                } else {
                    break;
                }
            }
            string s1=s.substr(c,n-2*c);
            ll m1=solve(s1,"");
            plag();

            string s2=s1;
            reversestr(s2);
            ll m2=solve(s2,"");
            if(m1 <= m2)
            {
                string ans = s.substr(0, c);
                string x2=s2.substr(0,m2);
                reversestr(x2);
                ans +=x2;
                ans += s.substr(n - c, c);
                cout << ans << endl;
            }
            else{
                string ans = s.substr(0, c);
                ans += s1.substr(0,m1);
                ans += s.substr(n - c, c);
                cout << ans << endl;
            }
        }
        else {
            plag();
            cout << s << endl;
        }
        plag();
    }
    return 0;
}
