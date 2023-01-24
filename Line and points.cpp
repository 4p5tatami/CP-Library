struct Line{

    int A, B, C;

    Line(int _A = 0, int _B = 0, int _C = 0) : A(_A), B(_B), C(_C){}

    Line(int x1, int y1, int x2, int y2){
        A = y1 - y2, B = x2 - x1;
        C = -A*x1 - B*y1;
        int g = gcd(abs(A), abs(B));
        g = gcd(g, abs(C));
        A /= g, B /= g, C /= g;
        if(A < 0 or (A == 0 and B < 0)) A *= -1, B *= -1, C *= -1;
    }

    pii slope(){
        int num = -A, den = B;
        int g = gcd(abs(num), abs(den));
        num /= g, den /= g;
        if(den < 0) den *= -1, num *= -1;
        if(den == 0) num = 1;
        return {num, den};
    }

    friend pair<double, double>intersection(Line L1, Line L2){
        int a1 = L1.A, b1 = L1.B, c1 = -L1.C;
        int a2 = L2.A, b2 = L2.B, c2 = -L2.C;
        int D = a1*b2 - a2*b1;
        if(D == 0) return {1e18, 1e18};
        double x = (double)(c1*b2 - c2*b1)/D;
        double y = (double)(a1*c2 - a2*c1)/D;
        return {x, y};
    }
    
};