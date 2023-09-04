//define M
ll fact[M], invfact[M];

ll expo(ll x, ll p){
    x %= MOD;
    ll res = 1;
    if(p == -1) p = MOD-2;
    while(p){
        if(p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

void precalc(){ //run this first
    fact[0] = 1;
    for(int i=1; i<M; i++) fact[i] = i*fact[i-1] % MOD;
    invfact[M-1] = expo(fact[M-1], -1);
    for(int i=M-2; i>=0; i--) invfact[i] = (i+1)*invfact[i+1] % MOD;
}

ll nCr(int n, int r){
    if(r > n or r < 0) return 0LL;
    return (fact[n] * invfact[r] % MOD) * invfact[n-r] % MOD;
}  





