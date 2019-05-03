#include <bits/stdc++.h>

using namespace std;

int invCount;

vector<int> mergeSort(vector<int> a){
    int len = a.size();
    if(len==1){ return a; }
    vector<int> a1, a2;

    int mid = len/2;
    for(int i=0; i<mid; i++){   a1.push_back(a[i]); }
    for(int i=mid; i<len; i++){   a2.push_back(a[i]); }

    vector<int> b1,b2;
    b1 = mergeSort(a1);
    b2 = mergeSort(a2);

    vector<int> b;
    int i=0,j=0,k=0;
    int len1=b1.size();int len2 = b2.size();
    bool bl=true;
    while(bl){
        if( (i==len1) || (j==len2) ){ bl=false;  break; }
        if(b1[i]<=b2[j]){
            b.push_back(b1[i]);
            i++;
        }else{
            b.push_back(b2[j]);
            j++;
            invCount++;
        }
    }

    while(i<len1){  b.push_back(b1[i]); i++;  }
    while(j<len2){  b.push_back(b2[j]); j++;  }

    return b;
}

int main()
{
    invCount = 0;
    vector<int> v, b;
    int n,m;
    cin>>n;
    for(int i=0; i<n; i++){ cin>>m; v.push_back(m); }

    b = mergeSort(v);
    for(int i=0; i<b.size(); i++){  cout<<b[i]<<" ";    }
    cout<<"\n";

    cout<<"Inv Count = "<<invCount<<"\n";
    return 0;
}
