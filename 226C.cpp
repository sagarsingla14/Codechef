#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi_mere_bina ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll l , r , n;
ll arr[1000001];
vector <ll> primeSum;
unordered_map <ll , ll> mp;
ll prime[10000001];
bool isPrime[10000001];
vector <ll> primeNumbers;
vector <ll> dp;
ll ans = 0;

void sieve() {
    for(ll i = 2 ; i * i <= 10000000 ; i++) {
        if(isPrime[i]) {
            prime[i] = i;
            for(ll j = i * i ; j <= 10000000 ; j += i) {
                prime[j] = i;
                isPrime[j] = false;
            }
        }
    }
}

void calcFactor(ll val) {
    set <ll> s;
    while(val > 1) {
        ll fac = prime[val];
        s.insert(fac);
        val /= fac;
    }
    for(auto i : s) {
        mp[i] ++;
    }
}

void fillFactors() {
    for(ll i = 0 ; i < n ; i ++) {
        ll val = arr[i];
        calcFactor(val);
    }
}

void fillPrime() {
    for(ll i = 2 ; i < 10000001 ; i++) {
        if(isPrime[i]) {
            primeNumbers.push_back(i);
            prime[i] = i;
        }
    }
}

void setDp() {
    for(ll i = 1 ; i < dp.size() ; i++) {
        dp[i] += dp[i - 1];
    }
}

void fillDP() {
    for(auto i : primeNumbers) {
        ll cnt = mp[i];
        dp.push_back(cnt);
    }
    setDp();
}


ll findLeftIndex() {
    auto left = lower_bound(primeNumbers.begin() , primeNumbers.end() , l) - primeNumbers.begin();
    return left - 1;
}

ll findRightIndex() {
    auto right = lower_bound(primeNumbers.begin() , primeNumbers.end() , r) - primeNumbers.begin();
    if(isPrime[r]) {
        return right;
    }
    else{
        return right - 1;
    }
}

void findAns() {
    ll leftIndex = findLeftIndex();
    ll rightIndex = findRightIndex();
    if(leftIndex == -1) {
        ans = dp[rightIndex];
    }
    else {
        ans = dp[rightIndex] - dp[leftIndex];
    }
    cout << ans << endl;
}


int main() {
    train_choot_jayegi_mere_bina
    memset(isPrime , true , sizeof(isPrime));
    sieve();
    fillPrime();

    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    fillFactors();
    fillDP();
    ll q;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        if(l >= 1e7) {
            l = 1e7;
        }
        if(r >= 1e7) {
            r = 1e7;
        }
        findAns();
    }
    return 0;
}
