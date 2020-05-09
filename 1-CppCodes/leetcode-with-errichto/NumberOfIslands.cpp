#include <bits/stdc++.h>

using namespace std;
/** Graph Theory DFS on first glance! **/
class Solution {
public:
    vector<vector<char>> g;
    int x, y;
    vector<pair<int,int>> a = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    bool isSafe(int i, int j) {
        return ((i >=0) && (i< x) && (j>=0) && (j<y));
    }
    void dfs(int ux,int uy) {
        g[ux][uy] = '2';
        int vx=0, vy=0;
        for(int i=0; i<4; i++) {
            vx = ux + a[i].first;
            vy = uy + a[i].second;

            if(isSafe(vx,vy)) {
                if(g[vx][vy] == '1'){    dfs(vx,vy);    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) { return 0; }
        for(int i=0; i<grid.size(); i++) {
            g.push_back(grid[i]);
        }
        x = g.size();
        y = g[0].size();

        int n = 0;        

        for(int i=0; i<x; i++) {
            for(int j=0; j<y; j++) {
                if(g[i][j] == '1') {
                    n++;
                    dfs(i,j);
                }
            }
        }
        return n;
    }
};

int main() {
    vector<vector<char>> v = { {'1','1','0','0','0'},
                               {'1','1','0','0','0'},
                               {'0','0','1','0','0'},
                               {'0','0','0','1','1'}
     };
    vector<vector<char>> v1;
     Solution s;
     int n = s.numIslands(v1);
     cout<<n<<"\n";

    return 0;
}