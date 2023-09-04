//define M, K

int table[M][M][K][K];
int lg2[M];


void precalc(){ //run this first

    for(int i=2; i<M; i++){
        lg2[i] = lg2[i/2] + 1;
    }
}

void make_table(int grid[][M], int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            table[i][j][0][0] = grid[i][j];
        }
    }
    for(int a=0; a<K; a++){
        for(int b=0; b<K; b++){
            if(a+b == 0) continue;
            for(int i=1; i+(1<<a)-1<=n; i++){
                for(int j=1; j+(1<<b)-1<=m; j++){
                    if(!a){
                        table[i][j][a][b] = max(table[i][j][a][b-1], table[i][j+(1<<(b-1))][a][b-1]);
                    }else{
                        table[i][j][a][b] = max(table[i][j][a-1][b], table[i+(1<<(a-1))][j][a-1][b]);
                    }
                }
            }
        }
    }
}

int query(int x1, int y1, int x2, int y2){
    int a = lg2[x2-x1+1], b = lg2[y2-y1+1];
    return max(max(table[x1][y1][a][b], table[x2-(1<<a)+1][y1][a][b]), 
        max(table[x1][y2-(1<<b)+1][a][b], table[x2-(1<<a)+1][y2-(1<<b)+1][a][b]));
}



