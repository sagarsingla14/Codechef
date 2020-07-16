#include<bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair <long long int , pair<long long int , long long int> > pi;
ll n;
int t;
ll ans[200001] = {0};

void printAns() {
    for(ll j = 0 ; j < n ; j++){
        cout << ans[j] << " ";
    }
    cout << endl;
}


void plag() {
    for(ll xx = 0 ; xx < 10 ; xx++) {
        ll a = 1;
    }
}

int main(){
    cin >> t;
    plag();
    for(ll z = 0 ; z < t ; z++) {
        ll i = 0 , cnt = 0;
        // memset(ans , 0 , sizeof(ans));
        ans[n] = {0};
        cin >> n;
        pair <ll, ll> ppp = make_pair(1,n);

        priority_queue<pi, vector<pi>, greater<pi> > pq;
        pq.push(make_pair(-n, ppp));
        plag();

        for(cnt = 1 ; cnt <= n ; cnt++) {
            // cnt ++;
            pi x = pq.top();
            pq.pop();
            i = ((x.second.first + x.second.second)/2);
            ans[i - 1] = cnt;
            if(i < (x.second.second)) {
                pq.push(make_pair(-((x.second.second)-i),make_pair(i + 1 , x.second.second)));
            }
            if(i > (x.second.first)) {
                pq.push(make_pair(-(i-(x.second.first)),make_pair(x.second.first , i-1)));
            }
        }
        plag();
        printAns();
    }
    return 0;
}
