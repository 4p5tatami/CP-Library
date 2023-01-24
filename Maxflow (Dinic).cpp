// Complexity : O(V^2 * E), O(E*sqrt(V)) for unit flow networks

struct FlowEdge{
	int u, v;
	ll cap, flow = 0;
	FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap){}
};
 
struct Dinic{
	vector<FlowEdge>edges;
	vector<vector<int>>adj;
	int n, m = 0;
	int s, t;
	vector<int>lv, ptr;
	queue<int>q;
 
	Dinic(int n, int s, int t) : n(n), s(s), t(t){
		adj.resize(n+1);
		lv.resize(n+1);
		ptr.resize(n+1);
	}
 
	void add_edge(int u, int v, ll cap){
		edges.emplace_back(u, v, cap);
		edges.emplace_back(v, u, 0);
		adj[u].push_back(m);
		adj[v].push_back(m+1);
		m += 2;
	}
 
	bool bfs(){
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int id : adj[u]){
				if(edges[id].cap - edges[id].flow < 1) continue;
				if(lv[edges[id].v] != -1) continue;
				lv[edges[id].v] = lv[u] + 1;
				q.push(edges[id].v);
			}
		}
		return lv[t] != -1;
	}
 
	ll dfs(int u, ll pushed){
		if(pushed == 0) return 0;
		if(u == t) return pushed;
		for(int &cid=ptr[u]; cid<(int)adj[u].size(); cid++){
			int id = adj[u][cid];
			int v = edges[id].v;
			if(lv[u] + 1 != lv[v] or edges[id].cap - edges[id].flow < 1) continue;
			ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
			if(tr == 0) continue;
			edges[id].flow += tr;
			edges[id^1].flow -= tr;
			return tr;
		}
		return 0;
	}
 
	ll maxflow(){
		ll f = 0;
		while(1){
			fill(lv.begin(), lv.end(), -1);
			lv[s] = 0;
			q.push(s);
			if(!bfs()) break;
			fill(ptr.begin(), ptr.end(), 0);
			while(ll pushed = dfs(s, INF)){
				f += pushed;
			}
		}
		return f;
	}
};