struct mint{
  int value;
  static const int MOD_value = MOD;

  mint(long long v = 0){ value = v % MOD; if(value < 0) value += MOD;}
  mint(long long a, long long b) : value(0){ *this += a; *this /= b;}

  mint& operator+=(mint const& b){value += b.value; if (value >= MOD) value -= MOD; return *this;}
  mint& operator-=(mint const& b){value -= b.value; if (value < 0) value += MOD;return *this;}
  mint& operator*=(mint const& b){value = (long long)value * b.value % MOD;return *this;}

  friend mint expo(mint a, long long e){
    mint res = 1; while (e){ if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend mint inverse(mint a){ return expo(a, MOD - 2); }

  mint& operator/=(mint const& b){ return *this *= inverse(b); }
  friend mint operator+(mint a, mint const b){ return a += b; }
  friend mint operator-(mint a, mint const b){ return a -= b; }
  friend mint operator-(mint const a){ return 0 - a; }
  friend mint operator*(mint a, mint const b){ return a *= b; }
  friend mint operator/(mint a, mint const b){ return a /= b; }
  friend istream& operator>>(istream& is, mint& a){ return is >> a.value;}
  friend ostream& operator<<(ostream& os, mint const& a){ return os << a.value;}
  friend bool operator==(mint const& a, mint const& b){ return a.value == b.value;}
  friend bool operator!=(mint const& a, mint const& b){ return a.value != b.value;}
};

mint expo(ll a, long long e){
    return expo((mint)a, e);
}

mint fact[M], invfact[M];

void precalc(){ //run this first
    fact[0] = 1;
    for(int i=1; i<M; i++) fact[i] = i*fact[i-1];
    invfact[M-1] = 1/fact[M-1];
    for(int i=M-2; i>=0; i--) invfact[i] = (i+1)*invfact[i+1];
}

mint nCr(int n, int r){
    if(r > n or r < 0) return 0;
    return fact[n] * invfact[r] * invfact[n-r];
}  