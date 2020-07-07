/**
 * HAD TO ABORT CZ FURTHER CODING REQUIRES ME TO IMPLEMENT A BASIC BST FIRST
 * NOW I HAVE SOME COMPATIBITY ISSUES
 * I'LL PROBABLY SCREW THINGS UP
 * SO LET THIS VERSION STAY THE WAY IT IS
 * :)
*/
#include <bits/stdc++.h>

using namespace std;

class Node{
private:

public:
    int n, depth;
    Node *left, *right;
    Node(int n = 0){    this->n = n; left = NULL; right = NULL;   }
    
    ~Node(){    
        if(left!=NULL) delete left; 
        if(right!=NULL) delete right;
    }
};

Node *root;

// call it like this: myTreeDestructor(root);
// unfortunately doesnot work, I get segmentation fault :'(
// todo: use gdb/ some linux cpp debugger to find what is wrong     
void myTreeDestructor(Node *node){ 

    if(node == NULL){   return; }
    myTreeDestructor((node->left));
    myTreeDestructor((node->right));
    try{
        if(node!=NULL) {
            cout<<"Destroying node = "<<(node->n)<<"\n";
            node->left = NULL;
            node->right = NULL;
            delete[] node;
        }
    }catch(exception &x){
        cout<<"Exception : "<<x.what();
    }
}

void insert(const int& m){
    if(root == NULL){
        root = new Node(m);
    }else{
        Node *prev = NULL;
        Node *curr = root;
        while(curr != NULL){
            prev = curr;
            if(m <= (curr->n) ){
                curr = curr->left;
            }else{  
                curr = curr->right; 
            }
            // if(curr == NULL){   break;  }
        }

        curr = new Node(m);
        if(m <= (prev->n)){
            prev->left = curr;
        }else{
            prev->right = curr;
        }

        
        // curr = NULL;
        // prev = NULL;
    }
}

int getHeight(Node *node){
    if(node == NULL){   return 0;   }
    int left = getHeight( (node->left) );
    int right = getHeight( (node->right) );
    return (1 + max(left, right));
}

void printer(Node* node){
    if(node == NULL){         cout<<" "<<" X "<<"\n";  return; }
    else{
        cout<<node->n<<" ";
        printer((node->left));
        printer((node->right));
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

//     A                               B
//    / \        rr / cwr             / \
//   B   C    ---------------->      D   A
//  / \       <----------------         / \ 
// D   E         lr / acwr             E   C 

Node* leftRotate(Node *node) // clockWiseRotate
{
    Node *a, *b, *c, *d, *e, *newRoot;
    // 1. track the nodes using pointers
    b = node;
    d = b->left; a = b->right;

    e = a->left; c = a->right;
    // 2. create new links according to the diagram
    a->left = b;
    b->right = e;

    // 3. make root = A
    newRoot = a;
    // 4. make these temp pointers = NULL
    a = NULL; b = NULL; c = NULL; d = NULL; e = NULL;
    return newRoot;
}

Node* rightRotate(Node *node) // antiClockWiseRotate
{
    Node *a, *b, *c, *d, *e, *newRoot;
    // 1. track the nodes using pointers
    a = node;
    b = a->left;  c = a->right;
    d = b->left;  e = b->right;
    // 2. create new links according to the diagram
    a->left = e;
    b->right = a;
    // 3. new root
    newRoot = b;
    // 4. make these temp pointers = NULL
    a = NULL; b = NULL; c = NULL; d = NULL; e = NULL;
    return newRoot;
}
// rule of thumb,
// rotate Child to 1st direction, then rotate Parent to 2nd direction
Node* leftLeftRotate(Node *node){
    Node *result;
    node->left = leftRotate((node->left));
    result = leftRotate(node);
    return result;
}

Node* leftRightRotate(Node *node){
    Node *result;
    node->left = leftRotate((node->left));
    result = rightRotate(node);
    return result;
}

Node* rightRightRotate(Node *node){
    Node *result;
    node->right = rightRotate((node->right));
    result = rightRotate(node);
    return result;
}

Node* rightLeftRotate(Node *node){
    Node *result;
    node->right = rightRotate((node->right));
    result = leftRotate(node);
    return result;
}

Node* balance(Node *node){
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

void AVL(const int& x){
    insert(x);
    root = balance(root);
    cout<<"new root = "<<root->n<<"\n";
    bfsPrinter();
}


int main(){
    root = NULL;
    int x;

    while(true){
        cin>>x;
        if(x == 0){ break;  }
        AVL(x);
        // cout<<"\n";
        // cout<<"height = "<<getHeight(root)<<"\n";
    }
    myTreeDestructor(root);
    return 0;
}