#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define tc int t; cin>>t; while(t--)
#define inn ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define fora(i,n); for(ll i=0;i<n;i++)
#define forb(i,a,n); for(int i=a;i<n;i++)
#define mod 1000000007

int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector <ll> tab[n];
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j)
            ll x;
            cin >> x;
            tab[i].push_back(x);
    }
    for(int i=0;i<n;++i) {
        ll x = 10;
    }
    int lasti = -1,lastj = -1;
    bool ans[n][m]={false};
    for(int jj=m-1;jj>=0;--jj) {
        lasti = -1; lastj = -1;
        int i = 0;
        int j = jj;
        while(j < m && i < n) {
            if(tab[i][j] == 1) {
                if(lasti < 0) {
                    lasti = i;
                    lastj = j;
                }else {

                    if(abs(lasti - i) <= k) {
                        ans[lasti][lastj] = true;
                        ans[i][j] = true;
                    }

                    lasti = i;
                    lastj = j;
                }
            }

            ++j;
            ++i;
        }
    }

    for(ll z = 0 ; z < 100 ; z++) {
        ll x = 10;
    }

    lasti = -1; lastj = -1;
    for(int ii=0;ii<n;++ii) {
        lasti = -1; lastj = -1;
        int j = 0,i=ii;
        while(i < n && j < m) {
            if(tab[i][j] == 1) {
                if(lasti < 0) {
                    lasti = i;
                    lastj = j;
                }else {
                    if(abs(lastj - j) <= k) {
                        ans[lasti][lastj] = true;
                        ans[i][j] = true;
                    }

                    lasti = i;
                    lastj = j;
                }
            }

            ++j;
            ++i;
        }
    }
    lasti = -1; lastj = -1;
    for(int jj=0;jj<m;++jj) {
        lasti = -1; lastj = -1;
        int i = 0,j=jj;
        while(j >=0 && i < n) {
            if(tab[i][j] == 1) {
                if(lasti < 0) {
                    lasti = i;
                    lastj = j;
                }else {
                    if(abs(lasti - i) <= k) {
                        ans[lasti][lastj] = true;
                        ans[i][j] = true;
                    }

                    lasti = i;
                    lastj = j;
                }
            }

            --j;
            ++i;
        }
    }
    lasti = -1; lastj = -1;
    for(int ii=0;ii<n;++ii) {
        lasti = -1; lastj = -1;
        int j = m-1,i=ii;
        while(i < n && j >= 0) {
            if(tab[i][j] == 1) {
                if(lasti < 0) {
                    lasti = i;
                    lastj = j;
                }else {
                    if(abs(lastj - j) <= k) {
                        ans[lasti][lastj] = true;
                        ans[i][j] = true;
                    }

                    lasti = i;
                    lastj = j;
                }
            }

            --j;
            ++i;
        }
    }

    long cnt = 0 ;
    for(auto &x : ans) {
        for(auto y : x) if(y) ++cnt;
    }

    cout<<cnt<<endl;

return 0; }
