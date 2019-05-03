#include <bits/stdc++.h>

using namespace std;

int bt[1000];

int binaryTree(int a){
    int j=1;
    while(true){
        if(bt[j]==a){   return j;  }
        if(a<bt[j]){    j=(j<<1);  }
        else{   j=(j<<1)|1;        }
        if(bt[j]==-1){  return -1; } 
    }
}

int main()
{

    for(int i=0; i<1000; i++){  bt[i]=-1;}
    int n,q;
    cin>>n>>q;

    int a,j;
    for(int i=0; i<n; i++){
        cin>>a;
        j=1;
        //if(bt[j]==-1){  bt[j]=a;    }
        //else{
            while(true){
                if(bt[j]==-1){  bt[j]=a; break;    }
                if(a<bt[j]){    j=j<<1;     }
                else{           j=j<<1|1;   }
            }
            
        //}
    }

    while(q--){
        cin>>a;
        cout<<binaryTree(a)<<"\n";
    }

    return 0;
}