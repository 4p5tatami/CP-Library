//Complexity : O(n+m)
struct _2SAT{

    vector<vector<int>>g, gt;
    vector<bool>vis;
    vector<int>order, comp;
    vector<bool>val;
    int n;

    _2SAT(){};

    _2SAT(int sz){
        n = 2*sz+1;
        g.assign(n+1, {});
        gt.assign(n+1, {});
    }

    void add_edge(int u, int v){
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    void add_OR(int a, int b){
        a <<= 1, b <<= 1;
        add_edge(a^1, b);
        add_edge(b^1, a);
    }
    
    void add_AND(int a, int b){
        a <<= 1, b <<= 1;
        add_edge(a, b);
        add_edge(b, a);
    }

    void add_XOR(int a, int b){
        a <<= 1, b <<= 1;
        add_edge(a^1, b);
        add_edge(b^1, a);
        add_edge(a, b^1);
        add_edge(b, a^1);
    }

    void add_XNOR(int a, int b){
        a <<= 1, b <<= 1;
        add_edge(a, b);
        add_edge(b, a);
        add_edge(a^1, b^1);
        add_edge(b^1, a^1);
    }

    void dfs(int u){
        vis[u] = 1;
        for(int v : g[u]){
            if(!vis[v]) dfs(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int cur){
        comp[u] = cur;
        for(int v : gt[u]){
            if(!comp[v]) dfs2(v, cur);
        }
    }

    bool solve(){
        vis.assign(n+1, false);

        for(int i=2; i<=n; i++){
            if(!vis[i]) dfs(i);
        }

        reverse(order.begin(), order.end());
        comp.assign(n+1, 0);
        int c = 0;

        for(int x : order){
            if(!comp[x]) dfs2(x, ++c);
        }
        val.assign(n/2 + 1, false);
        for(int i=1; i<=n/2; i++){
            if(comp[2*i] == comp[2*i+1]) return false;
            val[i] = comp[2*i] > comp[2*i+1];
        }
        return true;

    }

};