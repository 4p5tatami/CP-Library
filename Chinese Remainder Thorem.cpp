ll mul_inv(ll a, ll b) {

	ll b0 = b;
	ll x0 = 0;
	ll x1 = 1;

	if(b == 1) return 1;

	while(a > 1){
		ll q = a / b;
		ll amb = a % b;
		a = b;
		b = amb;

		ll xqx = x1 - q * x0;
		x1 = x0;
		x0 = xqx;
	}

	if(x1 < 0){
		x1 += b0;
	}

	return x1;
}

ll CRT(vector<ll>a, vector<ll>r){

	ll prod = accumulate(a.begin(), a.end(), 1LL, multiplies<ll>());

	ll res = 0;
	for (int i=0; i<a.size(); i++){
		ll p = prod / a[i];
		res += r[i] * mul_inv(p, a[i]) * p;
	}

	return res % prod;
}