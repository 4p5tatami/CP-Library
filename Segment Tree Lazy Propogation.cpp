//define M, INF first
/*
use = for assignment, += for addition
multiply with (tr-tl+1) for range sum
*/

ll t[4*M], lazy[4*M];

void build(ll a[], int v, int tl, int tr){

    //lazy[v] = -1; //for assignment
    if(tl == tr){
        t[v] = a[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}

void push(int v, int tl, int tr){

    //if(lazy[v] == -1) return; //for assignment
    t[v] += lazy[v];
    if(tl != tr){
        lazy[v*2] += lazy[v];
        lazy[v*2+1] += lazy[v];
    }
    lazy[v] = 0;

}

void update(int v, int tl, int tr, int l, int r, ll val){

    push(v, tl, tr);

    if(l > tr or r < tl) return;

    if(l <= tl and tr <= r){
        lazy[v] += val;
        push(v, tl, tr);
        return;
    }

    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, r, val);
    update(v*2+1, tm+1, tr, l, r, val);
    t[v] = min(t[v*2], t[v*2+1]);

}

ll query(int v, int tl, int tr, int l, int r){

    push(v, tl, tr);

    if(l > tr or r < tl) return 0;

    if(l <= tl and tr <= r) return t[v];

    int tm = (tl + tr) / 2;

    ll Lchild = query(v*2, tl, tm, l, r);
    ll Rchild = query(v*2+1, tm+1, tr, l, r);

    return Lchild + Rchild;

}