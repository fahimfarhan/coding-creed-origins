#include <bits/stdc++.h>

using namespace std;

int bubbleSort(vector<int>& v) {
    int swapKount = 0;
    for(int i=1; i<v.size(); i++) {
        for(int j=1; j<v.size(); j++) {
            if(v[j-1]>v[j]) {
                swap(v[j-1], v[j]);
                swapKount++;
            }
        }
    }
    return swapKount;
}


int main() {

    vector<int> v;
    int T, L, swapKount = 0;
    cin>>T;
    while(T--) {
        cin>>L;
        v.resize(L);
        for(int i=0; i<L; i++) {
            cin>>v[i];
        }

        swapKount = bubbleSort(v);

        // cout<<swapKount<<"\n";
        cout<<"Optimal train swapping takes "<<swapKount<<" swaps.\n";
        
        v.clear();
    }

    return 0;
}