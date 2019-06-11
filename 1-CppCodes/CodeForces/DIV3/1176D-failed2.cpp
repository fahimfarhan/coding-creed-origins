#include <bits/stdc++.h>

using namespace std;

#define N 3000000

bool isprime[N];
int biggestDivisor[N];
int cnt[N];
vector<int> v, res;

void preprocess_and_seive(){
    for(int i=0; i<N; i++){ isprime[i] = true; biggestDivisor[i] = 0; cnt[i]=0; }
    
    isprime[0]=false; 
    isprime[1]=false;
    isprime[2] = true;

    for(int j=2; j<N; j+=2){
        if(j!=2){
            isprime[j] = false;
            biggestDivisor[j] = max(biggestDivisor[j], 2);
            biggestDivisor[j] = max(biggestDivisor[j], j/2);
            
        }
    }

    for(int i=3; i<N; i+=2){
        for(int j=i; j<N; j+=i){
            if(j!=i){
                isprime[j] = false;
                biggestDivisor[j] = max(biggestDivisor[j], i);
                biggestDivisor[j] = max(biggestDivisor[j], j/i);
                
            }
        }
    }

    for(int i=0; i<N; i++){
        if(isprime[i]) v.push_back(i);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess_and_seive();

    int n,x,y;
    cin>>n;
    n = n<<1;

    for(int i=0; i<n; i++){
        cin>>x;
        cnt[x]++;
    }

    for(int i=N-1; i>=0; i--){
        if(cnt[i]>0){
            if(isprime[i]){
                x = v[i];
                cnt[x]--;
                cnt[i]--;
                res.push_back(i);
            }else{
                x = biggestDivisor[i];
                cnt[x]--;
                cnt[i]--;
                res.push_back(i);
            }
        }
    }

    int len = res.size();
    for(int i=0;i<len; i++){
        cout<<res[i]<<" ";
    }cout<<"\n";

    for(int i=0; i<10; i++){    cerr<<v[i]<<" ";    }cout<<"\n";


    return 0;
}