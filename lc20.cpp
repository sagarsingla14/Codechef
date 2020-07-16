#define ll long long int

ll p = 31;
ll mod = 1e9 + 7;

ll p = 37;
ll mod = 1e9 + 9;

string longestDupSubstring(string str) {
    ll n = str.length();

    ll h[n + 1];
    ll power[n + 1];

    ll h1[n + 1];
    ll power1[n + 1];

    power[0] = 1;
    power1[0] = 1;


    for(ll i = 1 ; i < n ; i++) {
        power[i] = power[i - 1] % mod * p;
        power1[i] = power1[i - 1] % mod1 * p1;

        power[i] %= mod;
        power1[i] %= mod1;
    }

    for(ll i = 0 ; i < n ; i++) {
        h[i + 1] = h[i] % mod + ((str[i] - 'a' + 1) % mod) * (power[i] % mod);
        h[i + 1] %= mod;

        h1[i + 1] = h1[i] % mod1 + ((str[i] - 'a' + 1) % mod1) * (power1[i] % mod1);
        h1[i + 1] %= mod1;
    }

    ll found = 0;
    ll ans = 0 , index = 0;
    ll f = 1 , l = n - 1;

    while(f <= l) {
        ll mid = (f + l) / 2;
        mp <ll , ll> mp;
        ll ok = 0;

        for(ll i = 0 ; i <= n - mid ; i++) {
            ll curHash = (h[i + mid] - h[i] + mod) % mod;
            curHash *= ((power[n - i - 1]) % mod);
            curHash %= mod;

            ll curHash1 = (h1[i + mid] - h1[i] + mod1) % mod1;
            curHash1 *= ((power1[n - i - 1]) % mod1);
            curHash1 %= mod1;

            if(mp[{curHash , curHash1}]) {
                index = i;
                ans = mid;
                ok = 1;
                break;
            }
            else {
                mp[{curHash , curHash1}] ++;
            }
        }

        if(ok) {
            f = mid + 1;
        }
        else{
            l = mid - 1;
        }
    }

    string s = "";
    for(ll i = index ; i < index + ans ; i++) {
        s += str[i];
    }
    return s;
}
