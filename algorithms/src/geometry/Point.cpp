#include <bits/stdc++.h>
#include "Point.hpp"

using namespace std;

int main() {

    Point p1(1, 1);
    Point p2(2, 2);
    Point p11(1, 1);

    Point p3(1, 1);
    p3 *= 5;
    cout << p3.x << " " << p3.y << endl;
    p3 /= 5;
    cout << p3.x << " " << p3.y << endl;
    
    printf("%d\n", p1 == p11);
}