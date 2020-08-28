/**
* @brief: this is a practive prototype. Probably it won't work. Don't use it somewhere in production.
*/

#include <bits/stdc++.h>
#include <exception>
#include <iostream>

using namespace std;

#define ORDER 4
#define MINIMUS_SIZE ORDER/2
#define MAXIMUS_SIZE 4

class Node {
public:
    vector<int> numbers;
    vector<Node*> nodePointers;
    Node *ancestor;

    Node(Node *ancestor = nullptr) {
        this->ancestor = ancestor;
    }

    ~Node() {
        try {
            ancestor = nullptr;

        } catch (exception &x) {
            cerr<<"Exception in ~Node-> "<<x.what()<<"\n";
        }
    }

    bool isLeaf() {
        for(int i=0; i<nodePointers.size(); i++) {
            if(nodePointers[i]!=nullptr) {  return false;   }
        }
        return true;
    }

    bool insert(int N) {
        if(numbers.size() == 0) {
            numbers.push_back(N);
            if(numbers.size() > MAXIMUS_SIZE) { return false; }
            else{   return true;    }
        }
        else if(N < numbers[0]){
            // insert in the nodePtr[0]
            
        }else if(N > numbers[numbers.size() - 1]) {
            // insert in nodePtr[order]
        }else{
            int j1 = 0;
            for(int i=1; i<numbers.size() ; i++) {
                if(numbers[i-1] < N && N < numbers[i]) {
                    // this is the one!
                    // insert in nodePtr[i]
                    j1 = i;
                    break;
                }
            }
            nodePointers[j1]->insert(N);
        }

        return true;
    }
};



class BPlusTree{
public:    
    Node *root;
    bool insert(const int& N) {
        if(root == nullptr) {
            root = new Node(nullptr);
        }
        return true; // todo: Fix it with help of search I guess
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}