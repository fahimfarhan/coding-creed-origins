#include <bits/stdc++.h>

using namespace std;

void init();
void permutation(int at, int n);

int used[20], number[20];

void init(){
    for(int i=0; i<20; i++) used[i]=0;
}

void permutation(int at, int n){
    if(at == n+1){
        for(int i=1; i<=n; i++){
            printf("%d", number[i]);
        }
        printf("\n");
        return;
    }

    for(int i=01; i<=n; i++){
        used[i]=1;
        number[at]=i;
        permutation(at+1,n);
        used[i]=0;
    }
}

int main()
{
    init();
    permutation(1,4);
    return 0;
}