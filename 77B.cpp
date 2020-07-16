
ll ok;
unordered_map <ll , ll> mask;
unordered_map <ll , ll> endmask;
vector <ll> v;
string num;
ll digits , n;
ll lucky = 0;

void convertToInt() {
    lucky = 0;
    for(auto i : num) {
        lucky *= 10;
        lucky += (i - '0');
    }
}

void setMask() {
    mask[1] = 47;
    mask[2] = 47;
    mask[3] = 4477;
    mask[4] = 4477;
    mask[5] = 444777;
    mask[6] = 444777;
    mask[7] = 44447777;
    mask[8] = 44447777;
    mask[9] = 4444477777;
    mask[10] = 4444477777;
    mask[11] = 4444477777;

    endmask[1] = 74;
    endmask[2] = 74;
    endmask[3] = 7744;
    endmask[4] = 7744;
    endmask[5] = 777444;
    endmask[6] = 777444;
    endmask[7] = 77774444;
    endmask[8] = 77774444;
    endmask[9] = 7777744444;
    endmask[10] = 7777744444;
    endmask[11] = 7777744444;
}

ll countDigits(ll n) {
    ll cnt = 0;
    while(n) {
        ll d = n % 10;
        n /= 10;
        v.push_back(d);
        cnt ++;
    }
    return cnt;
}

void beyondLimits() {
    reverse(v.begin() , v.end());
    ll f = digits / 2;
    ll s = digits / 2;
    ll present = 0;
    num = "";
    for(auto i : v) {
        if(i <= 4) {
            if(f > 0) {
                num += '4';
                f --;
                present = 1;
            }
            else{
                num += '7';
                s --;
            }
        }
        else{
            if(i > 7 && !present) {
                ok = 0;
                num += '7';
                s --;
            }
            else{
                if(s > 0) {
                    num += '7';
                    s--;
                }
                else{
                    num += '4';
                    f --;
                }
            }
        }
    }
}

void checkProper(ll x) {
    ll s = 0 , f = 0;
    while(x) {
        ll d = x % 10;
        x /= 10;
        if(d == 4) {
            f ++;
        }
        if(d == 7) {
            s ++;
        }
    }

    if(s == f && (digits / 2) == s) {
        ok = 1;
    }
}

int main() {
    fast
    cin >> n;
    setMask();
    digits = countDigits(n);
    if(digits & 1 || digits >= 9) {
        digits ++;
        cout << mask[digits] << endl;
    }
    else{
        ll right = endmask[digits];
        if(n > right) {
            cout << mask[digits + 1] << endl;
            return 0;
        }

        ok = 1;
        beyondLimits();
        convertToInt();

        if(!ok) {
            cout << mask[digits + 2] << endl;
        }
        else{
            ll s = 0, f = 0;
            for(auto i : v) {
                if(i == 4) {
                    f ++;
                }
                if(i == 7) {
                    s ++;
                }
            }
            if(s == f && (digits / 2) == s) {
                cout << n << endl;
                return 0;
            }
            ok = 0;
            ll check = 0;
            for(ll i = n ; i <= endmask[digits] ; i ++) {
                if(i >= n) {
                    checkProper(i);
                    if(ok) {
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
