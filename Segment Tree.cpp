//declare M first
ll t[4*M];

void build(ll a[], int v, int tl, int tr){

    if(tl == tr){
        t[v] = a[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}

void update(int v, int tl, int tr, int pos, ll new_val){

    if(tl == tr){
        t[v] = new_val;
        return;
    }

    int tm = (tl + tr) / 2;
    if(pos <= tm) update(v*2, tl, tm, pos, new_val);
    else update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = t[v*2] + t[v*2+1];

}

ll query(int v, int tl, int tr, int l, int r){

    if(l > tr or r < tl) return 0;

    if(l <= tl and tr <= r) return t[v];

    int tm = (tl + tr) / 2;

    ll Lchild = query(v*2, tl, tm, l, r);
    ll Rchild = query(v*2+1, tm+1, tr, l, r);

    return Lchild + Rchild;

}



