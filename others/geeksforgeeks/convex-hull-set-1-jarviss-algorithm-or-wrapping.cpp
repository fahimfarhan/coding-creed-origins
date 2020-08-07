#include <bits/stdc++.h>

using namespace std;

class Point{
public:
    int x,y;
};

int orientation(const Point& p, const Point& q, const Point& r){
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

    if(val == 0){   return 0;   } // colinear
    if(val > 0 ){   return 1; }   // clockwise 
    else return 2;                // anticlockwise
    
}

void convexHull(Point points[], int n){
    if(n<3) return;
    // initialize result
    vector<Point> hull;

    int l = 0;
    for(int i=0; i<n; i++){
        if(points[i].x < points[l].x){    l = i;    }
    }
     // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output. 

    int p,q;
    p = l;
    while(1){
        hull.push_back(points[p]);
          // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n;
        for(int i=0; i<n; i++){
            // If i is more counterclockwise than current q, then 
           // update q 
            if(orientation(points[p], points[i], points[q]) == 2)
            {    q = i;  }
        }
        // Now q is the most counterclockwise with respect to p 
        // Set p as q for next iteration, so that q is added to 
        // result 'hull' 
        p = q;
        if(p==l){   break;  }
    }

     // Print Result 
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n"; 

}

int main(){

    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    convexHull(points, n); 
    return 0;
}