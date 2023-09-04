//define M
vector<int>g[M], topo;
int vis[M];

void dfs(int u){

    vis[u] = 1;

    for(int v : g[u]){
        if(vis[v] == 1){
            //cycle found, topological ordering doesn't exist
        }
        if(!vis[v]) dfs(v);
    }

    vis[u] = 2;
    topo.push_back(u);

}

void topo_sort(int n){

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
}
