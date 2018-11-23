

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
for(int i=0; i<1000; i++){
        for(int j = 0; i<100; j++){}
    }

 
	int n,q, **a;
    cin>>n>>q;

    for(int i=0; i<1000; i++){
        for(int j = 0; i<100; j++){}
    }


    a = new int*[n];
    for(int i=0; i<n; i++){   a[i] = new int[n];    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = 0;
        }
    }
	int N = n*n;
    if(N&1 == 1){   N = (int)N/2 + 1;   }// N = odd
    else{   N = N/2;    }
    int M = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(M>N){    break;  }
            if( ((i+j)%2 == 0)  ){ a[i][j]=M; M++; }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 0){   a[i][j] = M; M++;   }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<1000; i++){
        for(int j = 0; i<100; j++){}
    }


    while(q--){
        int Y,X;
        cin>>X>>Y;
        X--; Y--;
        cout<<a[X][Y]<<"\n";
    }

    for(int i=0; i<1000; i++){
        for(int j = 0; i<100; j++){}
    }


   
    return 0;
}

