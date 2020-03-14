/**
 * left left, left right ... they might be all jumbled up -_-
 * review and fix
 * 
*/

#include <bits/stdc++.h>

using namespace std;

#define NO_ANCESTOR 0
#define LEFT_CHILD 1
#define RIGHT_CHILD 2
#define NO_CHILD -1


/**
 * @brief: a class representing out nodes
 * 
*/
class Node{
private:

public:
    int n, depth; // @TODO: Add member var/func as necessary
    Node *left, *right, *ancestor;
    Node(int n = 0){    this->n = n; left = NULL; right = NULL; ancestor = NULL;   }

    ~Node(){    
        if(left!=NULL) delete left; 
        if(right!=NULL) delete right;
    }
};
Node *root;


/**
 * @brief: insert  number in our bst
 * @input: int x
 * @output: void
*/
void Insert(const int& x){
    if(root == NULL){
        root = new Node(x);
    }else{
        Node *node = root, *parent = NULL;
        while(node!=NULL){
            parent = node;
            if(x <= (node->n) ){
                // go left
                node = node->left;
            }else{
                node = node->right;
            }
        }
        node = new Node(x);
        node->ancestor = parent;
        if(x <= (parent->n)){
            parent->left = node;
        }else{
            parent->right = node;
        }
        node = NULL;
        parent = NULL;
    }
}

/**
 * @brief: lookup for a number
 * @input: int x
 * @output: node containing x or NULL
*/
Node* Search(const int& x){
    Node *ret = root;
    while(ret != NULL){
        if(ret->n == x){
            return ret;
        }else if(x < ret->n){
            ret = ret->left;
        }else{
            ret = ret->right;
        }
    }
    return NULL;
}


/**
 * @brief: an auxiliary function to delete a single node for better/modular reusable code
 * @input: Node*
 * @output: void
*/
void Destroy(Node *node){
    Node *ancestor;
    try{
        ancestor = node->ancestor;
        if(ancestor!=NULL){ 
            if(ancestor->left == node){ ancestor->left = NULL;  }
            else{   ancestor->right = NULL; }
            ancestor = NULL;
        }
        node->ancestor = NULL; node->left = NULL; node->right = NULL;
        delete node;
    }catch(exception &x){
        cout<<x.what()<<"\n";
    }
    ancestor = NULL;
}
/**
 * @brief: return the inorder successor of a tree, ie the smallest element in a tree
 *       a
 *       /\ 
 *      b  c  return d;
 *     /
*    d
*        a
 *       /\ 
 *      b  c  return b; WARNING
 *       \
*         d
*/
Node* getInorderSuccessor(Node *input){
    Node *node = input;
    while(node->left!=NULL){
        node = node->left;
    }
    return node;
}

/**
 * @brief: use Search(x) to find the target node
 * so usage:  Delete(Search(x));
 * @input: Node*
 * @output: if deleted, return true else false
*/
bool Delete(Node *node){
    if(node == NULL){
        return false;
    }else{
        // case 1: both child are null
        if( (node->left == NULL) && (node->right == NULL) ){
            Destroy(node);
            return true;
        }
        // case 2: 1 child exist
        else if( (node->left == NULL) && (node->right!=NULL) ){
            Node *ancestor = node->ancestor;
            Node *rightChild = node->right;

            if(ancestor == NULL){ // so node is the root, therefore, new root is the rightChild
                root = rightChild;
            }else{
                if(ancestor->left == node){
                    ancestor->left = rightChild;
                }else{
                    ancestor->right = rightChild;
                }
            }
            node->ancestor = NULL; node->right = NULL;
            Destroy(node);
            return true;
        }else if( (node->left != NULL) && (node->right == NULL) ){
            Node *ancestor = node->ancestor;
            Node *leftChild = node->left;

            if(ancestor == NULL){ // so node is the root, therefore, new root is the rightChild
                root = leftChild;
            }else{
                if(ancestor->left == node){
                    ancestor->left = leftChild;
                }else{
                    ancestor->right = leftChild;
                }
            }
            node->ancestor = NULL; node->right = NULL;
            Destroy(node);
            return true;
        }else{
            // case: node has 2 children
            // 1. find inorder successor, ie, smallest element in the right subtree
            Node *inorderSuccessor = NULL; // todo: write an auxiliary function as things might get complicated
            inorderSuccessor = getInorderSuccessor((node->right));

            node->n = inorderSuccessor->n; // fetch the successor
            cout<<"inorderSuccessor = "<<inorderSuccessor->n<<"\n";
            // Destroy(inorderSuccessor);
            Delete(inorderSuccessor); // cz there might be a right child
            return true;
        }

    }

    return false;
}

void Update(Node *node, int m){
    int temp = 0;
    // 1. update
    node->n = m;
    // 2. ensure condition: left < this < right
    while(true){
        if( (node->left!=NULL) && ((node->left->n) > (node->n)) ){
            temp = node->n;
            node->n = node->left->n;
            node->left->n = temp;
        }else if( (node->left!=NULL) && ((node->n) > (node->right->n)) ){   
            temp = node->n;
            node->n = node->right->n;
            node->right->n = temp;
        }else{
            // condition ensured: left < this < right, so break
            break;
        }
    } 
}

void bfsPrinter(){
    queue<Node*> q;
    root->depth = 1;
    
    q.push(root);
    int myDepth = 1;
    while(!q.empty()){
        Node *p = q.front();
        q.pop();
        if(myDepth!=(p->depth)){
            cout<<"\n";
            myDepth = p->depth;
        }
        cout<<p->n<<" ";
        if(p->left!=NULL){
            p->left->depth = myDepth+1;
            q.push(p->left);
        }
        if(p->right!=NULL){
            p->right->depth = myDepth+1;
            
            q.push(p->right);            
        }
    }
    cout<<"\n---------------------------------------------\n";
}

void myDfsDestructor(Node *node){
    if(node->left != NULL){
        myDfsDestructor(node->left);
    }
    if(node->right != NULL){
        myDfsDestructor(node->right);
    }
    cout<<"Destroying node = "<<(node->n)<<"\n";
    Destroy(node);
}

/********* AVL TREE START ************/
int getHeight(Node *node){
    if(node == NULL){   return 0;   }
    int left = getHeight( (node->left) );
    int right = getHeight( (node->right) );
    return (1 + max(left, right));
}
//     P                                P  <--- Ancestor 
//     ||                              ||
//     A                                B
//    //\        rr / cwr              / \\
//   B   C    ---------------->       D    A
//  / \\       <----------------         // \ 
// D   E         lr / acwr               E   C 

Node* rightRotate(Node *node){
  Node *newRoot = NULL;
    Node *a, *b,  *e, *p; // *c, *d,
    int whichChildOfP = NO_CHILD;
    // 1. mark the nodes as in the diagram & some other markers
    a = node;
    p = a->ancestor;
    if(p == NULL){          whichChildOfP = NO_ANCESTOR;    }
    else if(p->left == a){  whichChildOfP = LEFT_CHILD;     }
    else{                   whichChildOfP = RIGHT_CHILD;    }
    
    b = a->left;  // c = a->right;
    e = b->right; // d = b->left; 
    // 2.  rearrange thhe bonds
    a->left = e; a->ancestor = b; if(e!=NULL){  e->ancestor = a; }
    b->right = a; b->ancestor = p; 
    if(whichChildOfP == LEFT_CHILD){    p->left = b; }
    else if(whichChildOfP == RIGHT_CHILD ){ p->right = b;   }
    // 3. new root
    newRoot = b;
    // 4. make local vars null
    a = NULL; b = NULL;  e = NULL; p = NULL; // c = NULL; d = NULL;
    // 5. return result 
    return newRoot;
}

Node* leftRotate(Node *node){
    Node *newRoot = NULL;
    Node *a, *b, *e, *p; //  *c, *d,
    int whichChildOfP = NO_CHILD;
    // 1. mark the nodes as in the diagram & some other markers
    b = node;
    p = b->ancestor;
    if(p == NULL){          whichChildOfP = NO_ANCESTOR;    }
    else if(p->left == b){  whichChildOfP = LEFT_CHILD;     }
    else{                   whichChildOfP = RIGHT_CHILD;    }

    a = b->right; //     d = b->left; 
    e = a->left;  //     c = a->right;
    // 2.  rearrange thhe bonds
    a->left = b; a->ancestor = p; 
    if(whichChildOfP==LEFT_CHILD){    p->left = a; }
    else if(whichChildOfP == RIGHT_CHILD){    p->right = a;   } 
    
    b->ancestor = a; b->right = e; if(e!=NULL){ e->ancestor = b;    }
    // 3. new root
    newRoot = a;
    // 4. make local vars null
    a = NULL; b = NULL; e = NULL; p = NULL; // c = NULL; d = NULL;
    // 5. return result 
    return newRoot;
}

// rule of thumb,
// rotate 1st direction's Child to 1st direction, then rotate Parent to 2nd direction


// Node* leftLeftRotate(Node *node){
//     Node *newRoot = NULL;
//     Node *left = node->left;
//     left = leftRotate(left);
//     newRoot = leftRotate(node);
//     return newRoot;
// }

Node* leftRightRotate(Node *node){
    Node *newRoot = NULL;
    Node *left = node->left;
    left = leftRotate(left);
    newRoot = rightRotate(node);
    return newRoot;
}

// Node* rightRightRotate(Node *node){
//     Node *newRoot = NULL;
//     Node *right = node->right;
//     right = rightRotate(right);
//     newRoot = rightRotate(node);
//     return newRoot;
// }

Node* rightLeftRotate(Node *node){
    Node *newRoot = NULL;
    Node *right = node->right;
    right = rightRotate(right);
    newRoot = leftRotate(node);
    return newRoot;
}

/** a) Left Left Case */
// T1, T2, T3 and T4 are subtrees.
//          z                                      y 
//         / \                                   /   \
//        y   T4      Right Rotate (z)          x      z
//       / \          - - - - - - - - ->      /  \    /  \ 
//      x   T3                               T1  T2  T3  T4
//     / \
//   T1   T2

/*** b) Left Right Case ***/
 
//      z                               z                           x
//     / \                            /   \                        /  \ 
//    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
//   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
// T1   x                          y    T3                    T1  T2 T3  T4
//     / \                        / \
//   T2   T3                    T1   T2


/*** c) Right Right Case ***/

//   z                                y
//  /  \                            /   \ 
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   x                     T1  T2 T3  T4
//        / \
//      T3  T4

/***d) Right Left Case ***/

//    z                            z                            x
//   / \                          / \                          /  \ 
// T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//    x   T4                      T2   y                  T1  T2  T3  T4
//   / \                              /  \
// T2   T3                           T3   T4

Node* avlBalance(Node *node){
    if(node == NULL){   return NULL; }

    int nodeHeight, leftHeight, rightHeight;
    // nodeHeight = getHeight(node);
    leftHeight = getHeight((node->left));
    rightHeight = getHeight((node->right));
    nodeHeight = 1 + max(leftHeight, rightHeight); // donot call unnecessary recursion, use memoisation tecnique to reduce time
    // TODO: maybe create Node->h to reduce recursion; 
    if(leftHeight > 1 + rightHeight){
        int llh, lrh;
        llh = getHeight( (node->left->left) );
        lrh = getHeight( (node->left->right) );

        if(llh>=lrh){
            return rightRotate(node);
        }else{
            return leftRightRotate(node);
        }
    }
    if(rightHeight > 1 + leftHeight){
        int rlh, rrh;
        rlh = getHeight(node->right->left);
        rrh = getHeight(node->right->right);

        if(rrh>=rlh){
            return leftRotate(node);
        }else{
            return rightLeftRotate(node);
        }
    }
    return node; // nothing happens, so return whatever was the input
}

void avlInsert(const int& x){
    // bst insert + balance
    Insert(x);
    root = avlBalance(root);
}

Node* avlSearch(const int& x){
    return Search(x);
}

bool avlDelete(const int& m1){
    // 1. node = search(x) 
    Node* node = avlSearch(m1);
    if(node == NULL){ return false;    }
    // 2. parent = node->ancestor
    Node *ancestor = node->ancestor;
    int whichChildOfP=NO_CHILD;
    if(ancestor == NULL){  /*this means we are at the root!*/ whichChildOfP = NO_ANCESTOR;  }
    else if(ancestor->left == node)      {   whichChildOfP = LEFT_CHILD ;    }
    else if(ancestor->right == node){   whichChildOfP = RIGHT_CHILD;    }
    bool isDeleted = Delete(node);

    Node *x,*y,*z;
    
    if(isDeleted){
        z = ancestor;
        if(whichChildOfP == NO_ANCESTOR){   z = root;   }
        else if(whichChildOfP == LEFT_CHILD ){       z = z->left;    }
        else if(whichChildOfP == RIGHT_CHILD){  z = z->right;   }
    
        // 3. balance at parent untill root's parent ie NULL
        while(z!=NULL){
            z = avlBalance(z); // we donot need to reimplement balance thanks to leftleftrotate, leftrightrotate, ... ...
            z = z->ancestor;
        }    
    }
    return isDeleted;
}

void avlUpdate(Node *node, const int& value){
    Update(node, value);
}

void avlDemo(){
    char ch;
    int n;
    while(true){
        cin>>ch;
        if(ch == 'I' || ch =='i'){
            cin>>n;
            avlInsert(n);
            bfsPrinter();
        }else if(ch == 'D' || ch == 'd'){
            cin>>n;
            if(avlDelete(n) ){
                cout<<n<<" deleted\n";
                bfsPrinter();
            }else{
                cout<<n<<" is not deleted\n";
            }
        }else if(ch == 's' || ch == 'S'){
            cin>>n;
            Node* node = avlSearch(n);
            if(node!=NULL){
                cout<<"Found!\n";
            }else{
                cout<<"Not found!\n";
            }
        }else if(ch =='p' || ch == 'P'){
            bfsPrinter();
        }else if(ch == 'u' || ch == 'U'){
            int m;
            cin>>n>>m;
            Node *node = avlSearch(n);
            if(node!=NULL){
                avlUpdate(node, m);
                cout<<"Node updated\n";
                bfsPrinter();
            }else{
                cout<<"Node not found, so cannot update\n";
            }
        }
        else if(ch =='X' || ch=='x'){ break;  }
    }
}

/********* AVL TREE END   ************/
int main(){
    avlDemo();
    myDfsDestructor(root);
    return 0;
}