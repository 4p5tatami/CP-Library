int trie[M*K][2];
int cnt[M*K];
int sz = 0;

void Insert(int x){
    int node = 0;

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        if(!trie[node][c]){
            trie[node][c] = ++sz;
        }
        node = trie[node][c];
        cnt[node]++;
    }
}

int Search(int x){
    int node = 0, ret = 0;

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        //do your stuff with x here
    }

    return ret;
}

void Delete(int x){
    int node = 0;
    vector<int>v(1, 0);

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        node = trie[node][c];
        cnt[node]--;
        v.push_back(node);
    }


    for(int i=1, j=K-1; i<v.size(); i++, j--){
        int c = (bool)(x >> j & 1);
        if(!cnt[v[i]]){
            trie[v[i-1]][c] = 0;
        }
    }
}