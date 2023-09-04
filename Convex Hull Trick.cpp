//slopes and queries given in sorted order

struct line{
    ll m, c;
    ll eval(ll x){
        return m*x + c;
    }
    long double intersectX(line l){
        return 1.0*(c-l.c)/(l.m-m);
    }
};
 
 
deque<line>lines;
deque<long double>points;
 
void add(line L){
    while(lines.size() >= 2 and lines[lines.size()-2].intersectX(L) <= lines[lines.size()-2].intersectX(lines.back())){
        lines.pop_back();
        points.pop_back();
    }
    if(!lines.empty()) points.push_back(lines.back().intersectX(L));
    lines.push_back(L);
    
}

int ptr;

ll query(ll x){
    while(ptr < points.size() and points[ptr] < x) ptr++;
    return lines[ptr].eval(x);
}