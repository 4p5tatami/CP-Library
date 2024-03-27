/*
consider numbers binary forms as vectors and XOR operation as addition (modulo 2)
this basis represents all possible linear combinations (in this case, XOR subsets) of a given array
*/

ll basis[K];
int sz;

void insertVector(ll mask){
    for(int i=0; i<K; i++){
        if(~mask >> i & 1) continue;
        if(!basis[i]){
            basis[i] = mask;
            return;
        }
        mask ^= basis[i];
    }
}
