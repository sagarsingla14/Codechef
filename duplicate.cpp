#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

string str;
vector <ll> curAnswer;
ll t , power , invVal;
ll pos;
vector <ll> init{1 , 1 , 1 , 1};
ll dpAND[4][4] = {{0 , 0 , 0, 0} , {0 , 1 , 2 , 3} , {0 , 2 , 2 ,0} , { 0, 3 , 0 , 3}};
ll dpOR[4][4] = {{0 , 1, 2 , 3} , { 1 , 1, 1 , 1} ,{ 2 , 1 , 2 , 1} , { 3 , 1 , 1, 3}};
ll dpXOR[4][4] = {{0 , 1, 2 , 3} ,{1 ,0 , 3 , 2} , {2 , 3 , 0 ,1} , { 3 , 2 , 1, 0 }};
vector <ll> finalAnswer;

vector <ll> calcNew() {
    vector <ll> v(4);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    return v;
}

void solveXOR(vector <ll> left , vector <ll> right){
    curAnswer.clear();
    curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpXOR[i][j]] %= mod;
            curAnswer[dpXOR[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpXOR[i][j]] %= mod;
        }
    }
}

void solveAND(vector<ll> left , vector<ll> right){
    curAnswer.clear();
    curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpAND[i][j]] %= mod;
            curAnswer[dpAND[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpAND[i][j]] %= mod;
        }
    }
}

void solveOR(vector<ll> left , vector<ll> right){
    curAnswer.clear();
    curAnswer = calcNew();
    for(ll i = 0 ; i < 4 ; i++){
        for(ll j = 0 ; j < 4 ; j++){
            curAnswer[dpOR[i][j]] %= mod;
            curAnswer[dpOR[i][j]] += (left[i] * right[j]) % mod;
            curAnswer[dpOR[i][j]] %= mod;
        }
    }
}

vector <ll> calcRes() {
    if(str[pos] == '(') {
        pos ++;
        vector <ll> left = calcRes();
        char ch = str[pos];
        pos ++;
        vector <ll> right = calcRes();
        if(ch == '^') {
            solveXOR(left , right);
            pos ++;
            return curAnswer;
        }
        else if(ch == '|') {
            solveOR(left , right);
            pos ++;
            return curAnswer;
        }
        else{
            solveAND(left , right);
            pos ++;
            return curAnswer;
        }
    }
    if(str[pos] == '#'){
        pos ++;
        return init;
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

void printResult() {
    for(ll i = 0 ; i < 4 ; i++){
        finalAnswer[i] *= invVal;
        finalAnswer[i] %= mod;
        cout << finalAnswer[i] % mod << " ";
    }
    cout<<endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> str;
        power = 0;
        calcpower();
        invVal = 0;
        calcInv();
        pos = 0;
        finalAnswer = calcRes();
        printResult();
        finalAnswer.clear();
        pos = 0;
        invVal = 0;
        power = 0;
        str = "";
    }
    return 0;
}
