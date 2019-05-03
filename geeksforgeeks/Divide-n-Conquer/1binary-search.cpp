#include<bits/stdc++.h>

using namespace std;

int givenSortedArray[10]={0,1,2,3,4,5,6,7,8,9};

int binarySearch(int a){
    int m,l,r; l=0; r=9;
    int count=ceil(log2(10));
    while(true){
        count--;
        m=(l+r);
        m=m>>1;
        if(givenSortedArray[m]==a){ return m; }
        else if(givenSortedArray[m]<a){ l = m; }
        else if(givenSortedArray[m]>a){ r=m; }

        if(r<=l){ break; }
        if(count==0){   break; }
    }
    return -1;
}

int main(){
    
    int q,a;
    cin>>q;
    while(q--){
        cin>>a;
        cout<<binarySearch(a)<<"\n";    
    }


    return 0;
}