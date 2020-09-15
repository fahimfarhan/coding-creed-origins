/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define PI 2*acos(0)
#define ll long long int
ll MOD = 1e9+7;
vector<int> *g;
bool *isvisited;

ll conquer(ll *a,ll *swapSpace, int l, int r) {
    ll swapKount = 0;
    int size = r - l + 1;
    int mid = (l + r) / 2;
    int i1 = l; int j1 = mid+1; int k1 = 0;
    swapKount = 0;
    while( (i1 <= mid) && (j1 <= r) ){
        if(a[i1] < a[j1]) {
            swapSpace[k1] = a[i1];
            i1++; 
        }else{
            swapSpace[k1] = a[j1];
            // swapKount = swapKount + (j1 - k1);
            swapKount = swapKount + ((mid - i1) + 1);
            j1++; 
        }
        k1++;
    }
    while(i1<=mid) {
        swapSpace[k1] = a[i1]; i1++; k1++; 
    }

    while(j1<=r) {
        swapSpace[k1] = a[j1]; j1++; k1++;
    }

    for(int i=l; i<=r; i++) {
        a[i] = swapSpace[i - l];
    }
    return swapKount;
}

ll divide(ll *array, ll * swapSpace, int l, int r) {
    if(r<l) {   return 0; }
    if(r-l+1 == 1) {    return 0; }
    int mid = (l+r) / 2;
    ll kount1 = divide(array, swapSpace,  l, mid);
    ll kount2 = divide(array, swapSpace, mid+1, r);
    ll kount3 = conquer(array, swapSpace, l, r);
    ll kount = kount1 + kount2 + kount3;
    return kount;
}

ll mergeSort(ll *inputArray, ll *swapSpace, int l, int r) {
    return divide(inputArray, swapSpace, l, r);
}


int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, *a, *b;
    ll one = 1;
    while(true) {
        cin>>N;
        if(N==0) {  break;  }
        a = new ll[N+1];
        b = new ll[N+1];
        for(int i=0; i<N; i++) {    cin>>a[i];  }

        ll player = mergeSort(a, b, 0, N-1);

        if( (player & one) == one) {
            cout<<"Marcelo\n";
        }else{
            cout<<"Carlos\n";
        }    

        delete[] b;
        delete[] a;
    }
    return 0;
}
