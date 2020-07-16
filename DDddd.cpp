#include <bits/stdc++.h>
#define ll long long
typedef pair <long long , pair <long long ,long long > > pi;
using namespace std;
ll n , t;
ll ans[100001] = {0};

int main(){
    cin >> t;
    while(t--) {
        memset(ans , 0 , sizeof(ans));
        cin >> n;
        ll i = 0 , k = 1;
        priority_queue <pi , vector<pi>, greater<pi> >pq;
        pq.push(make_pair(-n , {1 , n}));
        ll ans[n] = {0};

        while(!q.empty() && k<=n){
            pi x=q.top();
            //cout<<(x.first)<<" "<<(x.second.first)<<" - "<<(x.second.second)<<endl;
            q.pop();
            i=((x.second.first+x.second.second)/2);
            ans[i-1]=k;
            if(i>(x.second.first))
                q.push(make_pair(-(i-(x.second.first)),make_pair(x.second.first,i-1)));
            if(i<(x.second.second))
                q.push(make_pair(-((x.second.second)-i),make_pair(i+1,x.second.second)));
            k++;
        }
        for(int j=0;j<n;j++){
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
}
