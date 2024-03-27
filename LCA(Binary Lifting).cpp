//define M and K >= log2(n)

namespace LCA{
    int d[M], up[M][K];
    int tin[M], tout[M], timer;

    void dfs(int u, int par, int h=0){

        up[u][0] = par;
        d[u] = h;
        tin[u] = ++timer;


        for(int i=1; i<K; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }

        for(int v : g[u]){
            if(v != par) dfs(v, u, h+1);
        }

        tout[u] = ++timer;

    }

    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    }


    int LCA(int u, int v){

        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;

        for(int i=K-1; i>=0; i--){
            if(!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }

    int dist(int u, int v){
        return d[u] + d[v] - 2*d[LCA(u, v)];
    }


    void preprocess(int root, int n){ //run this first
        for(int i=0; i<=n; i++){
            d[i] = tin[i] = tout[i] = 0;
            memset(up[i], sizeof up[i], 0);
        }
        timer = 0;
        dfs(root, root);
    }
}

