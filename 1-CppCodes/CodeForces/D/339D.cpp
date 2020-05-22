#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define MY_OR true 
#define MY_XOR false
#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int v, n, m;
int *st;

void printer(){
    int nextNewLinePos = 2, stop = 2*n;
    for(int i=1; i<stop; i++){
        if(i==nextNewLinePos){  cout<<"\n"; nextNewLinePos=nextNewLinePos<<1;   }
        cout<<st[i]<<" ";
    }cout<<"\n";
}

int f(bool toogle, int const& a,int const& b ){
    if(toogle==MY_OR){  return (a|b); }
    else{   return (a^b);   }
}

void build(){
    int l, r;
    bool toogle=MY_OR;
    int nextTooglePoint = (n>>1);
    for(int i=n-1; i>0; i--){
        l = i<<1 ; r = l|1  ;
        l = st[l]; r = st[r];
        st[i] = f(toogle, l,r);

        if(i==nextTooglePoint){
            toogle = (!toogle);
            nextTooglePoint=(nextTooglePoint>>1);
        }

    }
}

void recursiveUpdate(bool toogle, int pos){
    if(pos == 0){   return; }
    bool nextToogle = !toogle;
    int curr,l, r;
    curr = pos;
    l = curr<<1; r = l|1;

    if(toogle == MY_OR){  st[curr] = (st[l]|st[r]);   }
    else{   st[curr] = (st[l]^st[r]);   }
    if(curr!=1){    
        int parent=(curr>>1);
        recursiveUpdate(nextToogle, parent);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int inputSize = 1<<n;
    int stSize = inputSize<<1;
    n = inputSize;

    st = new int[stSize+1];

    for(int i=0; i<=stSize; i++){ st[i] = 0;   }
    for(int i=n; i<stSize; i++){    cin>>st[i]; }
    build();
    //printer();

    int p,b, parent;
    for(int i=0; i<m; i++){
        cin>>p>>b;
        // update pos
        st[n+p-1] = b;
        // recursively update
        parent = (n+p-1)>>1;
        recursiveUpdate(MY_OR, parent);
        v = st[1];
        cout<<v<<"\n";        
    }
    if(!st)delete[] st;
    return 0;
}
