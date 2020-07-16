#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
    ll b , l , d;
    cin >> b >> l >> d;

    // book score || book number
    ll s[b] = {0};
    for(ll i = 0 ; i < b ; i++) {
        cin >> s[i];
    }
    vector <pair <ll , ll> > bookscore;
    for(ll i = 0 ; i < b ; i++) {
        bookscore.push_back(make_pair(s[i] , i));
    }
    sort(bookscore.begin() , bookscore.end());

    vector <ll> library[l];

    vector <pair <ll,ll> > signup;
    // signup time || library number
    for (ll i = 0 ; i < l ; i++) {
        ll n , t , m;
        cin >> n >> t >> m;
        signup.push_back(make_pair(t , i));
        library[i].push_back(t);
        library[i].push_back(m);
        for(ll j = 0 ; j < n ; j++) {
            ll x;
            cin >> x;
            library[i].push_back(x);
        }
    }

    sort(signup.begin() , signup.end());
    // cout << 1 << " " << endl;

    vector <ll> arr[l];
    for (ll i = 0 ; i < signup.size(); i++) {
        ll librarynum = signup[i].second;
        ll librarytime = signup[i].first;
        for(ll j = 0 ; j < library[librarynum].size() ; j++) {
            arr[i].push_back(library[librarynum][j]);
        }
    }

    ll days[d] = {0};
    for(ll i = 0 ; i < d ; i++) {
        days[i] = -1;
    }

    ll currentday = 0;
    ll outa = 0;
    for(ll i = 0 ; i < l ; i++) {
        if(i == 0) {
            currentday = arr[0][0] - 1;
        }
        else {
            currentday += arr[i][0];
        }
        if(currentday >= d) {
            break;
        }
        days[currentday] = i;
        outa ++;
    }

    vector <ll> ans[outa];
    ll aa = 0;
    for(ll i = 0 ; i < d ; i++) {
        if(days[i] != -1) {
            ll librarynum = days[i];
            ll sze = arr[librarynum].size();
            vector <pair <ll , ll> > bookid;
            for(ll j = 2 ; j < sze ; j++) {
                bookid.push_back(make_pair(s[arr[librarynum][j]] , arr[librarynum][j]));
            }
            sort(bookid.begin() , bookid.end()) ;
            ans[aa].push_back(librarynum);
            ll index = i + 1;
            ll bookidindex = 0;
            while (index < d && bookidindex < bookid.size()) {
                for(ll z = 0 ; z < arr[librarynum][1] ; z++) {
                    if(bookidindex >= bookid.size() ) {
                        break;
                    }
                    ans[aa].push_back(bookid[bookidindex].second);
                    bookidindex ++;
                }
                index ++;
            }
            aa++;
        }
    }

    cout << outa << endl;
    for(ll i = 0 ; i < outa ; i++) {
        cout << ans[i][0] << " " << ans[i].size() - 1 << endl;

        for(ll j = 1 ; j < ans[i].size() ; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
