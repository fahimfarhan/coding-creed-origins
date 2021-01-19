#include <iostream>
#include <vector>
using namespace std;

inline void displayPathtoPrincess(const int& n, const vector <string>& grid){
    //your logic here
    int px = -1, py = -1;
    int mx = -1, my = -1;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(grid[i][j] == 'p') {
          px = i; py = j;
        }else if(grid[i][j] == 'm') {
          mx = i; my = j;
        }

        if(px != -1 && mx != -1) {
          break;
        }
      }
    }

    int dx = px - mx; // - LEFT, + RIGHT
    int dy = py - my; // - UP, + DOWN

    string horizontal , vertical;
    if(dx > 0) {  horizontal = "LEFT";  }else { horizontal = "RIGHT"; }
    if(dy > 0) {  vertical = "UP";  }else { vertical = "DOWN";  }

    dx = abs(dx);
    dy = abs(dy);
    for(int i= 0; i<dx; i++) {  cout<<horizontal<<"\n"; }
    for(int i= 0; i<dy; i++) {  cout<<vertical<<"\n"; }
    
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}