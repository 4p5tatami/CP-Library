//define M

int par[M], sz[M];

void init(int n){ //run this
    for(int i=1; i<=n; i++) par[i] = i, sz[i] = 1;
}

int Find(int u){
    if(u == par[u]) return u;
    return par[u] = Find(par[u]);
}

void Union(int u, int v){

    u = Find(u), v = Find(v);

    if(u != v){
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }

}