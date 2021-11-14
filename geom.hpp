#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001) {
    return abs(d2 - d1) < eps;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x;
    in >> p.y;
    
    return in;
}

struct Line {
    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {}

    Line(const Point& p1, const Point& p2) {
        A = (p2.y - p1.y)/(p2.x - p1.y); 
        B = -1; 
        C = p1.y - p1.x*((p2.y - p1.y)/(p2.x - p1.y));
    }

    bool parallel(const Line& other) const {
        if(other.A == 0 || other.B == 0){
            
        }
        return (A/other.A) == (B/other.B);
    }

    Line parallel(const Point& p) {
        return Line(0,0,0);
    }

    bool perpendicular(const Line& other) const {
        if(A*B + other.A*other.B == 0){
            return true;
        }
        return false;
    }

    Line perpendicular(const Point& p) {
        return Line(0,0,0);
    }

    void print(ostream& out) const {
        out<< A << "x + "<< B<< "y + "<< C<< " = 0";
    }
};

ostream& operator<<(ostream& out, const Line& l) {
    l.print(out);
    return out;
}

istream& operator>>(istream& in, Line& l) {
    in >> l.A;
    in >> l.B;
    in >> l.C;
    
    return in;
}
