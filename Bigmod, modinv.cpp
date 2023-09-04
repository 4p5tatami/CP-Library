const int MOD = 1e9 + 7;

ll expo(ll x, ll p){
    x %= MOD;
    if(p == -1) p = MOD-2;
    ll res = 1;
    while(p){
        if(p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

