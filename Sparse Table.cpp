//define M, K >= log2(n)
int lg2[M];
int table[M][K];

void precalc(){ //run this first

    for(int i=2; i<M; i++){
        lg2[i] = lg2[i/2] + 1;
    }

}

void make_table(int a[], int n){
    for(int i=1; i<=n; i++){
        table[i][0] = a[i];
    }
    for(int j=1; j<K; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int L, int R){
    int len = lg2[R-L+1];
    return min(table[L][len], table[R-(1<<len)+1][len]);
}