const ll INF = 1e18;
//define M and INF
vector<pll>g[M];
ll d[M]; //initialize with INF

void dijkstra(int src){

    fill(begin(d), end(d), INF);
    d[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto [cst, u] = pq.top();
        pq.pop();
        if(d[u] != cst) continue;
        for(auto [v, weight] : g[u]){
            if(d[v] > d[u] + weight){
                d[v] = d[u] + weight;
                pq.emplace(d[v], v);
            }
        }
    }

}
