/*
answer queries offline. use remove and add functions to define adding and removing of indices
complexity : O(n*sqrt(n)*f), where f is the time taken by the remove/add function
*/

const int B = 450; //define B close to sqrt(n)

void add(int idx){

} 
void remove(int idx){

}
ll get_answer(){

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
 
vector<ll>mo(vector<query>queries){
    
    vector<ll>answers(queries.size());
    sort(queries.begin(), queries.end());
 
    int cur_l = 1, cur_r = 0;
 
    for(auto q : queries){
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
        answers[q.idx] = get_answer();
    }

    return answers;
 
}