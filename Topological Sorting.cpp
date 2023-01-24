//define M
vector<int>g[M], topo;
int vis[M];

void dfs(int u){

    vis[u] = 1;

    for(int x : g[u]){
        if(vis[x] == 1){
            //cycle found, topological ordering doesn't exist
        }
        if(!vis[x]) dfs(x);
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
