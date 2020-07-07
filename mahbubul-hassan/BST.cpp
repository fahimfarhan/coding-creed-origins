/* recently I had some confusion... sso practicing basic stuffs... refreshing my memories...
*/

#include <bits/stdc++.h>

using namespace std;


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

void basicBstDemo(){
char ch;
    int n;
    while(true){
        cin>>ch;
        if(ch == 'I' || ch =='i'){
            cin>>n;
            Insert(n);
            bfsPrinter();
        }else if(ch == 'D' || ch == 'd'){
            cin>>n;
            if(Delete(Search(n)) ){
                cout<<n<<" deleted\n";
                bfsPrinter();
            }else{
                cout<<n<<" is not deleted\n";
            }
        }else if(ch == 's' || ch == 'S'){
            cin>>n;
            Node* node = Search(n);
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
            Node *node = Search(n);
            if(node!=NULL){
                Update(node, m);
                cout<<"Node updated\n";
                bfsPrinter();
            }else{
                cout<<"Node not found, so cannot update\n";
            }
        }
        else if(ch =='X' || ch=='x'){ break;  }
    }
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

int main(){
    basicBstDemo();
    myDfsDestructor(root);
    return 0;
}