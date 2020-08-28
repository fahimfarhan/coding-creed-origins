#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <exception>
#include <ios>
#include <iostream>
#include <utility>

using namespace std;

#define ORDER 4

class Node{
public:
    vector<int> numbers;
    vector<Node *> descendants;
    Node *ancestor;

    Node(Node* ancestor = nullptr) {
        this->ancestor = ancestor;
        descendants.resize(ORDER+1);
        for(int i=0; i<descendants.size(); i++) {
            descendants[i] = nullptr;
        }
    }

    void destroyNode() {
        try {
            ancestor = nullptr;
            for(int i=0; i<descendants.size(); i++) {
                descendants[i]->destroyNode();
                delete[] descendants[i];
            }
        } catch (exception &x) {
            cerr<<"Exception in destroyNode() -> "<<x.what()<<"\n";
        }
    }

    ~Node() {/* destroy node */}
};

class BPlusTree{
public:
    Node *root;

    pair<Node*, int> search(Node *node, const int& N){
        pair<Node*, bool> p(node, -1);

        for(int i=0; i<node->numbers.size(); i++){
            if(node->numbers[i] == N) {
                p.second = i;
                return p;
            }
        } 
        // not found
        if(N < node->numbers[0]) {
            if(node->descendants[0] == nullptr) {
                node->descendants[0] = new Node();
            }
            p.first = node->descendants[0];
            p.second = -1;
            return p;

        }else if( N > node->numbers[node->numbers.size() - 1] ) {
            if(node->descendants[ORDER] == nullptr) {
                node->descendants[ORDER] = new Node();
            }
            p.first = node->descendants[0];
            p.second = -1;
            return p;
        
        }else{

        }

        return p;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}