//z[i] is the length of the longest string which is a prefix of both s and s[i..n-1]
vector<int>z_function(string s){

    int n = s.size(), l = 0, r = 0;
    vector<int>z(n, 0);

    for(int i=1; i<n; i++){
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }

    return z;

}
