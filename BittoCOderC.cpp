#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

vector<vector<int> > and1 {{0,0,0,0},{0,1,2,3},{0,2,2,0},{0,3,0,3}};
vector<vector<int> > or1  {{0,1,2,3},{1,1,1,1},{2,1,2,1},{3,1,1,3}};
vector<vector<int> > xor1 {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};

vector<ll> solve(vector<ll> a , vector<ll> b, char oper){
    vector<ll> ans = {0,0,0,0};
    if(oper == '|'){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ans[or1[i][j]] = (ans[or1[i][j]] + (a[i]*b[j])%mod)%mod;
            }
        }
    }
    else if(oper == '&'){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ans[and1[i][j]] = (ans[and1[i][j]] + (a[i]*b[j])%mod)%mod;
            }
        }
    }

    else{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ans[xor1[i][j]] = (ans[xor1[i][j]] + (a[i]*b[j])%mod)%mod;
            }
        }
    }

    return ans;
}

ll modex(ll a, ll x) {
	if (x==0)
    {
        return 1;
    }
	if (x & 1)
    {
        return a * modex(a, x - 1) % mod;
    }
	ll v = modex(a, x >> 1);
	return v * v % mod;
}

pair<int,vector<ll> > sss(string s,int pos){
    vector<ll> a{1,1,1,1};
    if(s[pos] == '#'){
        return make_pair(pos  + 1,a);
    }

    if(s[pos] == '('){
        cout << "pos ->  " << pos << endl;
        pair<int,vector<ll> > aa = sss(s,pos+1);
        pos = aa.first;
        cout << "posaa ->  " << pos << endl;
        char op = s[pos];
        pair<int,vector<ll> > bb = sss(s,pos+1);
        pos = bb.first;
        cout << "posbb ->  " << pos << endl;

        vector<ll> anss  = solve(aa.second,bb.second,op);
        // cout<<pos<<" ";
        return make_pair(pos+1,anss);
    }
//     1
// (#^(#^#)^#)
    // return make_pair(0,vector<ll>{1,1,1,1});
    cout << "POSOUT -> " << pos << endl;
}


// (((#&#)^#)&#)

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        pair<int,vector<ll> >  ans= sss(s,0);
        cout << "POSOUT -> " << ans.first << endl;

        int pp = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '&' || s[i]=='|' || s[i]== '^'){
                pp++;
            }
        }
        cout << "x x " << endl;
        ll modu = modex(4,mod-2-pp);
        for(int i=0;i<4;i++){
            // cout<<ans.second[i]<<" ";
            cout<< (ans.second[i]*modu)%mod<<" ";
        }
        cout<<endl;
    }

}
