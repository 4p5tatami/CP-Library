/*
answer queries offline. use remove and add functions to define adding and removing of indices
complexity : O(n*sqrt(n)*f), where f is the time taken by the remove/add function
*/

const int BLOCK = 320; //define BLOCK as close to sqrt(n)

void remove(int idx);
void add(int idx);
int get_answer();

struct query{
    int l, r, idx;
    query(){};
    query(int _l, int _r, int _idx) : l(_l), r(_r), idx(_idx){};
    bool operator <(const query &other){
        return make_pair((l-1)/BLOCK, r) < make_pair((other.l-1)/BLOCK, other.r);
    }
};

vector<int>mo(vector<query>queries){

    vector<int>answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 1, cur_r = 0;

    for(query q : queries){
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
