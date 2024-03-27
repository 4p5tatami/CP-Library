vector<int>eulerian_cycle(int s, int n, vector<pii>edges){

    int m = edges.size();
    vector<int>used(m, 0);
    vector<pii>g[n+1];
    vector<int>deg(n+1, 0);

    for(int i=0; i<m; i++){
        auto [u, v] = edges[i];
        deg[u]++, deg[v]++;
        g[u].emplace_back(v, i), g[v].emplace_back(u, i);
    }

    for(int i=1; i<=n; i++){
        if(deg[i] % 2){
            return vector<int>(1, -1);
        }
    }

    stack<int>st;
    st.push(s);

    vector<int>ans;

    while(!st.empty()){
        int u = st.top();
        if(deg[u] == 0){
            ans.push_back(u);
            st.pop();
        }else{
            for(auto [v, id] : g[u]){
                if(!used[id]){
                    deg[u]--, deg[v]--;
                    st.push(v);
                    used[id] = 1;
                    break;
                }
            }
        }
    }

    return ans;

}