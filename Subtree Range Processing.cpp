//define M. processes a subtree as a range [L, R] in a linear array
int tin[M], tout[M], timer;
vector<int>times(1, 0);
vector<int>order(1, 0);
int pos[M];

void dfs(int u, int par=0){

    tin[u] = ++timer;
    pos[u] = order.size();
    times.push_back(tin[u]);
    order.push_back(u);

    for(int v : g[u]){
        if(v != par){
            dfs(v, u);
        }
    }

    tout[u] = ++timer;
}

void preprocess(int root, int n){ //run this first
    for(int i=0; i<=n; i++) tin[i] = tout[i] = pos[i] = 0;
    times.assign(1, 0);
    order.assign(1, 0);
    dfs(root);
}

pii subtreeRange(int u){

    int L = lower_bound(times.begin(), times.end(), tin[u]) - times.begin();
    int R = lower_bound(times.begin(), times.end(), tout[u]) - times.begin();
    return {L, R-1};

}