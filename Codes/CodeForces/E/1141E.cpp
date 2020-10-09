#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define ll long long int

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll H, *A;int n;ll sum=0;ll maximus = 0;
    cin>>H>>n;
    A = new ll[n+1];
    for(int i=0; i<n; i++){
        cin>>A[i];
        sum = sum - A[i];
        maximus = max(maximus, sum);
        if(H-maximus<=0){
            cout<<(i+1)<<"\n";
            return 0;
        }
    }
    if(sum<=0){     cout<<"-1\n";   }
    else{
        ll count = (H-maximus)/sum;
        H=H-sum*count;
        count = count*n;
        int i=0;
        while(true){
            H = H+A[i%n];
            count++; i++;
            if(H<=0){
                cout<<count<<"\n";
                break;
            }
        }
    }
    return 0;
}
