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