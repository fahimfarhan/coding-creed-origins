#include <bits/stdc++.h>

using namespace std;

string s = "azbxcydwetfqgeh";
int n;
bool *isFree;

void recursion(const string& prefix, const int& k){
    // base case
    if(k==0){   cout<<prefix<<"\n";   return; }
    // recursion
    int k1 = k-1;
    for(int i=0; i<n; i++){
        if(isFree[i]){
            isFree[i] = false;
            string nextprefix = "";
            nextprefix = prefix+s[i];
            recursion(nextprefix, k1);
            isFree[i] = true;
        }
    }
}

int main()
{
    n = s.size();
    int k=4;
    isFree = new bool[n+1];
    for(int i=0; i<n; i++){ isFree[i] = true;   }

    recursion("", k);
    
    delete[] isFree;
    return 0;
}