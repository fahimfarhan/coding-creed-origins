#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

#define NUM_OF_BITS 4
// int n,m;
vector<int> *g;
bool *isvisited;

int N,Q, *A;
int **cf;

void preprocessing(){
    for(int i=0; i<NUM_OF_BITS; i++){   
        for(int j=0; j<=N; j++){    cf[i][j]=0;     }
    }

    for(int i=0; i<NUM_OF_BITS; i++){
        int k=1;
        k=k<<i;
        
        int *b;
        b = new int[N+1];
        b[0] = 0;

        for(int j=1; j<=N; j++){
            b[j] = A[j]&k;
        }

        for(int j=1; j<=N; j++){   cf[i][j] = cf[i][j-1]+(b[j]>>i);     }

        if(!b)delete[] b;
    }
}

void printer(){
    for(int i=0; i<NUM_OF_BITS; i++){
        for(int j=0; j<=N; j++){
            cout<<cf[i][j]<<" ";
        }cout<<"\n";
    }
}

int queryMinimus(int l,int r){ 
    int ret=0;
    int *x; x = new int[NUM_OF_BITS+1]; 
    int n = r-l+1;
        int p=0;
    for(int i=0; i<NUM_OF_BITS; i++){
        p = cf[i][r]-cf[i][l-1];
        if(p>=(n-p)){
            x[i] = 1; 
        }else{
            x[i]=0;
        }
    }

    for(int i=0; i<NUM_OF_BITS; i++){
        ret=ret|(x[i]<<i);
    }

    delete[] x;
    return ret;  
}

int queryMaximus(int l, int r){ 
    int ret=0;
    int *x; x = new int[NUM_OF_BITS+1]; 
    int n = r-l+1;
        int p=0;
    for(int i=0; i<NUM_OF_BITS; i++){
        p = cf[i][r]-cf[i][l-1];
        if(p>=(n-p)){
            x[i] = 0; 
        }else{
            x[i]=1;
        }
    }

    for(int i=0; i<NUM_OF_BITS; i++){
        ret=ret|(x[i]<<i);
    }

    delete[] x;
    return ret;  
}

vector<int> v;

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
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        A = new int[N+1];
        cf = new int*[NUM_OF_BITS];
        for(int i=0; i<NUM_OF_BITS; i++){    cf[i]=new int[N+1];    }
        
        A[0]=0;

        for(int i=1; i<=N; i++){    cin>>A[i];    }

        preprocessing();
        //printer();
        int L,R,X;
        L=1; R=N;
        //X=queryMaximus(L,R);
        //    cout<<X<<"\n";
            X=queryMinimus(L,R);
            // cout<<X<<"\n";
        int sum=0; 
        int temp=0;
        for(int i=1; i<=N; i++){    temp=(A[i]^X);  sum=sum+temp;    }
        v.push_back(sum);
        //cout<<sum<<"\n";
        
        for(int i=0; i<NUM_OF_BITS; i++){   delete[] cf[i]; }
        delete[] cf;
        if(!A)delete[] A;
        
    }

    for(int i=0; i<v.size(); i++){  cout<<v[i]<<"\n";   }
    return 0;
}
