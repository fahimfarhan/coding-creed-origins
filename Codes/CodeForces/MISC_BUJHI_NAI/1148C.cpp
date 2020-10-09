#include <bits/stdc++.h>

using namespace std;

int n,m,*a, *pos;
vector< pair<int, int> > v;

void myswap(int i, int j){
    v.push_back({i,j});
    swap(pos[a[i]], pos[a[j]]);
    swap(a[i], a[j]);
}

bool ok(int a, int b){
    return ( (abs(a-b)) >= (n>>1) );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin>>n;
    a = new int[n+1];
    pos = new int[n+1];
    for(int i=0; i<=n; i++){ a[i]=0; pos[i] = 0;  }

    for(int i=1; i<=n; i++){
        cin>>a[i]; 
        pos[a[i]]=i;
    }
    m = n>>1;

    int now, next;
    for(int i=1; i<=m; i++){
        now = i; next = pos[i];
        if(now == next){    continue; }
        else if(ok(now, next)){
            myswap(now, next);
        }else{
            if(ok(next, n)){
                myswap(next, n);
                myswap(now, n);
            }else{
                myswap(next, 1);
                myswap(1,n);
                myswap(now, n);
                myswap(1,next);
            }
        }
    }

    for(int i=m+1; i<=n; i++){
        now = i; next = pos[i];
        if(now != next){
            if(ok(now, next)){
                myswap(now, next);
            }else{
                if(ok(next, 1)){
                    myswap(1, next);
                    myswap(1,now);
                    myswap(1,next);
                }
            }
        }
    }

    m = v.size();
    cout<<m<<"\n";

    for(int i=0; i<m; i++){   cout<<v[i].first<<" "<<v[i].second<<"\n";   }

    delete[] a;
    delete[] pos;
    return 0;
}