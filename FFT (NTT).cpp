/*multiples two polynomials modulo MOD. Complexity : O(nlogn).
set G = primitive_root(), define N as a power of two greater than the size of any possible polynomial
*/

const int G = 3;
const int MOD = 998244353; 
const int N = 1<<17 + 5;

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

int rev[N], w[N], inv_n;

void prepare(int &n){
	int sz = abs(31 - __builtin_clz(n));
	int r = bigmod(G, (MOD-1)/n);
	inv_n = modinv(n), w[0] = w[n] = 1;
	for(int i=1; i<n; i++) w[i] = 1LL*w[i-1]*r % MOD;
	for(int i=1; i<n; i++) rev[i] = (rev[i>>1] >> 1) | ((i & 1) << (sz-1));
}

void ntt(int *a, int n, int dir){
	for(int i=1; i<n-1; i++){
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	}
	for(int m=2; m<=n; m<<=1){
		for(int i=0; i<n; i+=m){
			for(int j=0; j<(m>>1); j++){
				int &u = a[i+j], &v = a[i+j+(m>>1)];
				int t = 1LL * v * w[dir ? n - n/m * j : n/m * j] % MOD;
				v = u - t < 0 ? u - t + MOD : u - t;
				u = u + t >= MOD ? u + t - MOD : u + t;
			}
		}
	}
	if(dir) for(int i=0; i<n; i++) a[i] = 1LL * a[i] * inv_n % MOD;
}

int fa[N], fb[N];

vector<int>multiply(vector<int>a, vector<int>b){
	int sz = 1, n = a.size(), m = b.size();
	while(sz < n+m-1) sz <<= 1; prepare(sz);
	for(int i=0; i<sz; i++) fa[i] = i < n ? a[i] : 0;
	for(int i=0; i<sz; i++) fb[i] = i < m ? b[i] : 0;
	ntt(fa, sz, 0); ntt(fb, sz, 0);
	for(int i=0; i<sz; i++) fa[i] = 1LL * fa[i] * fb[i] % MOD;
	ntt(fa, sz, 1);
	return vector<int>(fa, fa+n+m-1);
}

//G = primitive_root()
int primitive_root(){
	vector<int>factor;
	int p = MOD;
	int tmp = p-1;
	for(int i=2; 1LL*i*i<=tmp; i++){
		if(tmp % i == 0){
			factor.emplace_back(i);
			while(tmp % i == 0) tmp /= i;
		}
	}
	if(tmp != -1) factor.emplace_back(tmp);
	for(int root=1;; root++){
		bool flag = true;
		for(int i=0; i<factor.size(); i++){
			if(bigmod(root, (p-1)/factor[i]) == 1){
				flag = false; break;
			}
		}
		if(flag) return root;
	}
}