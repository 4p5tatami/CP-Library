// Complexity : O(n^3 log p). define M and MOD
const int M = 103;
const int MOD = 998244353;

struct matrix{
    int mat[M][M];
    int n, m;
    matrix(){};
    matrix(int _n, int _m=0) : n(_n), m(_m){
        if(!m) m = n;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[i][j] = 0;
            }
        }
    }
    matrix operator *(const matrix &mul){
        int p = n, q = mul.n, r = mul.m;
        matrix ret(p, r);
        for(int i=0; i<p; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<q; k++){
                    ret.mat[i][j] += 1LL * mat[i][k] * mul.mat[k][j] % MOD;
                    ret.mat[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    
};

matrix expo(matrix m, ll p){
    int n = m.n;
    matrix ret = matrix(n);
    for(int i=0; i<n; i++) ret.mat[i][i] = 1;
    while(p){
        if(p & 1) ret = ret * m;
        m = m * m;
        p >>= 1;
    }
    return ret;
}
