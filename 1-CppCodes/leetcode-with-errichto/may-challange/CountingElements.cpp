#include <bits/stdc++.h>

using namespace std;



int a[1005];

int countElements(vector<int>& arr) {
    int n, m;
    int kount = 0;
    bool elementsOfA[1005] = {0};

    n = arr.size();
    for(int i=0; i<n; i++) {
        m = arr[i];
        elementsOfA[m] = true;
    }        

    for(int i=0; i<n; i++) {
        m = arr[i];
        m=m+1;
        if(elementsOfA[m]==true) {
            kount++;
        }
    }

    return kount;
}

int main() {
    bool elementsOfA[1005] = {0};
    int n, m;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>m;
        a[i] = m;
        elementsOfA[m] = true;
    }    

    int kount = 0;
    for(int i=0; i<n; i++) {
        m = a[i];
        m=m+1;
        if(elementsOfA[m]==true) {
            kount++;
        }
    }

    cout<<kount<<"\n";
    return 0;

}