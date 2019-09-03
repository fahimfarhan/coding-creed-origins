#include <bits/stdc++.h>
using namespace std;

#define N 16

string database[N*N];
string l1cache[N];
int l1count[N];
string l2cache[2*N];

int cost;

void constructor(){
    for(int i=0; i<N; i++){ l1cache[i]="";  l1count[i]=0; }
    for(int i=0; i<2*N; i++){   l2cache[i] = "";    }
    for(int i=0; i<N*N; i++){   cin>>database[i];   }

    // for(int i=0; i<N*N; i++){  cout<<i<<" "<<database[i]<<"\n";    }
}

void swapL1L2(const int& l1index,const int& l2index){
    swap(l1cache[l1index], l2cache[l2index]);
    l1count[l1index] = 0;
}



bool doesS1ContainS2(const string& s1, const string& s2){
    if (s1.find(s2) != std::string::npos) {
        return true;
    }return false;
}

int lookUpL1Cache(string t){
    for(int i=0; i<N; i++){ 
        cost++;
        if(doesS1ContainS2(l1cache[i], t)){ 
            l1count[i]++;
            cout<<"Found in L1: ";
            return i;
        }
    }
    return -1;
}

int lookUpL2Cache(string t){
    for(int i=0; i<2*N; i++){
        cost+=2;
        if(doesS1ContainS2(l2cache[i], t)){ 
            cout<<"Found in L2: ";
            return i;
        }
    }
    return -1;
}

int lookUpDatabase(string t){
    for(int i=0; i<N*N; i++){
        cost+=16;
        if(doesS1ContainS2(database[i], t)){ 
            cout<<"Found in DB: ";
            return i;
        }
    }
    return -1;
}

int LRUreplacementPolicyFromL1ToL2(int l2Index){
    cost+=N;
    int minimus = INT_MAX;
    int l1Index;
    for(int i=0; i<N; i++){
        if(l1count[i]<minimus){
            minimus = l1count[i];
            l1Index = i;
        }
    }

    swapL1L2(l1Index, l2Index);
    cost+=3;
    return l1Index;
}

int RandomReplacementPolicyFromDBtoL2cache(const int& dbIndex){
    int j = rand()%(2*N);
    l2cache[j] = database[dbIndex];
    cost+=16;
    return j;
}

string LookUp(string t){
    cost = 0;
    int i=0;
    i = lookUpL1Cache(t);
    if(i!=-1){  return l1cache[i];  }

    i = lookUpL2Cache(t);
    if(i!=-1){ // found!
        // 1. fetch it into l1
        int j = LRUreplacementPolicyFromL1ToL2(i);
        // 2. return 
        return l1cache[j];
    }

    i = lookUpDatabase(t);
    if(i!=-1){
        int j = RandomReplacementPolicyFromDBtoL2cache(i);
        int k = LRUreplacementPolicyFromL1ToL2(j);
        return l1cache[k];
    }

    return "ERROR 404 Not Found! "+t;

}

void printer(const string& t){
    cout<<LookUp(t)<<" "<<cost<<"\n";
}

void memoryPrinter(){
    cout<<"\n---------L1 cache----------\n";
    for(int i=0; i<N; i++){ cout<<l1cache[i]<<"-"<<l1count[i]<<" | ";  }
    cout<<"\n";

    cout<<"\n---------L2cache----------\n";
    for(int i=0; i<2*N; i++){   cout<<l2cache[i]<<" | ";  }

}

int main(int argc, char const *argv[])
{
    /* code */
    constructor();
    printer("ricardo milos");
    printer("Ann");
    printer("Ann");
    printer("Ann");
    printer("des");
    printer("H");
    printer("opp");    
    printer("thr");    
    printer("imp");
    printer("una");
        memoryPrinter();
    printer("day");
    printer("his");
    printer("are");
    printer("unr");
    printer("ind");
    printer("fin");
    printer("rea");
    printer("san");
    printer("Par");
    memoryPrinter();
cout<<"------------------round 2----------------\n";
    printer("Ann");
    printer("Ann");
    printer("Ann");
    printer("des");
    printer("H");
    printer("opp");    
    printer("thr");    
    printer("imp");
    printer("una");
    printer("day");
    printer("his");
    printer("are");
    printer("unr");
    printer("ind");
    printer("fin");
    printer("rea");
    printer("san");
    printer("Par");
memoryPrinter();
    return 0;
}
