//define M. processes a subtree as a range [L, R] in a linear array
vector<int>g[M];
int tin[M], tout[M], timer;
vector<int>times(1, 0);
vector<int>order(1, 0);

void dfs(int u, int p=0){ //run this first

    tin[u] = ++timer;
    times.push_back(tin[u]);
    order.push_back(u);

    for(int x : g[u]){
        if(x != p){
            dfs(x, u);
        }
    }

    tout[u] = ++timer;


}

pii subtreeRange(int u){

    int L = lower_bound(times.begin(), times.end(), tin[u]) - times.begin();
    int R = lower_bound(times.begin(), times.end(), tout[u]) - times.begin();
    return {L, R-1};

}