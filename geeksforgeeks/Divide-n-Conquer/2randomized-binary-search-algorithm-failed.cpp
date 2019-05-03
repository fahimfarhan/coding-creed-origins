#include<bits/stdc++.h>

using namespace std;

int a[10] = {10,11,22,33,44,55,66,77,88,99};

int getRand(int l, int r){
    int ret = rand();
    ret = l+ret%(r-l+1);
    return ret;
}

int randomizedBinarySearch(int l1, int r1,int x){
    int l=l1, r=r1;
    while(r>=l){
        int t = getRand(l,r);
        if(a[t]==x){    return t; }
        else if(a[t]<x){ r = t-1; }
        else if(a[t]>x){ l=t+1; }
    }
    return -1;
}

int main()
{

    cout<<randomizedBinarySearch(0,9,10)<<"\n";
    cout<<randomizedBinarySearch(0,9,33)<<"\n";
    cout<<randomizedBinarySearch(0,9,3)<<"\n";

    return 0;
}