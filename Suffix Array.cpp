/* stores all suffixes of a string in lexicographical order.
longest common prefix of suf[i] and suf[j] = LCP(i, i+1, ... j-1).
Construction complexity : O(nlogn) */
vector<int>sort_cyclic_shifts(const string &s){
    const int alphabet = 256;
    int n = s.size();

    vector<int>p(n), c(n), cnt(max(alphabet, n), 0);

    for(int i=0; i<n; i++) cnt[s[i]]++;
    for(int i=1; i<alphabet; i++) cnt[i] += cnt[i-1];
    for(int i=0; i<n; i++){
        p[--cnt[s[i]]] = i;
    }

    c[p[0]] = 0;
    int classes = 1;
    for(int i=1; i<n; i++){
        if(s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes - 1;
    }

    vector<int>pn(n), cn(n);
    for(int h=0; (1<<h)<n; h++){
        for(int i=0; i<n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) pn[i] += n;
        }
        for(int i=0; i<classes; i++) cnt[i] = 0;
        for(int i=0; i<n; i++) cnt[c[pn[i]]]++;
        for(int i=1; i<classes; i++) cnt[i] += cnt[i-1];

        for(int i=n-1; i>=0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for(int i=1; i<n; i++){
            pii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pii prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if(cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;

}

vector<int>suffix_array(string s){
    s += "$";
    vector<int>sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int>get_lcp(string const&s, vector<int>const& p){
    int n = s.size();
    vector<int>Rank(n, 0);
    for(int i=0; i<n; i++){
        Rank[p[i]] = i;
    }
    int k = 0;
    vector<int>lcp(n-1, 0);
    for(int i=0; i<n; i++){
        if(Rank[i] == n-1){
            k = 0;
            continue;
        }
        int j = p[Rank[i] + 1];
        while(i+k<n and j+k<n and s[i+k] == s[j+k]) k++;
        lcp[Rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}