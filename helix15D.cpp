#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll tree[400000] = {0};
ll arr[400000] = {0};

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
            res %= mod;
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1ll;
    }
    return res % mod;
}

ll lcm(ll a, ll b) {
    return ((((a % mod) * (b % mod)) % mod) * (power(__gcd(a,b) , mod - 2) % mod)) % mod;
    return (a % mod) * ((b % mod) * power(__gcd(a,b) , mod - 2);
}

void build(ll node, ll start, ll end)
{
    if (start==end)
    {
        tree[node] = arr[start];
        return;
    }

    ll mid = (start+end)/2;

    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    ll left_lcm = tree[2*node];
    ll right_lcm = tree[2*node+1];

    tree[node] = lcm(left_lcm , right_lcm);
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (end<l || start>r)
        return 1;

    if (l <= start && r >= end)
        return tree[node];

    ll mid = (start+end)/2;
    ll left_lcm = query(2*node , start, mid, l, r);
    ll right_lcm = query(2*node + 1 , mid+1 , end , l , r);
    return lcm(left_lcm, right_lcm) % mod;
}

int main()
{
    ll n , q;
    cin >> n >> q;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    // build(1 , 0 , n - 1);

    while(q--) {
        ll l ,r ;
        cin >> l >> r;
        l -- , r --;

        ll lcm = arr[l];
        for(ll i = l + 1 ; i <= r ; i++) {
            // ll g = __gcd(arr[i] , lcm);
            // lcm = (lcm % mod) * (arr[i] % mod * (power(g , mod - 2)) % mod) % mod) % mod;

            lcm = ((((lcm % mod) * (arr[i] % mod)) % mod) * (power( __gcd(arr[i] , lcm) , mod - 2) % mod)) % mod;
        }
        cout << lcm << endl;
        // cout << query(1 , 0, n - 1 , l , r) % mod << endl;
    }

    return 0;
}
