//linear sieve. define M
int sp[M];
vector<int>pr;

void sieve(){

    for(int i=2; i<M; i++){
        if(!sp[i]){
            sp[i] = i;
            pr.push_back(i);
        }
        for(int j=0; j<pr.size() and pr[j]<=sp[i] and i*pr[j]<M; j++){
            sp[i*pr[j]] = pr[j];
        }
    }
}

void factorize(int x){

    while(x > 1){
        //sp[x] is a prime factor
        x /= sp[x];
    }

}
