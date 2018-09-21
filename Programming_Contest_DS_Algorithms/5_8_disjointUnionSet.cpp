#include <bits/stdc++.h>
using namespace std;

int p[10];

int find(int x){
    if(p[x]==x) return x;
    else {
        p[x] = find(p[x]);
        return p[x];
    }
    return 0;
}

void Union(const int& a,const int& b){
    //int x = find(b);
    p[find(b)] = find(a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<10; i++){    p[i]=i; }
    return 0;

}