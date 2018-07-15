#include <bits/stdc++.h>
#define N 10
using namespace std;
int b[N][N] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,1,0,1,0},
            {0,0,1,0,1,0,0,0,1,0},
            {0,0,0,1,0,0,0,0,1,0},
            {0,0,0,1,0,0,0,0,1,0},
            {0,0,0,1,0,0,0,0,1,0},
            {0,0,0,1,1,1,1,1,1,0},
            {0,0,0,0,0,0,0,0,0,0}
        };

class Node{
    public:
    double f,g,h; // g = distance from src; h = distance to dest
    int x,y;
    Node(){
        f = 0; g = 0; h = 0;

        int x = -1; y = -1; 
    }
};

class AStar{
public:
    int a[N][N];
    int sx, sy, dx,dy;
    bool isVisited[N][N];

    deque<Node> openList;
    
    void Algorithm1(){
        Node n;
        n.x = sx; n.y = sy; 
        n.g = 0; n.h = H1(n.x,n.y);
        isVisited[n.x][n.y] = true;
        openList.push_back(n);
        while(!openList.empty()){
            Node temp;
            temp.x = openList[0].x; temp.y = openList[0].y;
            temp.f = openList[0].f; temp.g = openList[0].g;
            temp.h = openList[0].h;

            openList.pop_front();

            // check all 8 sides 1 by 1 
            // x+1, y+1
            


        }
        
    }

    double H1(int x, int y){
        int h;
        h = (x-dx)*(x-dx)+(y-dy)*(y-dy);
        h = sqrt(h);
        return h;
    } 

    AStar(){
        reset_isVisited();
        cout<<"Enter sx sy dx dy respectively: ";
        cin>>sx>>sy>>dx>>dy;
        cout<<"Enter r to use random input, any other key for default input: ";
        char ch;
        cin>>ch;
        if(ch == 'r')
        {  set_random_input();  }
        else
        {  test();  }

    }

    ~AStar(){}
    void reset_isVisited(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                isVisited[i][j] = false;
            }
        }
    }
    bool isValid(int x, int y){
        if((0<=x && x<10) && (0<=y && y<10))
            return true;
        return false;
    }

    bool isUnblocked(int x, int y){
        return !a[x][y];
    }

    void set_random_input(){
        srand(time(0));

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                a[i][j] = (rand()%2);
            }
        }

    }
    void test(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                a[i][j] = b[i][j];
            }
        }
    }
    void printer(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<a[i][j]<<" ";
            }cout<<"\n";
        }
    }

};


int main()
{
    AStar astar;
    astar.test();
    astar.printer();
    return 0;
}