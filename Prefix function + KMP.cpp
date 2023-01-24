//pi[i] is the length of the longest proper prefix of s[0..i] which is also a suffix of s[0..i]
vector<int>prefix_function(string s){

    int n = s.size();
    vector<int>pi(n, 0);

    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 and s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;

}

void KMP(string t, string s){

    string str = s + '#' + t;

    int n = s.size(), ret = 0;

    vector<int>pi = prefix_function(str);

    for(int i=n+1; i<str.size(); i++){
        if(pi[i] == n){
            //match found at position [i-2*n, i-n)
        }
    }


}
