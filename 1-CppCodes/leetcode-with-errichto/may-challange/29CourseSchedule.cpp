#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> *g;
    queue<int> q;
    int *degree;
    int n;
    bool b;
public:
    void bfs() {
        // 1. detect src
        // for sources, degree[src] = 1, g[src].size() >= 1

        for(int i=0; i<n; i++) {
            if( (degree[i] == 1) && (g[i].size() >= 1) ) {
                q.push(i);
            }
        }

        // bfs
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        g = new vector<int>[n+1];
        degree = new int[n+1];
        for(int i=0; i<=n; i++) {   degree[i] = 0;  }
        b = true;

        for(int i=0; i<prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            g[u].push_back(v);
            degree[u]++; degree[v]++;
        }

        

        delete[] g;
        delete[] degree;
        return b;
    }
};

int main() {


    return 0;
}