/*
Single source shortest path. Including negative cycles.
Distance of vertices in negative cycles are set as -INF.
Complexity : O(nm)
*/

const int M = 1e3 + 3, INF = 2e9;

struct edge{
    int u, v, w;
};

edge e[M];
int d[M], p[M], vis[M];
vector<int>g[M];

void dfs(int u){

    d[u] = -INF;
    vis[u] = 1;

    for(int x : g[u]){
        if(!vis[x]) dfs(x);
    }
}

void bellman_ford(int strt, int n, int m){

    fill(begin(d), end(d), INF);

    d[strt] = 0;
    int x = -1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[e[j].u] < INF and d[e[j].v] > d[e[j].u] + e[j].w){
                d[e[j].v] = d[e[j].u] + e[j].w;
                p[e[j].v] = e[j].u;
                if(i == n-1) x = e[j].v;
            }
        }
    }

    if(x != -1){
        //negative cycle found
        for(int i=0; i<n; i++) x = p[x];
        dfs(x);
    }

}
