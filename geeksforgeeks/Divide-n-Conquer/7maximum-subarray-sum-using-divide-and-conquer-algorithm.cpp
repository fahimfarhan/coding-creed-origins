#include <bits/stdc++.h>

using namespace std;

int maxSum(int *a, int l, int r){
    int len = r-l+1;
    if(l>r){    return 0; }
    if(len == 1){   return a[l]; }
    
    int mid = (l+r)>>1;

    int maximusL = maxSum(a,l,mid);
    int maximusR = maxSum(a,mid+1,r);

    int temp=0,tempL=INT_MIN ,tempR=INT_MIN;

    for(int i=mid; i>=l; i--){
        temp+=a[i];
        tempL = max(temp,tempL);
    }

    temp=0;
    for(int i=mid+1; i<r; i++){
        temp+=a[i];
        tempR = max(temp,tempR);
    }
    int maximusM = tempL+tempR;

    int maximus = max(maximusL, maximusR);
    maximus = max(maximus,maximusM);

    return maximus;
}


int main(){
    int input[] = {2, 3, 4, 5, 7}; 
   int n = sizeof(input)/sizeof(input[0]); 
    // len =9 (0-8)

    cout<<maxSum(input,0,n-1)<<"\n";

    return 0;
}