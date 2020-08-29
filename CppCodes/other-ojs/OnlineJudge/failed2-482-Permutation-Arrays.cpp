#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {

    int T;
    vector<int> v;
    char ch;

    cin>>T;
    while(T--) {
        while(true) {
            int n;
            cin>>n;
            n = n-1;
            v.push_back(n);
            char ch;
            ch = getchar();
            if(ch == '\n') {    break;  }
        }

        float *f = new float[v.size() + 1];

        for(int i=0; i<v.size(); i++) {    cin>>f[v[i]];   }

        for(int i=0; i<v.size(); i++) {    cout<<f[i]<<"\n";   }

        delete[] f;
        v.clear();

    }
}