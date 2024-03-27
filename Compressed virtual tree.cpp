/*
Creates a compressed virtual tree for a given set of nodes which includes all possible LCA pairs of that set. O(k) nodes.
Needs LCA template.
Complexity : O(klogk)
*/

int used[M], tpar[M];
vector<int>gt[M];
int rut;
vector<int>nodes;

void gen_tree(vector<int>vc){
    
    for(int x : vc) used[x] = 1;
    sort(vc.begin(), vc.end(), [&](int x, int y){
        return tin[x] < tin[y];
    });
    
    nodes = vc;
    for(int i=0; i+1<vc.size(); i++){
        int L = LCA(vc[i], vc[i+1]);
        if(!used[L]) nodes.push_back(L), used[L] = 1;
    }

    sort(nodes.begin(), nodes.end(), [&](int x, int y){
        return tin[x] < tin[y];
    });

    vector<int>cur;

    for(int x : nodes){
        while(!cur.empty() and LCA(x, cur.back()) != cur.back()){
            tpar[cur.back()] = cur[cur.size()-2];
            cur.pop_back();
        }
        cur.push_back(x);
    }

    while(cur.size() > 1){
        tpar[cur.back()] = cur[cur.size()-2];
        cur.pop_back();
    }

    for(int x : nodes){
        if(tpar[x]) gt[tpar[x]].push_back(x);
        else rut = x;
    }

}


void reset(){
    for(int x : nodes){
        used[x] = tpar[x] = 0;
        gt[x].clear();
    }
    rut = 0;
    nodes.clear();
}
