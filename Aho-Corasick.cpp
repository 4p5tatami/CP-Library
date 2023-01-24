/* Builds an aho-corasick automaton with suffix links and exit links.
Complexity : O(nk), where k is the alphabet size. 
define M and K */

int trie[M][K], link[M], elink[M], sz;
int word[M];

void add_string(string s){

    int node = 0;

    for(char ch : s){
        int c = ch-'a';
        if(!trie[node][c]){
            trie[node][c] = ++sz;
        }
        node = trie[node][c];
    }

    //pattern "s" ends at vertex "node". store relevant pattern info in word[node].

}

void push_links(){

    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int c=0; c<K; c++){
            if(trie[u][c]){
                int v = trie[u][c];
                link[v] = (trie[link[u]][c] == v) ? 0 : trie[link[u]][c];
                elink[v] = (word[link[v]] > 0) ? link[v] : elink[link[v]];
                q.push(v);
            }else{
                trie[u][c] = trie[link[u]][c];
            }
        }
    }

}
