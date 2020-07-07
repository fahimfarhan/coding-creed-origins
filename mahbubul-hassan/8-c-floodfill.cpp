#include <bits/stdc++.h>

using namespace std;

int g[10][10] = {
    {0,02,03,0,03,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,01,0,0,0,0,0,0,0,0},
    {0,01,01,01,02,0,0,0,0,0},
    {0,01,0,0,0,0,0,0,0,0},
    {0,01,0,0,0,0,0,0,0,0},
    {0,01,01,01,01,01,01,01,0,0},
    {0,0,0,0,01,0,0,0,0,0},
    {0,0,01,01,01,0,0,0,0,0},
    {0,0,0,0,01,0,0,0,0,0},
};

bool isvalid(int x, int y){
    return ( (x>=0) && (x<10) && (y>=0) && (y<10));
}

void floodfill(int x, int y, int oldColor, int newColor){
    if(isvalid(x,y)){
        if(g[x][y] == oldColor){
            g[x][y] = newColor;
            floodfill(x+1, y, oldColor, newColor);
            floodfill(x-1, y, oldColor, newColor);
            floodfill(x, y+1, oldColor, newColor);
            floodfill(x, y-1, oldColor, newColor);
        }
    }
}

void printer(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<g[i][j]<<" ";
        }cout<<"\n";
    }
}

int main(){
    cout<<"before\n";
    printer();
    floodfill(8,2,1,7);
    cout<<"after\n";
    printer();
    return 0;
}