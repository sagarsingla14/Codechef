#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353
string str;
ll t , power , invVal;

ll dpAND[4][4] = {{0 , 0 , 0, 0} , {0 , 1 , 2 , 3} , {0 , 2 , 2 ,0} , { 0, 3 , 0 , 3}};
ll dpOR[4][4] = {{0 , 1, 2 , 3} , { 1 , 1, 1 , 1} ,{ 2 , 1 , 2 , 1} , { 3 , 1 , 1, 3}};
ll dpXOR[4][4] = {{0 , 1, 2 , 3} ,{1 ,0 , 3 , 2} , {2 , 3 , 0 ,1} , { 3 , 2 , 1, 0 }};


vector <ll> calcNew() {
    vector <ll> v(4);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    return v;
}

vector <ll> solveXOR(vector <ll> left , vector <ll> right){
    vector <ll> curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpXOR[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpXOR[i][j]] %= mod;
        }
    }
    return curAnswer;
}

vector <ll> solveAND(vector<ll> left , vector<ll> right){

    vector <ll> curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpAND[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpAND[i][j]] %= mod;
        }
    }
    return curAnswer;
}

vector <ll> solveOR(vector<ll> left , vector<ll> right){

    vector <ll> curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpOR[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpOR[i][j]] %= mod;
        }
    }
    return curAnswer;
}

pair <ll , vector<ll> > calcRes(ll pos){
    vector <ll> a{1 , 1 , 1 , 1};
    if(str[pos] == '#'){
        return make_pair(pos + 1, a);
    }
    if(str[pos] == '('){
        pair <ll , vector<ll> > left = calcRes(pos + 1);
        pos = left.first;
        char ch = str[pos];
        pair <ll , vector<ll> > right = calcRes(pos + 1);
        pos = right.first;
        if(ch == '^') {
            vector <ll> ansXor = solveXOR(left.second , right.second);
            return make_pair(pos + 1 , ansXor);
        }
        else if(ch == '|') {
            vector <ll> ansOr  = solveOR(left.second , right.second);
            return make_pair(pos + 1 , ansOr);
        }
        else{
            vector <ll> ansAnd = solveAND(left.second , right.second);
            return make_pair(pos + 1 , ansAnd);
        }
    }
}


void calcpower() {
    for(auto i : str){
        if(i == '&' || i == '^' ||  i == '|'){
            power ++;
        }
    }
}

ll modInverse(ll a , ll x) {
	if(x == 0) {
        return 1;
    }
	if(x % 2 == 1) {
        ll val = (a * modInverse(a , x - 1)) % mod;
        return val;
    }
	ll inv = modInverse(a , x >> 1);
    inv %= mod;
	return (inv * inv) % mod;
}

void calcInv() {
    invVal = modInverse(4 , mod - power - 2);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> str;
        power = 0;
        calcpower();
        invVal = 0;
        calcInv();
        pair <ll , vector<ll> > finalAnswer = calcRes(0);

        for(ll i = 0 ; i < 4 ; i++){
            ll val = (finalAnswer.second[i] * invVal);
            val %= mod;
            cout << val % mod << " ";
        }
        cout<<endl;
    }
    return 0;
}
