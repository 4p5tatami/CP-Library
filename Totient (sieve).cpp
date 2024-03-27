int phi[M];

void phi_sieve(){ //run this
    iota(begin(phi), end(phi), 0);
    for(int i=2; i<M; i++){
        if(phi[i] == i){
            for(int j=i; j<M; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}