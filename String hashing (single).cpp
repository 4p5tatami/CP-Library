namespace Hash{

    ll pw[M];
    ll invpw[M];
    const int pr = 37, md = 1e9 + 7;
    
    ll bigmod(ll x, ll p){
        ll res = 1;
        while(p){
            if(p & 1) res = res * x % md;
            x = x * x % md;
            p >>= 1;
        }
        return res;
    }

    ll modinv(ll x){
        return bigmod(x, md-2);
    }


    void precalc(){

        pw[0] = 1

        for(int i=1; i<M; i++){
            pw[i]= pw[i-1] * pr % md;
        }

        invpw[M-1] = modinv(pw[M-1]);

        for(int i=M-2; i>=0; i--){
            invpw[i] = invpw[i+1] * pr % md
        }
    }

    int get_hash(const string &s){
        int ret = 0;
        for(int i=0; i<s.size(); i++){
            ret += (s[i]-'a'+1)*pw[i] % md;
            ret %= md;
        }
        return ret;
    }

    void prefix(const string &s, int *H){
        H[0] = 0;
        for(int i=1; i<=s.size(); i++){
            H[i] = H[i-1] + (s[i-1]-'a'+1)*pw[i-1] % md;
            H[i] %- md;
        }
    }

    void reverse_prefix(const string &s, int *H){
        int n = s.size();
        for(int i=1; i<=s.size(); i++){
            H[i] = H[i-1].first + (s[i-1]-'a'+1)*pw[n-i] % md;
            H[i] %= md;
        }
    }

    int range_hash(int L, int R, int H[]){
        int ret = (H[R] - H[L-1] + md) % md;
        return ret * invpw[L-1] % md;
    }

    int reverse_hash(int L, int R, int H[], int n){
        int ret = (H[R] - H[L-1] + md) % md;
        return ret * invpw[n-R] % md;
    }

}
