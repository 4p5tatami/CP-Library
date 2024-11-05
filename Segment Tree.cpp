template<typename T>
struct segtree{

    T t[4*M];
    int n;

    segtree(int n=0) : n(n){}

    void build(T a[], int v, int tl, int tr){

        if(tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }

    void build(T a[]){
        build(a, 1, 1, n);
    }

    void update(int v, int tl, int tr, int pos, T val){

        if(tl == tr){
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if(pos <= tm) update(v*2, tl, tm, pos, val);
        else update(v*2+1, tm+1, tr, pos, val);
        t[v] = t[v*2] + t[v*2+1];

    }

    void update(int idx, T val){
        update(1, 1, n, idx, val);
    }

    T query(int v, int tl, int tr, int l, int r){

        if(l > tr or r < tl) return T(0);

        if(l <= tl and tr <= r) return t[v];

        int tm = (tl + tr) / 2;

        T Lchild = query(v*2, tl, tm, l, r);
        T Rchild = query(v*2+1, tm+1, tr, l, r);

        return Lchild + Rchild;

    }

    T query(int L, int R){
        return query(1, 1, n, L, R);
    }
};