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
    TN *l, *r;
    TreapNode(int key = 0){
        this->key = key; priority = rand()%100; l = NULL; r = NULL;
    }
};

TN *rotateRight(TN *y){
    TN *x = y->l, *T2 = x->r;
    // perform rotation
    x->r = y;
    y->l = T2;
    return x;
}

TN *rotateLeft(TN *x){
    TN *y=x->r, *T2 = y->l;
    // perform rotation
    y->l = x;
    x->r = T2;

    return y;
}

TN *search(TN *root, int key){
    //just like binary search
    if( (root == NULL) || (root->key == key) ){
        return root;
    }

    // left 
    if(key < root->key){
        return search(root->l, key);
    }else{ return search(root->r, key); }
    return NULL;
}

TN *insert(TN *root, int key){
    // if no root, create a new node and return
    if(!root){
        root = new TN(key);
        return root;
    }

    if(key <=root->key){
        // insert in the left branch
        root->l = insert(root->l, key);
        // fix priority issue
        if(root->l->priority > root->priority){
            root = rotateRight(root);
        }
    }else{
        root->r = insert(root->r, key);
        // fix priority
        if(root->r->priority > root->priority){
            root = rotateLeft(root);
        }
    }
    return root;
}

TN *deleteNode(TN *root, int key){
    if(root == NULL){   return root;    }
    if(key < root->key){    root = deleteNode(root->l, key);    }
    else if (key > root->key){  root = deleteNode(root->r, key);   }
    // if key is at root 

    // if left = NULL
    else if(root->l == NULL){
        TN *temp = root->r;
        root->r = NULL;
        delete(root);
        root = temp;
        temp = NULL;
    }
    // if right == NULL 
    else if(root->r == NULL){
        TN *temp = root->l;
        root->l = NULL;
        delete(root);
        root = temp;
        temp = NULL;

    }else if(root->l->priority < root->r->priority){
        root = rotateLeft(root);
        root->r = deleteNode(root->l, key);
    }else{
        root = rotateRight(root);
        root->r = deleteNode(root->r, key);
    }
    return root;
}

void inorder(TN *root){
    if(root){
        inorder(root->l); 
        cout << "key: "<< root->key << " | priority: %d "
            << root->priority; 
        if (root->l) 
            cout << " | left child: " << root->l->key; 
        if (root->r) 
            cout << " | right child: " << root->r->key; 
        cout << endl; 
        inorder(root->r); 
    }
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

    TN *root(NULL);

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

