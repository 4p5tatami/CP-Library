/*
find solutions to equation -> ax + by = c. 
solutions will be of form -> x = x0 + k*(b/g), y = y0 - k*(a/g).
*/

ll ext_gcd(ll a, ll b, ll &x, ll &y){
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1){
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
    g = ext_gcd(abs(a), abs(b), x0, y0);
    if(c % g) return false;

    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

//find number of solutions such that x in [minx, maxx] and y in [miny, maxy]

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt){
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy){ 
    ll x, y, g;
    if(!find_any_solution(a, b, c, x, y, g)) return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if(x < minx) shift_solution(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if(x > maxx) shift_solution(x, y, a, b, -sign_b);
    
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if(y < miny) shift_solution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}