const int MOD = 1e9 + 7;

ll bigmod(ll x, ll p){
    x %= MOD;
    ll res = 1;
    while(p){
        if(p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

ll modinv(ll x){
    return bigmod(x, MOD-2);
}

