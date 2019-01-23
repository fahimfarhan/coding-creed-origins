#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;

#define TN TreapNode
class TreapNode{
public:
    int key, priority;
    TN *l,*r;
    TN(int key = 0){    this->key=key; priority = rand()%100; l=NULL; r=NULL;   }
    ~TN(){  
        if(!l){ delete[] l; l=NULL; }
        if(!r){ delete[] r; r=NULL; }  
    }

    TN operator= (const TN& point)
    {
        this->key = point.key;
        this->priority = point.priority;
        this->l = point.l;
        this->r = point.r;
        
        return *this;
    }

};

/* T1, T2 and T3 are subtrees of the tree rooted with y 
  (on left side) or x (on right side) 
                y                               x 
               / \     Right Rotation          /  \ 
              x   T3   – – – – – – – >        T1   y 
             / \       < - - - - - - -            / \ 
            T1  T2     Left Rotation            T2  T3 */
  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 

TN *rotateRight(TN *y){
    TN temproot; 
    TN x = *y->l;
    TN T1 = *x.l;
    TN T2 = *x.r;
    TN T3 = *y->r;
    temproot = x;
    temproot.l = &T1;
    temproot.r = y;
    temproot.r->l = &T2;
    temproot.r->r = &T3;
    return &temproot;
}

TN *rotateLeft(TN *x){
    TN temproot;
    TN T1, T2, T3, y;
    y = *x->r;
    T1 = *x->l;
    T2 = *y.l;
    T3 = *y.r;

    temproot = y;
    temproot.l = x;
    temproot.l->l = &T1;
    temproot.l->r = &T2;
    temproot.r = &T3;
    return &temproot;
}
TN *search(TN *root, int key){
    // normal BST 
    if( (root == NULL) || (root->key = key) ){    return root;    }
    else if(root->key > key){   return search(root->l, key);    }
    else{ return search(root->r, key);  }
    return NULL;
}

TN *insert(TN *root, int key){
    if(!root){ TN r(key); return &r;  }
    if(key <= root->key){ 
        // Insert in left subtree 
        root->l = insert(root->l, key);

        // Fix Heap property if it is violated 
        if(root->l->priority > root->priority){
            return rotateRight(root);
        }
    }else{
        // insert in r8 branch
        root->r = insert(root->r, key);
        // Fix Heap property if it is violated 
        if(root->r->priority > root->priority){
            return rotateLeft(root);
        }
    }
}

TN *deleteNode(TN *root, int key){
    if (root == NULL) 
        return root; 
    if (key < root->key) 
        root->l = deleteNode(root->l, key); 
    else if (key > root->key) 
        root->r = deleteNode(root->r, key); 
    // IF KEY IS AT ROOT 
  
    // If left is NULL 
    else if (root->l == NULL) 
    { 
        TreapNode *temp = root->r; 
        delete(root); 
        root = temp;  // Make right child as root 
    } 
    // If key is at root and both left and right are not NULL 
    else if (root->l->priority < root->r->priority) 
    { 
        root = rotateLeft(root); 
        root->l = deleteNode(root->l, key); 
    } 
     else
    { 
        root = rotateRight(root); 
        root->r = deleteNode(root->r, key); 
    } 
  
    return root; 
    //return NULL;
}

// A utility function to print tree 
void inorder(TreapNode* root) 
{ 
    if (root) 
    { 
        inorder(root->l); 
        cout << "key: "<< root->key << " | priority:  "
            << root->priority; 
        if (root->l) 
            cout << " | left child: " << root->l->key; 
        if (root->r) 
            cout << " | right child: " << root->r->key; 
        cout << endl; 
        inorder(root->r); 
    }else{  cout<<"shit\n";} 
} 
  

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 srand(time(NULL)); 
    //TN tn;
    //tn.key = 1; 
    TN *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
  cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    TreapNode *res = search(root, 50); 
    (res == NULL)? cout << "\n50 Not Found ": 
                   cout << "\n50 found"; 
  return 0;
}

