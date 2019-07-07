#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int T,Q,X,y,z;
set<int> s;
vector<int> temp;
        

int pc[128+1];
int Xor[128+1][128+1];

void preprocess(){
    int m = 0;
    for(int i=0; i<129; i++){
        m = __builtin_popcount(i);
        if( (m%2) == 0){    pc[i] = 0; }
        else{   pc[i] = 1;  }
    }

    for(int i=0; i<129; i++){
        for(int j=0; j<129; j++){
            Xor[i][j] = (i^j);
        }
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

    preprocess();

    cin>>T;
    while(T--){

        if(!s.empty()){ s.clear();  }
        if(!temp.empty()){ temp.clear();  }
        
        int a[2] = {0};
        cin>>Q;
        while(Q--){
            cin>>X;
            for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
                y = (*it);
                if(y!=X){  
                    z = Xor[X][y];
                    temp.push_back(z);
                    z = pc[z];
                    a[z]++;
                }
                
            }

            for(int i=0; i<temp.size(); i++){   s.insert(temp[i]);  }
            temp.clear();

            s.insert(X);
            z = pc[X];
            a[z]++;

            cout<<a[0]<<" "<<a[1]<<"\n";
        }

    }
    return 0;
}