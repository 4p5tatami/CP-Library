//define M and INF
vector<pll>g[M];
ll dist[M]; //initialize with INF

void dijkstra(int src){

    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto [cst, u] = pq.top();
        pq.pop();
        if(dist[u] != cst) continue;
        for(auto [v, weight] : g[u]){
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

}
