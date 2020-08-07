#include <bits/stdc++.h>
#define N 8
#define DATABASE_SIZE 256
#define CACHEL2_SIZE N*2
using namespace std;

string database[DATABASE_SIZE];
string cacheL2[CACHEL2_SIZE];
string cacheL1[N];
int cacheL1count[N];

int isCacheL2Filled=0;
int cost=0;

void takeInput(){
    for(int i=0; i<DATABASE_SIZE; i++){    cin>>database[i];   }
    for(int i=0; i<CACHEL2_SIZE; i++){  cacheL2[i] = "";    }
    for(int i=0; i<N; i++){ cacheL1[i] = ""; cacheL1count[i]=0;    }
}

bool doesS1ContainS2(const string& s1, const string& s2){
    if (s1.find(s2) != std::string::npos) {
        return true;
    }return false;
}

int lookupDatabase(const string& t){
    for(int i=0; i<DATABASE_SIZE; i++){
        cost+=16;
        if(doesS1ContainS2(database[i], t)){    return i; }
    }
    return -1;
}

int lookupCacheL2(const string& t){
    for(int i=0; i<CACHEL2_SIZE; i++){
        cost+=4;
        if(doesS1ContainS2(cacheL2[i], t)){ return i;   }
    }return -1;
}

int lookupCacheL1(const string& t){
    for(int i=0; i<N; i++){
        if(doesS1ContainS2(cacheL1[i], t)){ return i;   }
    }
    return -1;
}

int LRUreplacementPolicy(const int& c2Index){
    
}

int randomReplacementPolicy(const int& dbIndex){
    int r = rand()%CACHEL2_SIZE;
    cacheL2[r] = database[dbIndex];
    return r;
}

int sequencialReplacementPolicy(const int& dbIndex){
    if(isCacheL2Filled>=CACHEL2_SIZE){   return -1; }
    cacheL2[isCacheL2Filled] = database[dbIndex];
    int ret = isCacheL2Filled;
    isCacheL2Filled++;
    return ret;
}

void myswap(string& s, string& t ){
    string temp = s;
    s = t;
    t = temp;

}

string LookUp(const string& t){
    cost=0;
    int index=0;
    index = lookupCacheL2(t);
    if(index!=-1){    return cacheL2[index];    }

    index = lookupDatabase(t);
    if(index!=-1){
        if(isCacheL2Filled<CACHEL2_SIZE){
            int retIndex = sequencialReplacementPolicy(index);
            return cacheL2[retIndex];
        }else{
            int retIndex = randomReplacementPolicy(index);
            return cacheL2[retIndex];
        }
    }
    return "Error 404: Not Found!";
}

void printer(const string& t){
    cout<<LookUp(t)<<" "<<cost<<"\n";
}

void memoryPrinter(){
    cout<<"\n---------cacheL2----------\n";
    for(int i=0; i<CACHEL2_SIZE; i++){   cout<<cacheL2[i]<<" | ";  }

}

int main(){
    takeInput();
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
        cout<<"\n";
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
cout<<"\n------------------round 2----------------\n";
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
    return 0;
}