//define M
ll fact[M], invfact[M];

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

void precalc(){ //run this first
    fact[0] = 1;
    for(int i=1; i<M; i++) fact[i] = i*fact[i-1] % MOD;
    invfact[M-1] = modinv(fact[M-1]);
    for(int i=M-2; i>=0; i--) invfact[i] = (i+1)*invfact[i+1] % MOD;
}

ll nCr(int n, int r){
    if(r > n or r < 0) return 0LL;
    return (fact[n] * invfact[r] % MOD) * invfact[n-r] % MOD;
}  





