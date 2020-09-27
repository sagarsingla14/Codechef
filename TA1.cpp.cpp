int main() {
    fast_io
    ll n;
    cin >> n;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    cout << maxSubarrayXOR(arr , n) << endl;
}
