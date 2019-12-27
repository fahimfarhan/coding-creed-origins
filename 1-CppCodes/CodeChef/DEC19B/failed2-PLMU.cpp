#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

int main(){
    
    int T;
    ll N, temp, *a;
    ll kount = 0;

    cin>>T;
    while(T--){
        cin>>N;
        a = new ll[N+1];
        for(int i=0; i<N; i++){
            cin>>a[i];
        }

        sort(a,a+N);
        kount = 0;
        for(int i=0; i<N; i++){
            temp = a[i];
            for(int j=i+1; j<N; j++){
                if(a[j]<=2*temp){
                    if( (temp+a[j]) == (temp*a[j]) ){
                        kount++;
                    }
                }else{
                    break;
                }
            }
        }

        cout<<kount<<"\n";

        delete[] a;
    }
    return 0;
}