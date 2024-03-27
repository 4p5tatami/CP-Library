//define M, INF first
/*
use = for assignment, += for addition
multiply with range length (tr-tl+1) when assigning lazy values for range sum
*/

struct segtree_lazy{
    
    ll t[4*M], lazy[4*M];
    int n;

    segtree_lazy(int n=0) : n(n){};

    void build(ll a[], int v, int tl, int tr){

        //lazy[v] = -1; //for assignment
        if(tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }

    void build(ll a[]){
        build(a, 1, 1, n);
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
        t[v] = max(t[v*2], t[v*2+1]);

    }

    void update(int l, int r, ll val){
        update(1, 1, n, l, r, val);
    }

    ll query(int v, int tl, int tr, int l, int r){

        push(v, tl, tr);

        if(l > tr or r < tl) return 0;

        if(l <= tl and tr <= r) return t[v];

        int tm = (tl + tr) / 2;

        ll Lchild = query(v*2, tl, tm, l, r);
        ll Rchild = query(v*2+1, tm+1, tr, l, r);

        return max(Lchild, Rchild);

    }

    ll query(int l, int r){
        return query(1, 1, n, l, r);
    }
};