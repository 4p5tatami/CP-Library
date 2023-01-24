//define M
vector<int>g[M];

int diameter(){

    int mx = 0, node;

    function<void(int, int, int)>dfs = [&](int u, int p, int h){
        if(h >= mx){
            mx = h;
            node = u;
        }
        for(int x : g[u]){
            if(x != p) dfs(x, u, h+1);
        }
    };

    dfs(1, -1, 0);
    mx = 0;
    dfs(node, -1, 0);
    return mx;

}
