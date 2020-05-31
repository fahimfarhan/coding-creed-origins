#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, end;
    int *g;
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // best guess input = vector<pair<int,int> >dekhte jerokom, thik seirokom
        this->n = numCourses;
        
        g = new int[numCourses+10];
        
        this->end = -1;
        for(int i=0; i<=numCourses; i++) {   g[i] = end; }

        for(int i=0; i<prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            g[u] = v;  // construct the graph
        }

        int hare = 0, tortoise = 0;
        bool b = true;

        // cout<<"here3\n";
        while(true) {
            if(tortoise != end) {   tortoise = g[tortoise];   }
            else{   break;    }
        
            if(hare != end) {    hare = g[hare];    }
            else{   break;    }
            
            if(hare != end) {    hare = g[hare];    }
            else{   break;    }
        
            if(hare == tortoise) {  b = false; break;  }
        }

        if(!g) delete[] g;
        return b;
    }
};

int main() {
    Solution s;
    // vector<vector<int> > v = {{0,1}};
    vector<vector<int> > v = {{1,0}, {0,1}};
//    vector<int> v1 = {0,1};
    cout<<s.canFinish(2, v)<<"\n";
    return 0;
}