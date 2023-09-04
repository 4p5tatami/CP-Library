/*
answer queries offline. use remove and add functions to define adding and removing of indices
complexity : O(n*sqrt(n)*f), where f is the time taken by the remove/add function
*/

const int B = 450; //define BLOCK as close to sqrt(n)
 
void remove(int idx){

}

void add(int idx){

}
 
int get_answer(){

}
 
struct query{
    int l, r, idx;
    query(){};
    query(int _l, int _r, int _idx) : l(_l), r(_r), idx(_idx){};
    bool operator <(const query &other){
        if(l/B == other.l/B){
            if((l/B) & 1) return r > other.r;
            else return other.r > r;
        }
        return l < other.l;
    }
};
 
query queries[M];
int ans[M];
 
void mo(int m){
 
    sort(queries+1, queries+m+1);
 
    int cur_l = 1, cur_r = 0;
 
    for(int i=1; i<=m; i++){
        query q = queries[i];
        while(cur_l > q.l){
            cur_l--;
            add(cur_l);
        }
        while(cur_r < q.r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l < q.l){
            remove(cur_l);
            cur_l++;
        }
        while(cur_r > q.r){
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_answer();
    }
 
}
