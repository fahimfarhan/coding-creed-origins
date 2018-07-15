#include <bits/stdc++.h>
using namespace std;
#define N 4

int start[N][N] = {
    {9,10,11,12},
    {5,6,7,8},
    {13,14,15,0},
    {1,2,3,4}
    
};
int goal[N][N] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11},
    {12,13,14,15}
};

map<int, pair<int,int> > mp;

void mapInit(){
    pair<int,int> p[16];
    int count = 0;
    for(int i=0; i<16; i++){
        int j = count/4; int k = count%4;
        p[i].first = j; p[i].second = k;
        mp[i] = p[i];
    }

}

class Node{
public:
    //Node *parent;
    // x0,y0 = pos of 0
    int x0,y0,hx,gx, fx; // hx = heurustuc func cost, gx = level / depth 
    //int dirx, diry;

    Node(){
        //parent = NULL; 
        x0=0; y0=0;fx = 0;  hx = 0; gx = 0; //dirx = 0; diry=0;
    }
    void FX(){ fx = gx+hx; }
};

void printer(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d ", start[i][j]);
        printf("\n");
    }
}
/*
Node* newNode(int xi, int yi, int level, Node*  parent)
{
    Node *node = new Node;
    node->parent = parent;
    //memcpy(node->mat, mat, sizeof(node->mat));

    // curr level
    node->gx = level;
    // save blank pos
    node->x0 = xi;
    node->y0 = yi;

    return node;
}
*/

// botton, left, top, right
int row[4] = { 1, 0, -1, 0 };
int col[4] = { 0, -1, 0, 1 };
 
int CalculateCost(int initial[N][N])  // calculateCost
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && (initial[i][j] != goal[i][j]))
        {
            int xi = mp[initial[i][j]].first;
            int yi = mp[initial[i][j]].second;
            int e = max(abs(xi-i), abs(yi-j));
            
            count = count+e; // eta thik korte hobe!!!
        }   
    return count;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}



void solution(){
    vector<Node> v;
    Node root;
    root.x0 = 2; root.y0 = 3; 
    int mat[N][N];
    
    memcpy(mat, start, sizeof(mat));
    root.hx = CalculateCost(mat);
    root.FX();
    v.push_back(root);
    int count = 0;
    printf("step #: %d\n", count);
    printf("fx = %d, gx = %d , hx = %d\n\n", root.fx, root.gx, root.hx);
    
    while(true){
        count++;
        if(count == 100){ break; }
        // print
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%d ", mat[i][j]);
            }printf("\n");
        }
        printf("\n------------\n");

        int last_pos = v.size()-1;
        if(v[last_pos].hx==0){
            break;
        }

        int temp[N][N][N];
        int xi = v[last_pos].x0; int yi = v[last_pos].y0;


        int min_hx = INT_MAX;
        int min_pos = 0;
        for(int i=0; i<4; i++){
            if(isSafe(v[last_pos].x0+row[i], v[last_pos].y0+col[i])){
            /*    
                if(last_pos-1 >2){
                    if(!( (v[last_pos-1].x0 ==(v[last_pos].x0+row[i])) && (v[last_pos-1].y0 == v[last_pos].y0+col[i]) )){
                        
                    }
                }
            */
                memcpy(temp[i], mat, sizeof(temp[i]));        
                swap(temp[i][xi][yi],temp[i][xi+row[i]][yi+col[i]]);
                int temp_hx = CalculateCost(temp[i]);

                if(temp_hx<min_hx){ min_hx = temp_hx; min_pos = i;  }

            }
        }

        Node next;
        next.hx = min_hx;
        next.gx = v[last_pos].gx+1;
        next.FX();
        next.x0 = v[last_pos].x0 + row[min_pos];
        next.y0 = v[last_pos].y0 + col[min_pos];

        v.push_back(next);
        // updat the matrix
        swap(mat[v[last_pos].x0][v[last_pos].y0], mat[next.x0][next.y0]);
        printf("step #: %d\n", count);
        printf("fx = %d, gx = %d , hx = %d\n\n", next.fx, next.gx, next.hx);
    }
    // now print soln
    /*printer();
    for(int i=1; i<v.size(); i++){
        int x_p = v[i-1].x0; int y_p = v[i-1].y0;
        int x_c = v[i].x0; int y_c = v[i].y0;

        swap(start[x_p][y_p], start[x_c][y_c]);
        printer();
    }*/

}



int main()
{
    mapInit();
    solution();
    return 0;
}