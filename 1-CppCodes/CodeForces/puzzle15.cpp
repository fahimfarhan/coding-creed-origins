#include <bits/stdc++.h>
using namespace std;
#define N 4
class Node{
public:
    Node *parent;
    int mat[N][N];
    int x,y,cost,level;
};

//class Puzzle15{
//public:
void printer(int mat[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

Node* newNode(int mat[N][N], int x, int y, int xi, int yi, int level, Node*  parent)
{
    Node *node = new Node;
    node->parent = parent;
    memcpy(node->mat, mat, sizeof(node->mat));

    // swap
    node->mat[x][y] = (node->mat[x][y])^(node->mat[xi][yi]);
    node->mat[xi][yi] = (node->mat[x][y])^(node->mat[xi][yi]);
    node->mat[x][y] = (node->mat[x][y])^(node->mat[xi][yi]);
    // curr level
    node->level = level;
    // save blank pos
    node->x = xi;
    node->y = yi;

    return node;
}

// botton, left, top, right
int row[4] = { 1, 0, -1, 0 };
int col[4] = { 0, -1, 0, 1 };
 
//};
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    printer(root->mat);
 
    printf("\n");
}

// Comparison object to be used to order the heap
class comp
{
public:
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

void solve(int initial[N][N], int x, int y, int final[N][N]){
    priority_queue<Node*, vector<Node*>, comp> pq;
    
    Node* root = newNode(initial, x,y,x,y,0,NULL);
    root->cost = calculateCost(initial, final);
    pq.push(root);

    while(!pq.empty()){
        Node *min = pq.top();
        pq.pop();

        if(min->cost == 0){
            printPath(min);
            return;
        }
        for(int i=0; i<4; i++){
            if(isSafe(min->x + row[i], min->y + col[i]))
            {
                 Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                // Add child to list of live nodes
                pq.push(child);
            }
        }

    }

}
int main()
{
    
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
    int x=2,y=3;
    solve(start, x, y, goal);
    return 0;
}