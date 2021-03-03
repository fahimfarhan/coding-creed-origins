#include <bits/stdc++.h>

using namespace std;

class Point{
    public:
    int x,y;
}

int compareX(const void* a, cconst void* b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->x - p2->x);
}

int compareY(const void* a, cconst void* b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->y - p2->y);
}

double dist(Point p1, Point p2){
    double ret = 0;
    ret = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    ret = sqrt(ret);
    return ret;
}

double bruteforce(Point p[], int n){
    double minimus=INT_MAX, temp=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                temp = dist(p[i],p[j]);
                minimus = min(minimus, temp);
            }
        }
    }
    return minimus;
}

int main()
{


    return 0;
}