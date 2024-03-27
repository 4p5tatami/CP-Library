struct edge{
    int from, to;
    ll capacity, cost;
};
 
vector<vector<int>>adj;
vector<vector<ll>>cost, capacity;
 
void SPFA(int n, int v0, vector<ll>&d, vector<int>&p){
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool>inq(n, false);
    queue<int>q;
    q.push(v0);
    p.assign(n, -1);
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int v : adj[u]){
            if(capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]){
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if(!inq[v]){
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
 
ll min_cost_flow(int N, vector<edge>edges, ll F, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<ll>(N, 0));
    capacity.assign(N, vector<ll>(N, 0));
    for(edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
 
    ll flow = 0, cost = 0;
    vector<ll>d;
    vector<int>p;
    while(flow < F){
        SPFA(N, s, d, p);
        if(d[t] == INF) break;
        // find max flow on that path
        ll f = F - flow;
        int cur = t;
        while(cur != s){
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
 
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while(cur != s){
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
 
    if(flow < F) return -1;
    else return cost;
}