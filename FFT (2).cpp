using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd>&a, bool inv){
	int n = a.size();
	for(int i=1, j=0; i<n; i++){
		int bit = n>>1;
		for(; j&bit; bit>>=1) j ^= bit;
		j ^= bit;
		if(i<j) swap(a[i], a[j]);
	}
	for(int len=2; len<=n; len<<=1){
		double ang = 2*PI/len*(inv ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(int i=0; i<n; i+=len){
			cd w(1);
			for(int j=0; j<len/2; j++){
				cd u = a[i+j], v = a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w *= wlen;
			}
		}
	}
	if(inv){
		for(cd &x : a) x /= n;
	}
}
 
vector<int>multiply(vector<int>a, vector<int>b){
	vector<cd>fa(a.begin(), a.end()), fb(b.begin(),  b.end());
	int n = 1;
	while(n < a.size() + b.size()) n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, 0);
	fft(fb, 0);
	for(int i=0; i<n; i++) fa[i] *= fb[i];
	fft(fa, 1);
	vector<int>res(n, 0);
	for(int i=0; i<n; i++) res[i] = round(fa[i].real());
	for(int &x : res) if(x) x = 1;
	return res;
}