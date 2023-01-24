//define M

struct LinearSystem{
	int m, n = 0;
	double a[M][M];
	double ans[M];
	LinearSystem(int m) : m(m){};
	void insertEquation(vector<double>c){
		for(int i=0; i<=m; i++) a[n][i] = c[i];
		n++; 
	}
	int gauss(){
		int r = 0;
		for(int c=0; c<m and r<n; c++){
			int j = r;
			for(int i=r+1; i<n; i++){
				if(fabs(a[i][c]) > fabs(a[j][c])) j = i;
			}
			if(fabs(a[j][c]) < EPS) continue;
			swap(a[j], a[r]);
			double s = 1.0/a[r][c];
			for(int i=0; i<=m; i++) a[r][i] *= s;
			for(int i=0; i<n; i++){
				if(i != r){
					double t = a[i][c];
					for(int j=0; j<=m; j++) a[i][j] -= t*a[r][j];
				}
			}
			r++;
		}
		return r;
	}
};